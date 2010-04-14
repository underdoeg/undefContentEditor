#############################################################################
# Makefile for building: contentEditor2QT.app/Contents/MacOS/contentEditor2QT
# Generated by qmake (2.01a) (Qt 4.6.2) on: Wed Apr 14 15:16:19 2010
# Project:  contentEditor2QT.pro
# Template: app
# Command: /usr/bin/qmake -spec /usr/local/Qt4.6/mkspecs/macx-g++ -macx -o Makefile contentEditor2QT.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT_LIB -DQT_XMLPATTERNS_LIB -DQT_XML_LIB -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -gdwarf-2 -arch i386 -Wall -W $(DEFINES)
CXXFLAGS      = -pipe -g -gdwarf-2 -arch i386 -Wall -W $(DEFINES)
INCPATH       = -I/usr/local/Qt4.6/mkspecs/macx-g++ -I. -I/Library/Frameworks/QtCore.framework/Versions/4/Headers -I/usr/include/QtCore -I/Library/Frameworks/QtNetwork.framework/Versions/4/Headers -I/usr/include/QtNetwork -I/Library/Frameworks/QtGui.framework/Versions/4/Headers -I/usr/include/QtGui -I/Library/Frameworks/QtXml.framework/Versions/4/Headers -I/usr/include/QtXml -I/Library/Frameworks/QtXmlPatterns.framework/Versions/4/Headers -I/usr/include/QtXmlPatterns -I/Library/Frameworks/QtWebKit.framework/Versions/4/Headers -I/usr/include/QtWebKit -I/usr/include -Iqxmlrpc -I. -I. -F/Library/Frameworks
LINK          = g++
LFLAGS        = -headerpad_max_install_names -arch i386
LIBS          = $(SUBLIBS) -F/Library/Frameworks -L/Library/Frameworks libqxmlrpc_debug.a -framework QtWebKit -framework phonon -framework QtDBus -framework QtXmlPatterns -framework QtXml -framework QtGui -framework QtNetwork -framework QtCore 
AR            = ar cq
RANLIB        = ranlib -s
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
STRIP         = 
INSTALL_FILE  = $(COPY_FILE)
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = $(COPY_FILE)
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
export MACOSX_DEPLOYMENT_TARGET = 10.4

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		mainwindow.cpp \
		utils/api.cpp \
		elements/page.cpp \
		pagehandler.cpp \
		utils/apiListener.cpp \
		elements/field.cpp \
		elements/media.cpp \
		elements/image.cpp \
		utils/dataStructs.cpp moc_mainwindow.cpp \
		moc_api.cpp \
		moc_page.cpp \
		moc_pagehandler.cpp \
		moc_field.cpp
OBJECTS       = main.o \
		mainwindow.o \
		api.o \
		page.o \
		pagehandler.o \
		apiListener.o \
		field.o \
		media.o \
		image.o \
		dataStructs.o \
		moc_mainwindow.o \
		moc_api.o \
		moc_page.o \
		moc_pagehandler.o \
		moc_field.o
DIST          = /usr/local/Qt4.6/mkspecs/common/unix.conf \
		/usr/local/Qt4.6/mkspecs/common/mac.conf \
		/usr/local/Qt4.6/mkspecs/common/mac-g++.conf \
		/usr/local/Qt4.6/mkspecs/qconfig.pri \
		/usr/local/Qt4.6/mkspecs/features/qt_functions.prf \
		/usr/local/Qt4.6/mkspecs/features/qt_config.prf \
		/usr/local/Qt4.6/mkspecs/features/exclusive_builds.prf \
		/usr/local/Qt4.6/mkspecs/features/default_pre.prf \
		/usr/local/Qt4.6/mkspecs/features/mac/default_pre.prf \
		/usr/local/Qt4.6/mkspecs/features/mac/dwarf2.prf \
		/usr/local/Qt4.6/mkspecs/features/debug.prf \
		/usr/local/Qt4.6/mkspecs/features/default_post.prf \
		/usr/local/Qt4.6/mkspecs/features/mac/default_post.prf \
		/usr/local/Qt4.6/mkspecs/features/mac/x86.prf \
		/usr/local/Qt4.6/mkspecs/features/mac/objective_c.prf \
		/usr/local/Qt4.6/mkspecs/features/warn_on.prf \
		/usr/local/Qt4.6/mkspecs/features/qt.prf \
		/usr/local/Qt4.6/mkspecs/features/unix/thread.prf \
		/usr/local/Qt4.6/mkspecs/features/moc.prf \
		/usr/local/Qt4.6/mkspecs/features/mac/rez.prf \
		/usr/local/Qt4.6/mkspecs/features/mac/sdk.prf \
		/usr/local/Qt4.6/mkspecs/features/resources.prf \
		/usr/local/Qt4.6/mkspecs/features/uic.prf \
		/usr/local/Qt4.6/mkspecs/features/yacc.prf \
		/usr/local/Qt4.6/mkspecs/features/lex.prf \
		/usr/local/Qt4.6/mkspecs/features/include_source_dir.prf \
		contentEditor2QT.pro
