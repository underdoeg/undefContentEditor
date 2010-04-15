#include "api.h"

ServerAPI* ServerAPI::singleton = 0;
QList<apiRequest*> ServerAPI::requests;
QList<ftpRequest*> ServerAPI::ftpRequests;
QString ServerAPI::rpcHost = "127.0.0.1";
QString ServerAPI::rpcPath = "/contentEditor/server/xml_rpc";
QString ServerAPI::ftpHost = "ftp://"+ServerAPI::rpcHost;
QString ServerAPI::ftpUser = "phwhitfield";
QString ServerAPI::ftpPass = "roadshow";
QString ServerAPI::ftpPath = "Sites/contentEditor/server/app/webroot";
QString ServerAPI::tmpPath = "";
QFtp* ServerAPI::ftp = 0;
int ServerAPI::rpcPort = 80;

ServerAPI::ServerAPI(QWidget *parent):QWidget(parent)
{

}

/* //////////////////////////////////////////////////////////////////
 * XML-RPC PART
 */

void ServerAPI::setup(){
    ftp = new QFtp(this);
    ftp->setTransferMode(QFtp::Active);
    QUrl url(ftpHost);
    ftp->connectToHost(url.host(), url.port(21));
    ftp->login(ftpUser, ftpPass);
    ftp->cd(ftpPath);

    connect(ftp, SIGNAL(dataTransferProgress(qint64, qint64)), getSingleton(), SLOT(updateDataTransferProgress(qint64, qint64)));
    connect(ftp, SIGNAL(commandFinished(int, bool)), getSingleton(), SLOT(ftpCommandFinished(int, bool)));

    QDir tmpDir("/tmp");
    tmpDir.mkdir("undefContentEditor");
    tmpDir.setPath("/tmp/undefContentEditor");
    tmpDir.mkdir("img");
    tmpDir.mkdir("video");
    tmpDir.mkdir("data");
    tmpPath = tmpDir.absolutePath()+"/";
}

Client*  ServerAPI::createRpcClient(){
    Client* client = new Client(getSingleton());
    client->setHost(rpcHost, rpcPort, rpcPath);
    return client;
}

ServerAPI* ServerAPI::getSingleton(){
    if(singleton == 0){
        qDebug("//// CREATING NEW API SINGLETON");
        singleton = new ServerAPI;
        singleton->setup();
    }
    return singleton;
}

apiRequest* ServerAPI::newRequest(){
    apiRequest* r = new apiRequest;
    r->client = createRpcClient();
    requests << r;
    return r;
}

void ServerAPI::removeRequest(apiRequest* r){
    if(r == 0)
        return;
    delete r->client;
    requests.removeOne(r);
    delete r;
}

apiRequest* ServerAPI::getRequestByID(int id){
    for(int i=0;i<requests.size();i++){
        if(requests[i]->id == id)
            return requests[i];
    }
    qDebug("////---> ERROR!! DID NOT FIND A REQUEST FOR PROVIDED ID (ServerAPI::getRequestByID)");
    return 0;
}

void ServerAPI::getPageIDs(apiListener* listener){
    apiRequest* r = newRequest();
    r->listener = listener;
    connect( r->client, SIGNAL(done( int, QVariant )),
             getSingleton(), SLOT(respondGetPageIDs( int, QVariant )) );
    connect( r->client, SIGNAL(failed( int, int, QString )),
             getSingleton(), SLOT(processFault( int, int, QString )) );
    r->id = r->client->request("pages.list");
}

void ServerAPI::respondGetPageIDs( int requestId, QVariant value ){
    QList<int> ret;
    QVariantList li = value.toList();
    for(int i=0;i<li.size();i++){
        QMap<QString,QVariant>item = li[i].toMap();
        ret << item["Page"].toMap()["id"].toInt();
    }
    apiRequest* r = getRequestByID(requestId);
    r->listener->onPagesList(ret);
    removeRequest(r);
}

void ServerAPI::getPageData(apiListener* listener, int id){
    apiRequest* r = newRequest();
    r->listener = listener;
    connect( r->client, SIGNAL(done( int, QVariant )),
             getSingleton(), SLOT(respondGetPageData( int, QVariant )) );
    connect( r->client, SIGNAL(failed( int, int, QString )),
             getSingleton(), SLOT(processFault( int, int, QString )) );
    r->id = r->client->request("page.get", id);
}

void ServerAPI::respondGetPageData( int requestId, QVariant value ){  
    apiRequest* r = getRequestByID(requestId);
    r->listener->onPageData(toPageData(value));
    removeRequest(r);
}

