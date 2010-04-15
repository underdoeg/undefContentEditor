#ifndef APILISTENER_H
#define APILISTENER_H
#include "dataStructs.h"

class apiListener{
public:
    virtual void onPageData(pageData pd){};
    virtual void onFieldData(fieldData pd){};
    virtual void onPagesList(QList<int> list){};
    virtual void onFieldSave(int id){};
    virtual void onPageSave(int id){};
    virtual void onFileUploadComplete(QString fileName){};
    virtual void onFileDownloadComplete(QString fileName){};
};

#endif // APILISTENER_H