QMAKE_TARGET  = contentEditor2QT
DESTDIR       = 
TARGET        = contentEditor2QT.app/Contents/MacOS/contentEditor2QT

####### Custom Compiler Variables
QMAKE_COMP_QMAKE_OBJECTIVE_CFLAGS = -pipe \
		-g \
		-gdwarf-2 \
		-arch \
		i386 \
		-Wall \
		-W


first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile contentEditor2QT.app/Contents/PkgInfo contentEditor2QT.app/Contents/Resources/empty.lproj contentEditor2QT.app/Contents/Info.plist $(TARGET)

$(TARGET): ui_mainwindow.h $(OBJECTS)  
	@$(CHK_DIR_EXISTS) contentEditor2QT.app/Contents/MacOS/ || $(MKDIR) contentEditor2QT.app/Contents/MacOS/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: contentEditor2QT.pro  /usr/local/Qt4.6/mkspecs/macx-g++/qmake.conf /usr/local/Qt4.6/mkspecs/common/unix.conf \
		/usr/local/Qt4.6/mkspecs/common/mac.conf \
		/usr/local/Qt4.6/mkspecs/common/mac-g++.conf \
		/usr/local/Qt4.6/mkspecs/qconfig.pri \
		/usr/local/Qt4.6/mkspecs/features/qt_functions.prf \
		/usr/local/Qt4.6/mkspecs/features/qt_config.prf \
		/usr/local/Qt4.6/mkspecs/features/exclusive_builds.prf \
		/usr/local/Qt4.6/mkspecs/features/default_pre.prf \
		/usr/local/Qt4.6/mkspecs/features/mac/default_pre.prf \
		/usr/local/Qt4.6/mkspecs/features/mac/dwarf2.prf \
		/usr/local/Qt4.6/mkspecs/features/debug.prf \
		/usr/local/Qt4.6/mkspecs/features/default_post.prf \
		/usr/local/Qt4.6/mkspecs/features/mac/default_post.prf \
		/usr/local/Qt4.6/mkspecs/features/mac/x86.prf \
		/usr/local/Qt4.6/mkspecs/features/mac/objective_c.prf \
		/usr/local/Qt4.6/mkspecs/features/warn_on.prf \
		/usr/local/Qt4.6/mkspecs/features/qt.prf \
		/usr/local/Qt4.6/mkspecs/features/unix/thread.prf \
		/usr/local/Qt4.6/mkspecs/features/moc.prf \
		/usr/local/Qt4.6/mkspecs/features/mac/rez.prf \
		/usr/local/Qt4.6/mkspecs/features/mac/sdk.prf \
		/usr/local/Qt4.6/mkspecs/features/resources.prf \
		/usr/local/Qt4.6/mkspecs/features/uic.prf \
		/usr/local/Qt4.6/mkspecs/features/yacc.prf \
		/usr/local/Qt4.6/mkspecs/features/lex.prf \
		/usr/local/Qt4.6/mkspecs/features/include_source_dir.prf \
		/Library/Frameworks/QtWebKit.framework/QtWebKit.prl \
		/Library/Frameworks/phonon.framework/phonon.prl \
		/Library/Frameworks/QtDBus.framework/QtDBus.prl \
		/Library/Frameworks/QtXml.framework/QtXml.prl \
		/Library/Frameworks/QtCore.framework/QtCore.prl \
		/Library/Frameworks/QtGui.framework/QtGui.prl \
		/Library/Frameworks/QtXmlPatterns.framework/QtXmlPatterns.prl \
		/Library/Frameworks/QtNetwork.framework/QtNetwork.prl
	$(QMAKE) -spec /usr/local/Qt4.6/mkspecs/macx-g++ -macx -o Makefile contentEditor2QT.pro
