#include "field.h"
#include "page.h"
#include "pagehandler.h"

field::field(QWidget *parent) :
        QWidget(parent)
{
    background = new QFrame(this);
    setStyleSheet("background-color: transparent;");
    mediaField = 0;

    overlay = new QFrame(this);
    overlay->setStyleSheet("background-color:transparent");
    altKeyPressed = false;

    textEdit = new QTextEdit(this);
    textEdit->setStyleSheet("border:none");
    toggleTextEdit();

    fieldListener = 0;
}

void field::load(int id){
    if(id<0)
        return;
    ServerAPI::getFieldData(this, id);
}

void field::onFieldData(fieldData fd){
    loadData(fd);
}

void field::loadData(fieldData fd){
    data = fd;
    if(mediaField != 0)
        delete mediaField;
    if(data.media.type == "image"){
        addImage();
    }
    setGeometry(data.x, data.y, data.w, data.h);
    updateGeometry();
    setBackgroundColor(data.background);
    if(fieldListener != 0){
        fieldListener->fieldMoved(this);
        fieldListener->fieldResized(this);
    }
    textEdit->setText(data.content);
}

void field::updateGeometry(){
    background->setGeometry(0,0,data.w, data.h);
    overlay->setGeometry(0,0,data.w, data.h);
    textEdit->setGeometry(0,0,data.w,data.h);
    if(mediaField != 0){
        if(mediaField->getAutoSize()){
            mediaField->setBounds(0, 0, data.w, data.h);
        }else{
            mediaField->setBounds(data.media_x, data.media_y, data.media_w, data.media_h);
        }
    }

}

void field::setParentID(int id){

}

void field::save(){
    if(mediaField != 0){
        mediaField->onSave();
        data.media = mediaField->getMediaData();
        data.media.type = mediaField->getMediaType();
    }
    data.content = textEdit->toPlainText();
    ServerAPI::saveFieldData(this, data, mediaField);
}

void field::onFieldSave(int id){
    pageHandler::loadPreview();
}

void field::toggleTextEdit(){
    if(textEdit->isEnabled()){
        textEdit->setEnabled(false);
        textEdit->setStyleSheet("background-color:transparent");
        textEdit->stackUnder(overlay);
    }else{
        textEdit->setEnabled(true);
        textEdit->setStyleSheet("background-color:rgba(255,255,255,50)");
        overlay->stackUnder(textEdit);
    }
}

void field::highlite(){
    //QColor border(255-data.background.red(), 255-data.background.green(), 255-data.background.blue(), 255);
    QColor border(200, 100, 10, 255);
    overlay->setStyleSheet("border: 1px solid "+border.name());
}
void field::unhighlite(){
    overlay->setStyleSheet("border: none;");
}

void field::selectBackgroundColor(){
    QColor color = QColorDialog::getColor(Qt::yellow, this );
    if( color.isValid() )
    {
        setBackgroundColor(color);
    }
}

void field::setBackgroundColor(QColor colr){
    data.background = colr;
    background->setStyleSheet("background-color: "+data.background.name());
}

void field::setMediaField(media* mf){
    mediaField = mf;
    mf->setMediaListener(this);
    mediaField->setBounds(0,0,geometry().width(),geometry().height());
}

void field::onMediaResize(int x, int y, int w, int h){
    data.media_x = x;
    data.media_y = y;
    data.media_w = w;
    data.media_h = h;
}


void field::addImage(bool showLoad){
    image* img = new image(this);
    img->stackUnder(textEdit);
    setMediaField(img);
    img->setMediaData(data.media);
    if(showLoad)
        img->showMenu();
}

void field::addFieldListener(fieldMoveListener* listener){
    fieldListener = listener;
}

void field::enterEvent( QEvent * event ){
    setFocus();
}

void field::leaveEvent( QEvent * event ){
    parent->setFocus();
    altKeyPressed = false;
}

void field::keyPressEvent ( QKeyEvent * event ){
    if(event->key()==16777251){
        altKeyPressed = true;
    }
}

void field::keyReleaseEvent ( QKeyEvent * event ){
    if(event->key()==16777251){
        altKeyPressed = false;
    }
}

