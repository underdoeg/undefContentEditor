#ifndef ServerAPI_H
#define ServerAPI_H

#include <QWidget>
#include <QMessageBox>
#include <QFtp>
#include "apiListener.h"
using namespace xmlrpc;

struct apiRequest{
    apiListener* listener;
    Client* client;
    int id;
};

struct ftpRequest{
    ftpRequest(){
        file = 0;
    }

    apiListener* listener;
    int id;
    QString fileName;
    QFile* file;
};

class ServerAPI : public QWidget
{
Q_OBJECT
public:
    explicit ServerAPI(QWidget *parent = 0);
    static void getPageIDs(apiListener* listener);
    static void getPageData(apiListener* listener, int id);
    static void getFieldData(apiListener* listener, int id);
    static void savePageData(apiListener* listener, pageData data);
    static void saveFieldData(apiListener* listener, fieldData data, dataStructHelper* dsh=0);
    static void downloadFile(apiListener* listener, QString fName);
    static void uploadFile(apiListener* listener, QString fName);
    static ServerAPI* getSingleton();
    static bool fileExists(QString fName);
    static void copyToTemp(QString path, QString target);
    static QString toTempPath(QString fName);

    static QString rpcHost;
    static QString rpcPath;
    static int rpcPort;
signals:

public slots:

private slots:
    void respondGetPageIDs( int requestId, QVariant value );
    void respondGetFieldData( int requestId, QVariant value );
    void respondSavePageData( int requestId, QVariant value );
    void respondSaveFieldData( int requestId, QVariant value );
    void respondGetPageData( int requestId, QVariant value );
    void processFault( int requestId, int errorCode, QString errorString );
    void updateDataTransferProgress(qint64 readBytes, qint64 totalBytes);
    void ftpCommandFinished(int commandId, bool error);

private:
    static apiRequest* newRequest();
    static void removeRequest(apiRequest* r);
    static apiRequest* getRequestByID(int id);
    static ftpRequest* createFtpRequest();
    static ftpRequest* getFtpRequestByID(int id);
    static void removeFtpRequest(ftpRequest* r);
    void setup();

    static Client* createRpcClient();
    static QList<apiRequest*> requests;
    static QList<ftpRequest*> ftpRequests;
    static ServerAPI* singleton;
    static QFtp* ftp;

    static QString ftpHost;
    static QString ftpUser;
    static QString ftpPass;
    static QString ftpPath;

    static QString tmpPath;
};

#endif // ServerAPI_H
