QT += core gui quickwidgets sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

TARGET = SimpleRead

DESTDIR = target

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    csvwindow.cpp \
    csvwindowmodel.cpp \
    docxwindow.cpp \
    exceptions.cpp \
    globalqmlengine.cpp \
    logger.cpp \
    main.cpp \
    pdfwindow.cpp \
    qmltyperegistrator.cpp \
    qmlwindow.cpp \
    settingswindow.cpp \
    statistics.cpp \
    statisticswindow.cpp \
    timer.cpp \
    translatorregistrator.cpp \
    txtwindow.cpp

HEADERS += \
    basewindow.h \
    csvwindow.h \
    csvwindowmodel.h \
    docxwindow.h \
    exceptions.h \
    globalqmlengine.h \
    logger.h \
    mainwindow.h \
    pdfwindow.h \
    qmltyperegistrator.h \
    qmlwindow.h \
    settingswindow.h \
    statistics.h \
    statisticswindow.h \
    tablewindow.h \
    textwindow.h \
    textwindowread.h \
    textwindowwrite.h \
    timer.h \
    translatorregistrator.h \
    txtwindow.h

ICON = images/icon.icns

RC_ICONS = images/icon.ico
RC_FILE = SimpleRead.rc

QMAKE_INFO_PLIST = Info.plist

TRANSLATIONS += \
    project_en.ts \
    project_uk.ts \
    project_pl.ts

CONFIG += lrelease \
    embed_translations

RESOURCES += \
    mainwindow.qml \
    settingswindow.qml \
    statisticswindow.qml \
    docxwindow.qml \
    csvwindow.qml \
    pdfwindow.qml \
    txtwindow.qml \
    utils.qml \
    images/united-states.png \
    images/poland.png \
    images/ukraine.png \
    images/lock_edit.png \
    images/unlock_edit.png \
    images/increase_font.png \
    images/decrease_font.png \
    images/save.png \
    images/information.png \
    storage.js \
    project_en.qm \
    project_pl.qm \
    project_uk.qm

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Info.plist \
    SimpleRead.qdocconf \
    SimpleRead.rc \
    csvwindow.qml \
    docxwindow.qml \
    logger.qdoc \
    pdfwindow.qml \
    settingswindow.qml \
    statisticswindow.qml \
    storage.js \
    txtwindow.qml

INCLUDEPATH += $$PWD/../../include/zip
DEPENDPATH += $$PWD/../../include/zip

INCLUDEPATH += $$PWD/../../include/rapidcsv
DEPENDPATH += $$PWD/../../include/rapidcsv

unix|win32: LIBS += -L$$PWD/../../lib/pdfmm/ -lpdfmm

INCLUDEPATH += $$PWD/../../include/pdfmm
DEPENDPATH += $$PWD/../../include/pdfmm

unix|win32: LIBS += -L$$PWD/../../lib/pugixml/ -lpugixml

INCLUDEPATH += $$PWD/../../include/pugixml
DEPENDPATH += $$PWD/../../include/pugixml

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../../lib/pugixml/pugixml.lib
else:unix|win32-g++: PRE_TARGETDEPS += $$PWD/../../lib/pugixml/libpugixml.a

unix|win32: LIBS += -L$$PWD/../../lib/duckx/ -lduckx

INCLUDEPATH += $$PWD/../../include/duckx
DEPENDPATH += $$PWD/../../include/duckx

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../../lib/duckx/duckx.lib
else:unix|win32-g++: PRE_TARGETDEPS += $$PWD/../../lib/duckx/libduckx.a
