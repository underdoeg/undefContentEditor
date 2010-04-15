#ifndef FIELD_H
#define FIELD_H

#include <QFrame>
#include <QWidget>
#include <QMouseEvent>
#include <QTextEdit>
#include <QColorDialog>
#include "utils/api.h"
#include "utils/utils.h"
#include "image.h"
#include "xmlrpc/variant.h"

class page;
enum{FIELD_DRAG, FIELD_SCALE, MEDIA_DRAG, MEDIA_SCALE};
#define FIELD_SCALE_AREA 20
class field;
class fieldMoveListener{
public:
    virtual void fieldMoved(field* f){};
    virtual void fieldResized(field* f){};
};

class field : public QWidget, public apiListener, public mediaListener
{
Q_OBJECT
public:
    explicit field(QWidget *parent = 0);
    void load(int id);
    void onFieldData(fieldData fd);
    void loadData(fieldData fd);
    void save();
    void updateGeometry();
    void onFieldSave(int id);
    void setParentID(int id);
    void highlite();
    void unhighlite();
    void selectBackgroundColor();
    void setBackgroundColor(QColor colr);
    void addImage(bool showLoader=false);
    void setMediaField(media* mf);
    void keyPressEvent ( QKeyEvent * event );
    void keyReleaseEvent ( QKeyEvent * event );
    void mouseDoubleClickEvent ( QMouseEvent * event );
    void onMediaResize(int x, int y, int w, int h);
    void toggleTextEdit();
    void addFieldListener(fieldMoveListener* listener);
    xmlrpc::Variant getContentData();

    page* parent;
signals:

public slots:
protected:
    void enterEvent( QEvent * event );
    void leaveEvent( QEvent * event );
    void mouseMoveEvent( QMouseEvent * event );
    void mousePressEvent( QMouseEvent * event );
    void mouseReleaseEvent( QMouseEvent * event );

private:
    fieldData data;
    int mode;
    QFrame* background;
    QFrame* overlay;
    QPoint mouseOffset;
    media* mediaField;
    bool altKeyPressed;
    QTextEdit* textEdit;
    fieldMoveListener* fieldListener;
};

#endif // FIELD_H
