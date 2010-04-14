#ifndef PAGEHANDLER_H
#define PAGEHANDLER_H

#include <QWidget>
#include <QWebView>
#include <QTreeWidget>
#include <QStackedWidget>
#include "utils/api.h"
#include "elements/page.h"

class pageHandler : public QWidget, public apiListener
{
    Q_OBJECT
public:
    explicit pageHandler(QWidget *parent = 0);
    void mouseReleaseEvent ( QMouseEvent * event );
    void onPagesList(QList<int> list);
    static pageHandler* getSingleton();
    static page* addPage(int id=0);
    static page* getCurrentPage();
    static page* getPageByID(int id);

    static QTreeWidget* treeWidget;
    static QStackedWidget* pageStack;
    static QWebView* webView;

public slots:
    static void loadPages();
    static void addPage(page* p);
    static void removePage(int id);
    static void removePage(page* p);
    static void updateTree();
    static void showPage(page* p);
    static void showPage(int id);
    static void setup();
    static void loadPreview(int id=-1);
    static void savePage(int id = -1);
    static void addField(int parentID = -1);
    static void addImage();
    static void setFieldBackgroundColor();

signals:

public slots:
    void treeItemClicked(QTreeWidgetItem *);
private:
    static pageHandler* singleton;
    static QList<page*> pages;
    static page* currentPage;
};

#endif // PAGEHANDLER_H
