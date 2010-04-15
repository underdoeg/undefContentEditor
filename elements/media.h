#ifndef MEDIA_H
#define MEDIA_H

#include <QWidget>
#include "utils/api.h"

class mediaListener{
public:
    virtual void onMediaResize(int x, int y, int w, int h){};
};

class media: public dataStructHelper
{
public:
    explicit media();
    void setBounds(QRect r);
    virtual void setBounds(int x, int y, int w, int h)=0;
    virtual QRect getBounds()=0;
    void setMediaData(mediaData md);
    mediaData getMediaData();
    virtual void onMediaDataChange() = 0;
    virtual void showMenu()=0;
    void setMediaListener(mediaListener* ml);
    bool getAutoSize();
    virtual void onSave(){};
    virtual QString getMediaType()=0;

signals:

public slots:
protected:
    mediaData mData;
    bool autoSize;
    mediaListener* mListener;
};

#endif // MEDIA_H
