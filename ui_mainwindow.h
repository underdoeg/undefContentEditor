/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Apr 15 03:38:54 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStackedWidget>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *newPage;
    QAction *deletePage;
    QAction *newField;
    QAction *deleteField;
    QAction *togglePagesList;
    QAction *toggleFullscreen;
    QAction *togglePreview;
    QAction *savePage;
    QAction *backgroundColor;
    QAction *addImage;
    QAction *toggleText;
    QAction *pageBackgroundColor;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTreeWidget *pagesList;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QStackedWidget *pageStack;
    QWidget *page;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QWidget *page_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(824, 500);
        newPage = new QAction(MainWindow);
        newPage->setObjectName(QString::fromUtf8("newPage"));
        deletePage = new QAction(MainWindow);
        deletePage->setObjectName(QString::fromUtf8("deletePage"));
        newField = new QAction(MainWindow);
        newField->setObjectName(QString::fromUtf8("newField"));
        deleteField = new QAction(MainWindow);
        deleteField->setObjectName(QString::fromUtf8("deleteField"));
        togglePagesList = new QAction(MainWindow);
        togglePagesList->setObjectName(QString::fromUtf8("togglePagesList"));
        togglePagesList->setCheckable(true);
        toggleFullscreen = new QAction(MainWindow);
        toggleFullscreen->setObjectName(QString::fromUtf8("toggleFullscreen"));
        toggleFullscreen->setCheckable(true);
        togglePreview = new QAction(MainWindow);
        togglePreview->setObjectName(QString::fromUtf8("togglePreview"));
        savePage = new QAction(MainWindow);
        savePage->setObjectName(QString::fromUtf8("savePage"));
        backgroundColor = new QAction(MainWindow);
        backgroundColor->setObjectName(QString::fromUtf8("backgroundColor"));
        addImage = new QAction(MainWindow);
        addImage->setObjectName(QString::fromUtf8("addImage"));
        toggleText = new QAction(MainWindow);
        toggleText->setObjectName(QString::fromUtf8("toggleText"));
        pageBackgroundColor = new QAction(MainWindow);
        pageBackgroundColor->setObjectName(QString::fromUtf8("pageBackgroundColor"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(3, 3, 3, 3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pagesList = new QTreeWidget(centralWidget);
        pagesList->setObjectName(QString::fromUtf8("pagesList"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pagesList->sizePolicy().hasHeightForWidth());
        pagesList->setSizePolicy(sizePolicy);
        pagesList->setMinimumSize(QSize(250, 0));
        pagesList->setDragEnabled(true);
        pagesList->setDragDropMode(QAbstractItemView::DragDrop);
        pagesList->setDefaultDropAction(Qt::MoveAction);

        gridLayout->addWidget(pagesList, 0, 0, 1, 1);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pageStack = new QStackedWidget(widget);
        pageStack->setObjectName(QString::fromUtf8("pageStack"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        horizontalLayout_2 = new QHBoxLayout(page);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(12, 0, 12, 12);
        label = new QLabel(page);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(350, 0));
        label->setTextFormat(Qt::RichText);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label->setWordWrap(true);
        label->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        horizontalLayout_2->addWidget(label);

        pageStack->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        pageStack->addWidget(page_2);

        horizontalLayout->addWidget(pageStack);


        gridLayout->addWidget(widget, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 824, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setMovable(true);
        mainToolBar->setFloatable(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        mainToolBar->addAction(newPage);
        mainToolBar->addAction(savePage);
        mainToolBar->addAction(deletePage);
        mainToolBar->addAction(pageBackgroundColor);
        mainToolBar->addSeparator();
        mainToolBar->addAction(newField);
        mainToolBar->addAction(deleteField);
        mainToolBar->addSeparator();
        mainToolBar->addAction(backgroundColor);
        mainToolBar->addAction(addImage);
        mainToolBar->addAction(toggleText);
        mainToolBar->addSeparator();
        mainToolBar->addAction(togglePagesList);
        mainToolBar->addAction(toggleFullscreen);
        mainToolBar->addAction(togglePreview);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "contentEditor .001", 0, QApplication::UnicodeUTF8));
        newPage->setText(QApplication::translate("MainWindow", "new page", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        newPage->setToolTip(QApplication::translate("MainWindow", "create a new page", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        newPage->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+N", 0, QApplication::UnicodeUTF8));
        deletePage->setText(QApplication::translate("MainWindow", "delete page", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        deletePage->setToolTip(QApplication::translate("MainWindow", "delete the selected page", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        deletePage->setShortcut(QApplication::translate("MainWindow", "Ctrl+Backspace", 0, QApplication::UnicodeUTF8));
        newField->setText(QApplication::translate("MainWindow", "new field", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        newField->setToolTip(QApplication::translate("MainWindow", "create a new field in the active page", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        newField->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        deleteField->setText(QApplication::translate("MainWindow", "delete field", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        deleteField->setToolTip(QApplication::translate("MainWindow", "create a new field in the active page", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        deleteField->setShortcut(QApplication::translate("MainWindow", "Backspace", 0, QApplication::UnicodeUTF8));
        togglePagesList->setText(QApplication::translate("MainWindow", "togglePages", 0, QApplication::UnicodeUTF8));
        togglePagesList->setShortcut(QApplication::translate("MainWindow", "T", 0, QApplication::UnicodeUTF8));
        toggleFullscreen->setText(QApplication::translate("MainWindow", "fullscreen", 0, QApplication::UnicodeUTF8));
        toggleFullscreen->setShortcut(QApplication::translate("MainWindow", "F", 0, QApplication::UnicodeUTF8));
        togglePreview->setText(QApplication::translate("MainWindow", "preview", 0, QApplication::UnicodeUTF8));
        togglePreview->setShortcut(QApplication::translate("MainWindow", "P", 0, QApplication::UnicodeUTF8));
        savePage->setText(QApplication::translate("MainWindow", "save page", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        savePage->setToolTip(QApplication::translate("MainWindow", "save your active page", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        savePage->setShortcut(QApplication::translate("MainWindow", "S", 0, QApplication::UnicodeUTF8));
        backgroundColor->setText(QApplication::translate("MainWindow", "color", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        backgroundColor->setToolTip(QApplication::translate("MainWindow", "set the background color of the selected field", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        backgroundColor->setShortcut(QApplication::translate("MainWindow", "C", 0, QApplication::UnicodeUTF8));
        addImage->setText(QApplication::translate("MainWindow", "add image", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        addImage->setToolTip(QApplication::translate("MainWindow", "add an image to the selected field", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        addImage->setShortcut(QApplication::translate("MainWindow", "I", 0, QApplication::UnicodeUTF8));
        toggleText->setText(QApplication::translate("MainWindow", "edit text", 0, QApplication::UnicodeUTF8));
        pageBackgroundColor->setText(QApplication::translate("MainWindow", "color", 0, QApplication::UnicodeUTF8));
        pageBackgroundColor->setShortcut(QApplication::translate("MainWindow", "Ctrl+B", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = pagesList->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "page", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Lucida Grande'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:20pt;\">welcome to undef content editor</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:20pt;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">this is a beta version, so use it at your own risk!</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">there is a"
                        " slight chance, that something might explode. If not your computer, then maybe your head, because there are probably some things not working correctly. for now...</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">This is not my fault, I'm just a simple software and do what I'm told to. so if you have any complains at all, send them to <a href=\"mailto:mail@undef.ch\"><span style=\" text-decoration: underline; color:#0000ff;\">mail@undef.ch</span></a>.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">thank you &amp; enjoy using me!</p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