void field::mousePressEvent( QMouseEvent * event ){
    parent->selectFields(this);
    mouseOffset.setX(event->x());
    mouseOffset.setY(event->y());
    if(event->button()==Qt::RightButton){
        mode = MEDIA_DRAG;
        return;
    }
    if(altKeyPressed){
        mode = MEDIA_SCALE;
        return;
    }
    parent->fieldOverlayShow();
    parent->fieldOverlayPosition(geometry());
    if(event->x()>width()-FIELD_SCALE_AREA && event->x()<width()){
        if(event->y()>height()-FIELD_SCALE_AREA && event->y()<height()){
            mode = FIELD_SCALE;
            return;
        }
    }
    mode = FIELD_DRAG;
}

void field::mouseReleaseEvent( QMouseEvent * event ){
    parent->fieldOverlayHide();
}

void field::mouseDoubleClickEvent ( QMouseEvent * event ){
    if(mediaField != 0){
        mediaField->showMenu();
        return;
    }
    toggleTextEdit();
}

void field::mouseMoveEvent( QMouseEvent * event ){
    QRect r;
    QRect overlay;
    QRect mRect;
    int modeX = ROUND_MODE;
    int modeY = ROUND_MODE;
    bool moveMouse = false;
    bool updateMouseOffset = false;
    switch(mode){
    case FIELD_DRAG:
        parent->fieldOverlayPosition(x()+event->x()-mouseOffset.x(), y()+event->y()-mouseOffset.y(), width(), height());
        r = parent->fieldOverlayGetPosition();
        r.x()<x()?modeX = CEIL_MODE:modeX = FLOOR_MODE;
        r.y()<y()?modeY = CEIL_MODE:modeY = FLOOR_MODE;

        setGeometry(toGrid(r, modeX, modeY));
        data.x = geometry().x();
        data.y = geometry().y();
        if(fieldListener!=0)
            fieldListener->fieldMoved(this);
        break;
    case FIELD_SCALE:
        overlay = parent->fieldOverlayGetPosition();
        parent->fieldOverlayPosition(x(), y(), overlay.width()+event->x()-mouseOffset.x(), overlay.height()+event->y()-mouseOffset.y());
        r = parent->fieldOverlayGetPosition();
        r.width()<width()?modeX = CEIL_MODE:modeX = FLOOR_MODE;
        r.height()<height()?modeY = CEIL_MODE:modeY = FLOOR_MODE;
        updateMouseOffset = true;
        setGeometry(toGrid(r, modeX, modeY));
        data.w = geometry().width();
        data.h = geometry().height();
        updateGeometry();
        if(fieldListener!=0)
            fieldListener->fieldResized(this);
        break;
    case MEDIA_DRAG:
        if(mediaField == 0)
            break;
        mRect = mediaField->getBounds();
        mediaField->setBounds(mRect.x()+event->x()-mouseOffset.x(), mRect.y()+event->y()-mouseOffset.y(), mRect.width(), mRect.height());
        data.media_x = mediaField->getBounds().x();
        data.media_y = mediaField->getBounds().y();
        updateMouseOffset = true;
        break;
    case MEDIA_SCALE:
        if(mediaField == 0)
            break;
        mRect = mediaField->getBounds();
        mediaField->setBounds(mRect.x(), mRect.y(), mRect.width()+event->x()-mouseOffset.x(), mRect.height()+event->y()-mouseOffset.y());
        updateMouseOffset = true;
        data.media_w = mediaField->getBounds().width();
        data.media_h = mediaField->getBounds().height();
        break;
    }
    if(moveMouse){
        if(event->x()<0){
            QCursor::setPos(x()+width(), QCursor::pos().y());
            if(updateMouseOffset){
                mouseOffset.setX(width());
                updateMouseOffset = false;
            }
        }else if(event->x()>(x()+width())){
            QCursor::setPos(x(),QCursor::pos().y());
            if(updateMouseOffset){
                mouseOffset.setX(0);
                updateMouseOffset = false;
            }
        }

    }
    if(updateMouseOffset){
        mouseOffset.setX(event->x());
        mouseOffset.setY(event->y());
    }
}