void ServerAPI::getFieldData(apiListener* listener, int id){
    apiRequest* r = newRequest();
    r->listener = listener;
    connect( r->client, SIGNAL(done( int, QVariant )),
             getSingleton(), SLOT(respondGetFieldData( int, QVariant )) );
    connect( r->client, SIGNAL(failed( int, int, QString )),
             getSingleton(), SLOT(processFault( int, int, QString )) );
    r->id = r->client->request("field.get", id);
}

void ServerAPI::respondGetFieldData( int requestId, QVariant value ){
    apiRequest* r = getRequestByID(requestId);
    r->listener->onFieldData(toFieldData(value));
    removeRequest(r);
}

void ServerAPI::saveFieldData(apiListener* listener, fieldData data, dataStructHelper* dsh){
    apiRequest* r = newRequest();
    r->listener = listener;
    connect( r->client, SIGNAL(done( int, QVariant )),
             getSingleton(), SLOT(respondSaveFieldData( int, QVariant )) );
    connect( r->client, SIGNAL(failed( int, int, QString )),
             getSingleton(), SLOT(processFault( int, int, QString )) );
    r->id = r->client->request("field.write", toFieldVariant(data, dsh));
}

void ServerAPI::respondSaveFieldData( int requestId, QVariant value )
{
    apiRequest* r = getRequestByID(requestId);
    r->listener->onFieldSave(value.toInt());
    removeRequest(r);
}

void ServerAPI::savePageData(apiListener* listener, pageData data){
    apiRequest* r = newRequest();
    r->listener = listener;
    connect( r->client, SIGNAL(done( int, QVariant )),
             getSingleton(), SLOT(respondSavePageData( int, QVariant )) );
    connect( r->client, SIGNAL(failed( int, int, QString )),
             getSingleton(), SLOT(processFault( int, int, QString )) );
    r->id = r->client->request("page.write", toPageVariant(data));
}

void ServerAPI::respondSavePageData( int requestId, QVariant value )
{
    apiRequest* r = getRequestByID(requestId);
    r->listener->onPageSave(value.toInt());
    removeRequest(r);
}

void ServerAPI::processFault( int requestId, int errorCode, QString errorString )
{
    QMessageBox::warning(this, tr("Request failed"),
                         QString("XML-RPC request  failed.\n\nFault code: %1\n%2\n") \
                         .arg(errorCode).arg(errorString),
                         QMessageBox::Ok );
}

/* //////////////////////////////////////////////////////////////////
 * FTP PART
 */
ftpRequest* ServerAPI::createFtpRequest(){
    ftpRequest* req = new ftpRequest;
    ftpRequests.push_back(req);
    return req;
}

ftpRequest* ServerAPI::getFtpRequestByID(int id){
    for(int i=0;i<ftpRequests.size();i++){
        if(ftpRequests[i]->id == id)
            return ftpRequests[i];
    }
    //qDebug("////---> ERROR!! DID NOT FIND A REQUEST FOR PROVIDED ID (ServerAPI::getFtpRequestByID)");
    return 0;
}

void ServerAPI::removeFtpRequest(ftpRequest* r){
    if(r == 0)
        return;
    ftpRequests.removeOne(r);
    if(r->file != 0)
        delete r->file;
    delete r;
}

void ServerAPI::copyToTemp(QString path, QString target){
    QFile file(path);
    if(!file.copy(tmpPath+target))
            qDebug("COULD NOT COPY TO TEMPORARY PATH");
}

bool ServerAPI::fileExists(QString fName){
    QFile f(tmpPath+fName);
    return f.exists();
}

QString ServerAPI::toTempPath(QString fName){
    return tmpPath+fName;
}

void ServerAPI::downloadFile(apiListener* listener, QString fName){
    if(fileExists(fName))
        return;
    ftpRequest* f = createFtpRequest();
    f->listener = listener;
    f->fileName = fName;
    f->file = new QFile(tmpPath+fName); //TODO remove QFile after writing
    f->file->open(QIODevice::WriteOnly);
    f->id = ftp->get(fName, f->file);
}

void ServerAPI::uploadFile(apiListener* listener, QString fName){
    ftpRequest* f = createFtpRequest();
    f->listener = listener;
    f->fileName = fName;
    f->file = new QFile(tmpPath+fName);
    ftp->put(f->file, fName);
}

void ServerAPI::updateDataTransferProgress(qint64 readBytes, qint64 totalBytes){
     //qDebug() << ftp->currentId();
}

void ServerAPI::ftpCommandFinished(int commandId, bool error){
    ftpRequest* r = getFtpRequestByID(commandId);
    if(r == 0)
        return;
    if(ftp->currentCommand() == QFtp::Get)
        r->listener->onFileDownloadComplete(r->fileName);
    else if(ftp->currentCommand() == QFtp::Put)
        r->listener->onFileUploadComplete(r->fileName);
    removeFtpRequest(r);
}
