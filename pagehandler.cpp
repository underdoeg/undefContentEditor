#include "pagehandler.h"
pageHandler* pageHandler::singleton = 0;
QTreeWidget* pageHandler::treeWidget = 0;
QStackedWidget* pageHandler::pageStack = 0;
QList<page*> pageHandler::pages;
QWebView* pageHandler::webView;
page* pageHandler::currentPage = 0;

pageHandler::pageHandler(QWidget *parent) :
        QWidget(parent)
{
}

void pageHandler::setup(){
    connect(treeWidget,SIGNAL(itemClicked(QTreeWidgetItem *, int)), getSingleton(), SLOT(treeItemClicked(QTreeWidgetItem *)));
    connect(treeWidget,SIGNAL(itemDoubleClicked(QTreeWidgetItem *, int)), getSingleton(), SLOT(treeItemDoubleClicked(QTreeWidgetItem *)));
    connect(treeWidget,SIGNAL(itemSelectionChanged()), getSingleton(), SLOT(treeItemSelectionChanged()));

}

pageHandler* pageHandler::getSingleton(){
    if(singleton==0)
        singleton = new pageHandler();
    return singleton;
}

void pageHandler::loadPages(){
    ServerAPI::getPageIDs(getSingleton());
}

void pageHandler::onPagesList(QList<int> list){
    for(int i=0;i<list.size();i++){
        addPage(list[i]);
    }
};

void pageHandler::addPage(int id){
    page* p = new page(getSingleton());
    pageStack->addWidget(p);
    addPage(p);
    if(id>0)p->load(id);else{ pageData d; p->onPageData(d); showPage(p); };
    pageStack->update();
}

void pageHandler::addPage(){
    addPage(-1);
}

void pageHandler::addPage(page* p){
    pages << p;
}

void pageHandler::removePage(int id){

}
void pageHandler::removePage(page* p){

}

void pageHandler::setPageBackgroundColor(){
    page* p = getCurrentPage();
    if(p == 0)
        return;
    p->pickBackgroundColor();
}

void pageHandler::addField(int parentID){
    page* p = getCurrentPage();
    if(parentID>0)
        p = getPageByID(parentID);
    if(p == 0)
        return;
    p->createField(0);
}

page* pageHandler::getPageByID(int id){
    for(int i=0;i<pages.size();i++){
        if(pages[i]->getID() == id)
            return pages[i];
    }
    return 0;
}

page* pageHandler::getPageByTreeItem(QTreeWidgetItem* ti){
    for(int i=0;i<pages.size();i++){
        if(pages[i]->treeWidgetItem == ti)
            return pages[i];
    }
    return 0;
}

void pageHandler::showPage(page* p){
    if(p == 0)
        return;
    p->parseData();
    pageStack->setCurrentWidget(p);
    loadPreview(p->getID());
    currentPage = p;
}

page* pageHandler::getCurrentPage(){
    return currentPage;
}

void pageHandler::showPage(int id){
    showPage(getPageByID(id));
}

void pageHandler::savePage(int id){
    page* p = getCurrentPage();
    if(id > 0)
        p = getPageByID(id);
    if(p == 0)
        return;
    p->save();
}

void pageHandler::addImage(){
    page* p = getCurrentPage();
    if(p == 0)
        return;
    p->addImage(true);
}

void pageHandler::setFieldBackgroundColor(){
    page* p = getCurrentPage();
    if(p == 0)
        return;
    p->activeFieldSelectBackground();
}

void pageHandler::toggleTextEdit(){
    page* p = getCurrentPage();
    if(p == 0)
        return;
    p->toggleTextEdit();
}

void pageHandler::exportPDF(){
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("printout.pdf");
    printer.setFullPage(true);
    printer.setOrientation(QPrinter::Portrait);
    printer.setPaperSize(QPrinter::A4);
    QPainter painter(&printer);

    pageStack->render(&painter, QPoint(0,0));
    //ui->table->render(&painter,QPoint(80,100));
}

void pageHandler::mouseReleaseEvent ( QMouseEvent * event ){

}

void pageHandler::updateTree(){
    treeWidget->update();
}

void pageHandler::treeItemClicked(QTreeWidgetItem *ti){
    /* for(int i=0;i<pages.size();i++){
        if(pages[i]->treeWidgetItem == ti)
            showPage(pages[i]);
    }*/
}

void pageHandler::treeItemSelectionChanged(){
    if(treeWidget->selectedItems().size()==0)
        return;
    for(int i=0;i<pages.size();i++){
        if(pages[i]->treeWidgetItem == treeWidget->selectedItems()[0]){
            showPage(pages[i]);
            return;
        }
    }
}

void pageHandler::treeItemDoubleClicked(QTreeWidgetItem* ti){
    page* p = getPageByTreeItem(ti);
    if(p==0)
        return;
    p->updateTitle();
}

void pageHandler::loadPreview(int id){
    if(webView->isHidden())
        return;
    if(id == -1){
        page* p = getCurrentPage();
        if(p == 0)
            return;
        id = p->getID();
    }
    QString url = "http://"+ServerAPI::rpcHost+"/contentEditor/server/pages/view/";
    QString num;
    num.setNum(id);
    url+= num;
    webView->load(QUrl(url));
}
