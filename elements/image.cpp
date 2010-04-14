#include "image.h"

image::image(QWidget* parent):QLabel(parent)
{
    setStyleSheet("background-color: transparent");
    show();
    autoSize = false;
    pixmap = 0;
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
    else
        loadImage(mData.content.toString());
};
void image::showMenu(){
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), QDir::homePath(), tr("Image Files (*.png *.jpeg *.jpg)"));
    if(fileName.isEmpty())
        return;
    loadImage(fileName);
};

void image::loadImage(QString path){
    if(pixmap != 0)
        delete pixmap;
    pixmap = new QPixmap(path);
    if(!pixmap->isNull())
        setBounds(0,0, pixmap->width(), pixmap->height());
    else
       qDebug() << "///// ERROR there should be an image with path (" << path << "), but there is not!";
}

/*
data.media.img.pixmap = new QPixmap();
data.media.type = "image";
if(fileName.isEmpty()){
    fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), QDir::homePath(), tr("Image Files (*.png *.jpeg *.jpg)"));
    QFile* f = new QFile(fileName);
    QFileInfo pathInfo( fileName );
    QDate date = QDate::currentDate();
    QTime time = QTime::currentTime();
    fileName = "img/"+date.toString("MM-dd-yy_")+time.toString("hh-mm-")+pathInfo.fileName();
    ftpHandler::copyToTemp(f, fileName);
}
//ftpHandler::uploadFile(f, nName);
data.media.img.pixmap->load(ftpHandler::localPath()+fileName);
data.media.img.path = fileName;
qDebug() << "loading img at location: " << ftpHandler::localPath()+fileName;
if(resetPostion){
    data.media.w = data.media.img.pixmap->width();
    data.media.h = data.media.img.pixmap->height();
    data.media.x = 0;
    data.media.y = 0;
}
updateImg();*/
