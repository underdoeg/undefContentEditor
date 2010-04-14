#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pagehandler.h"

class WebView: public QWebView{
public:
    WebView():QWebView(){

    }
    void hide(){
        qDebug("hidden");
    }
};

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    webView = new QWebView();
    webView->setWindowTitle("contentEditor preview");
    webView->setWindowFlags(Qt::WindowStaysOnTopHint); // | Qt::FramelessWindowHint

    pageHandler::loadPages();
    pageHandler::treeWidget = ui->pagesList;
    pageHandler::pageStack = ui->pageStack;
    pageHandler::webView = webView;
    pageHandler::setup();

    setGeometry(50, 50, 1200, 700);

    connect(ui->savePage,SIGNAL(triggered()),this, SLOT(savePage()));

    connect(ui->togglePagesList,SIGNAL(triggered()),this, SLOT(togglePagesList()));
    connect(ui->toggleFullscreen,SIGNAL(triggered()),this, SLOT(toggleFullscreen()));
    connect(ui->togglePreview,SIGNAL(triggered()),this, SLOT(togglePreview()));
    connect(ui->newPage,SIGNAL(triggered()),this, SLOT(newPage()));
    connect(ui->newField,SIGNAL(triggered()),this, SLOT(newField()));
    connect(ui->backgroundColor, SIGNAL(triggered()), this, SLOT(setFieldBackgroundColor()));
    connect(ui->addImage, SIGNAL(triggered()), pageHandler::getSingleton(), SLOT(addImage()));

    lastWebViewGeometry = QRect(200,200,500,400);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::savePage(){
    pageHandler::savePage();
}

void MainWindow::newPage(){
    pageHandler::addPage();
}

void MainWindow::newField(){
    pageHandler::addField();
}

void MainWindow::addImage(){

}

void MainWindow::setFieldBackgroundColor(){
    pageHandler::setFieldBackgroundColor();
}

void MainWindow::togglePagesList(bool stat){
    if(ui->pagesList->isHidden())
        ui->pagesList->show();
    else
        ui->pagesList->hide();
}

void MainWindow::toggleFullscreen(bool stat){
    if(isFullScreen()){
        showNormal();
        setFocus();
    }
    else
        showFullScreen();
}

void MainWindow::onPreviewHide(){
    lastWebViewGeometry = webView->geometry();
}

void MainWindow::togglePreview(bool stat){
    if(webView->isVisible()){
        lastWebViewGeometry = webView->geometry();
        webView->hide();
    }
    else{
        webView->setGeometry(lastWebViewGeometry);
        webView->show();
        pageHandler::loadPreview();
    }
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