/usr/local/Qt4.6/mkspecs/common/unix.conf:
/usr/local/Qt4.6/mkspecs/common/mac.conf:
/usr/local/Qt4.6/mkspecs/common/mac-g++.conf:
/usr/local/Qt4.6/mkspecs/qconfig.pri:
/usr/local/Qt4.6/mkspecs/features/qt_functions.prf:
/usr/local/Qt4.6/mkspecs/features/qt_config.prf:
/usr/local/Qt4.6/mkspecs/features/exclusive_builds.prf:
/usr/local/Qt4.6/mkspecs/features/default_pre.prf:
/usr/local/Qt4.6/mkspecs/features/mac/default_pre.prf:
/usr/local/Qt4.6/mkspecs/features/mac/dwarf2.prf:
/usr/local/Qt4.6/mkspecs/features/debug.prf:
/usr/local/Qt4.6/mkspecs/features/default_post.prf:
/usr/local/Qt4.6/mkspecs/features/mac/default_post.prf:
/usr/local/Qt4.6/mkspecs/features/mac/x86.prf:
/usr/local/Qt4.6/mkspecs/features/mac/objective_c.prf:
/usr/local/Qt4.6/mkspecs/features/warn_on.prf:
/usr/local/Qt4.6/mkspecs/features/qt.prf:
/usr/local/Qt4.6/mkspecs/features/unix/thread.prf:
/usr/local/Qt4.6/mkspecs/features/moc.prf:
/usr/local/Qt4.6/mkspecs/features/mac/rez.prf:
/usr/local/Qt4.6/mkspecs/features/mac/sdk.prf:
/usr/local/Qt4.6/mkspecs/features/resources.prf:
/usr/local/Qt4.6/mkspecs/features/uic.prf:
/usr/local/Qt4.6/mkspecs/features/yacc.prf:
/usr/local/Qt4.6/mkspecs/features/lex.prf:
/usr/local/Qt4.6/mkspecs/features/include_source_dir.prf:
/Library/Frameworks/QtWebKit.framework/QtWebKit.prl:
/Library/Frameworks/phonon.framework/phonon.prl:
/Library/Frameworks/QtDBus.framework/QtDBus.prl:
/Library/Frameworks/QtXml.framework/QtXml.prl:
/Library/Frameworks/QtCore.framework/QtCore.prl:
/Library/Frameworks/QtGui.framework/QtGui.prl:
/Library/Frameworks/QtXmlPatterns.framework/QtXmlPatterns.prl:
/Library/Frameworks/QtNetwork.framework/QtNetwork.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/local/Qt4.6/mkspecs/macx-g++ -macx -o Makefile contentEditor2QT.pro

contentEditor2QT.app/Contents/PkgInfo: 
	@$(CHK_DIR_EXISTS) contentEditor2QT.app/Contents || $(MKDIR) contentEditor2QT.app/Contents 
	@$(DEL_FILE) contentEditor2QT.app/Contents/PkgInfo
	@echo "APPL????" >contentEditor2QT.app/Contents/PkgInfo
contentEditor2QT.app/Contents/Resources/empty.lproj: 
	@$(CHK_DIR_EXISTS) contentEditor2QT.app/Contents/Resources || $(MKDIR) contentEditor2QT.app/Contents/Resources 
	@touch contentEditor2QT.app/Contents/Resources/empty.lproj
	
contentEditor2QT.app/Contents/Info.plist: 
	@$(CHK_DIR_EXISTS) contentEditor2QT.app/Contents || $(MKDIR) contentEditor2QT.app/Contents 
	@$(DEL_FILE) contentEditor2QT.app/Contents/Info.plist
	@sed -e "s,@ICON@,,g" -e "s,@EXECUTABLE@,contentEditor2QT,g" -e "s,@TYPEINFO@,????,g" /usr/local/Qt4.6/mkspecs/macx-g++/Info.plist.app >contentEditor2QT.app/Contents/Info.plist
dist: 
	@$(CHK_DIR_EXISTS) .tmp/contentEditor2QT1.0.0 || $(MKDIR) .tmp/contentEditor2QT1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/contentEditor2QT1.0.0/ && $(COPY_FILE) --parents mainwindow.h utils/api.h utils/dataStructs.h utils/apiListener.h elements/page.h pagehandler.h elements/field.h elements/media.h utils/utils.h elements/image.h .tmp/contentEditor2QT1.0.0/ && $(COPY_FILE) --parents main.cpp mainwindow.cpp utils/api.cpp elements/page.cpp pagehandler.cpp utils/apiListener.cpp elements/field.cpp elements/media.cpp elements/image.cpp utils/dataStructs.cpp .tmp/contentEditor2QT1.0.0/ && $(COPY_FILE) --parents mainwindow.ui .tmp/contentEditor2QT1.0.0/ && (cd `dirname .tmp/contentEditor2QT1.0.0` && $(TAR) contentEditor2QT1.0.0.tar contentEditor2QT1.0.0 && $(COMPRESS) contentEditor2QT1.0.0.tar) && $(MOVE) `dirname .tmp/contentEditor2QT1.0.0`/contentEditor2QT1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/contentEditor2QT1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) -r contentEditor2QT.app
	-$(DEL_FILE) Makefile


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_objective_c_make_all:
compiler_objective_c_clean:
compiler_moc_header_make_all: moc_mainwindow.cpp moc_api.cpp moc_page.cpp moc_pagehandler.cpp moc_field.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindow.cpp moc_api.cpp moc_page.cpp moc_pagehandler.cpp moc_field.cpp
moc_mainwindow.cpp: elements/page.h \
		utils/api.h \
		utils/apiListener.h \
		utils/dataStructs.h \
		elements/field.h \
		utils/utils.h \
		elements/image.h \
		elements/media.h \
		mainwindow.h
	/Developer/Tools/Qt/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ mainwindow.h -o moc_mainwindow.cpp

