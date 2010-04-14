#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebView>
#include "elements/page.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void savePage();

    void togglePagesList(bool stat=false);
    void toggleFullscreen(bool stat=false);
    void togglePreview(bool stat=false);
    void onPreviewHide();
    void newPage();
    void newField();
    void addImage();
    void setFieldBackgroundColor();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    QWebView* webView;
    QRect lastWebViewGeometry;
};

#endif // MAINWINDOW_H
