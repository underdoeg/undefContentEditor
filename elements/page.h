#ifndef PAGE_H
#define PAGE_H

#include <QWidget>
#include <QTreeWidgetItem>
#include <QHBoxLayout>
#include <QInputDialog>
#include <QScrollArea>
#include "utils/api.h"
#include "field.h"

class page : public QWidget, public apiListener, public fieldMoveListener
{
Q_OBJECT
public:
    explicit page(QWidget *parent = 0);
    void load(int id);
    void createField(int id=-1);
    void addField(field* f);
    void parseData();
    int getID();
    void fieldOverlayShow();
    void fieldOverlayHide();
    void fieldOverlayPosition(int x, int y, int w, int h);
    void fieldOverlayPosition(QRect r);
    void onPageSave(int id);
    void save();
    void onPageData(pageData pd);
    void selectFields(field* f);
    void unselectFields();
    void mouseReleaseEvent ( QMouseEvent * event );
    void activeFieldSelectBackground();
    void addImage(bool showLoader=false);
    void toggleTextEdit();
    void resetMinSize();
    void fieldMoved(field *f);
    void fieldResized(field *f);
    void setBackgroundColor(QColor bgColor);
    void pickBackgroundColor();
    void updateTitle(QString name="");
    QRect fieldOverlayGetPosition();

    QTreeWidgetItem* treeWidgetItem;

signals:

public slots:

private:
    pageData data;
    bool dataChanged;
    QList<field*> fields;
    QWidget* fieldOverlay;
    field* fieldToDrag;
    QList<field*> selectedFields;
    QScrollArea* scrollArea;
    QWidget* fieldRoot;
};

#endif // PAGE_H