moc_api.cpp: utils/apiListener.h \
		utils/dataStructs.h \
		utils/api.h
	/Developer/Tools/Qt/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ utils/api.h -o moc_api.cpp

moc_page.cpp: utils/api.h \
		utils/apiListener.h \
		utils/dataStructs.h \
		elements/field.h \
		utils/utils.h \
		elements/image.h \
		elements/media.h \
		elements/page.h
	/Developer/Tools/Qt/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ elements/page.h -o moc_page.cpp

moc_pagehandler.cpp: utils/api.h \
		utils/apiListener.h \
		utils/dataStructs.h \
		elements/page.h \
		elements/field.h \
		utils/utils.h \
		elements/image.h \
		elements/media.h \
		pagehandler.h
	/Developer/Tools/Qt/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ pagehandler.h -o moc_pagehandler.cpp

moc_field.cpp: utils/api.h \
		utils/apiListener.h \
		utils/dataStructs.h \
		utils/utils.h \
		elements/image.h \
		elements/media.h \
		elements/field.h
	/Developer/Tools/Qt/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ elements/field.h -o moc_field.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_rez_source_make_all:
compiler_rez_source_clean:
compiler_uic_make_all: ui_mainwindow.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h
ui_mainwindow.h: mainwindow.ui
	/Developer/Tools/Qt/uic mainwindow.ui -o ui_mainwindow.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: main.cpp mainwindow.h \
		elements/page.h \
		utils/api.h \
		utils/apiListener.h \
		utils/dataStructs.h \
		elements/field.h \
		utils/utils.h \
		elements/image.h \
		elements/media.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		elements/page.h \
		utils/api.h \
		utils/apiListener.h \
		utils/dataStructs.h \
		elements/field.h \
		utils/utils.h \
		elements/image.h \
		elements/media.h \
		ui_mainwindow.h \
		pagehandler.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

api.o: utils/api.cpp utils/api.h \
		utils/apiListener.h \
		utils/dataStructs.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o api.o utils/api.cpp

page.o: elements/page.cpp elements/page.h \
		utils/api.h \
		utils/apiListener.h \
		utils/dataStructs.h \
		elements/field.h \
		utils/utils.h \
		elements/image.h \
		elements/media.h \
		pagehandler.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o page.o elements/page.cpp

pagehandler.o: pagehandler.cpp pagehandler.h \
		utils/api.h \
		utils/apiListener.h \
		utils/dataStructs.h \
		elements/page.h \
		elements/field.h \
		utils/utils.h \
		elements/image.h \
		elements/media.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o pagehandler.o pagehandler.cpp

apiListener.o: utils/apiListener.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o apiListener.o utils/apiListener.cpp

field.o: elements/field.cpp elements/field.h \
		utils/api.h \
		utils/apiListener.h \
		utils/dataStructs.h \
		utils/utils.h \
		elements/image.h \
		elements/media.h \
		elements/page.h \
		pagehandler.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o field.o elements/field.cpp

media.o: elements/media.cpp elements/media.h \
		utils/api.h \
		utils/apiListener.h \
		utils/dataStructs.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o media.o elements/media.cpp

image.o: elements/image.cpp elements/image.h \
		elements/media.h \
		utils/api.h \
		utils/apiListener.h \
		utils/dataStructs.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o image.o elements/image.cpp

dataStructs.o: utils/dataStructs.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dataStructs.o utils/dataStructs.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_api.o: moc_api.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_api.o moc_api.cpp

moc_page.o: moc_page.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_page.o moc_page.cpp

moc_pagehandler.o: moc_pagehandler.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_pagehandler.o moc_pagehandler.cpp

moc_field.o: moc_field.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_field.o moc_field.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:
