#include "media.h"

media::media()
{

}

void media::setMediaData(mediaData md){
    mData = md;
    onMediaDataChange();
}

mediaData media::getMediaData(){
    return mData;
}

bool media::getAutoSize(){
    return autoSize;
}

void media::setBounds(QRect r){
    setBounds(r.x(), r.y(), r.width(), r.height());
}

void media::setMediaListener(mediaListener* ml){
    mListener = ml;
}
