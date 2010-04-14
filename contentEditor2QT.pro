# -------------------------------------------------
# Project created by QtCreator 2010-04-08T13:23:01
# -------------------------------------------------
QT += network \
    webkit \
    xml \
    xmlpatterns
TARGET = contentEditor2QT
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    utils/api.cpp \
    elements/page.cpp \
    pagehandler.cpp \
    utils/apiListener.cpp \
    elements/field.cpp \
    elements/media.cpp \
    elements/image.cpp \
    utils/dataStructs.cpp
HEADERS += mainwindow.h \
    utils/api.h \
    utils/dataStructs.h \
    utils/apiListener.h \
    elements/page.h \
    pagehandler.h \
    elements/field.h \
    elements/media.h \
    utils/utils.h \
    elements/image.h
FORMS += mainwindow.ui
INCLUDEPATH += qxmlrpc/
unix { 
    CONFIG(debug, debug|release):LIBS += libqxmlrpc_debug.a
    else:LIBS += libqxmlrpc.a
}
win32:LIBS += /xmlrpc/qxmlrpc.lib
