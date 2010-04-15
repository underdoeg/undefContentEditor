#include "image.h"

image::image(QWidget* parent):QLabel(parent)
{
    setStyleSheet("background-color: transparent");
    show();
    autoSize = false;
    pixmap = 0;
    mData.type = "image";
}

void image::setBounds(int x, int y, int w, int h){
    if(pixmap != 0){
        if(!pixmap->isNull()){
            h = w*pixmap->height()/pixmap->width();
            pixmapScaled = pixmap->scaled(QSize(w,h));
            setPixmap(pixmapScaled);
        }
    }
    setGeometry(x, y, w, h);
};
QRect image::getBounds(){
    return geometry();
};

void image::onMediaDataChange(){
    if(mData.content.toString().isEmpty())
        showMenu();
    else{
        loadImage(mData.content.toString());
    }
};

void image::showMenu(){
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), QDir::homePath(), tr("Image Files (*.png *.jpeg *.jpg)"));
    if(fileName.isEmpty())
        return;
    QFileInfo pathInfo( fileName );
    QDateTime dt = QDateTime::currentDateTime();
    QString newName = "img/"+dt.toString("yy_MM_dd-hh_mm_")+pathInfo.fileName();
    ServerAPI::copyToTemp(fileName, newName);
    loadImage(newName, true);
};

void image::loadImage(QString path, bool resize){
    if(pixmap != 0)
        delete pixmap;
    mData.content = path;
    if(!ServerAPI::fileExists(path)){
        ServerAPI::downloadFile(this, path);
        return;
    }
    pixmap = new QPixmap(ServerAPI::toTempPath(path));
    if(!pixmap->isNull() && resize){
        setBounds(0,0, pixmap->width(), pixmap->height());
        mListener->onMediaResize(0, 0, pixmap->width(), pixmap->height());
        qDebug("SETTING THE BOUNDS");
    }
}

void image::onFileDownloadComplete(QString fileName){
    loadImage(fileName);
}

void image::onFileUploadComplete(QString fileName){

}

void image::onSave(){
    ServerAPI::uploadFile(this, mData.content.toString());
}

QString image::getMediaType(){
    return "image";
}
