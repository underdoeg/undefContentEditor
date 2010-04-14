#ifndef MEDIA_H
#define MEDIA_H

#include <QWidget>
#include "utils/api.h"

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
    bool getAutoSize();
signals:

public slots:
protected:
    mediaData mData;
    bool autoSize;
};

#endif // MEDIA_H
