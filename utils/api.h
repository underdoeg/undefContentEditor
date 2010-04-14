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
    static ServerAPI* getSingleton();

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

private:
    static apiRequest* newRequest();
    static void removeRequest(apiRequest* r);
    static apiRequest* getRequestByID(int id);

    static Client* createRpcClient();
    static  QList<apiRequest*> requests;
    static ServerAPI* singleton;
    static QFtp ftp;
};

#endif // ServerAPI_H
