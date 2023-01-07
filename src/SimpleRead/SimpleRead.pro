QT += core gui \
    quickwidgets \
    sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

TARGET = SimpleRead

DESTDIR = target

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    csvwindow.cpp \
    dataview.cpp \
    docxwindow.cpp \
    filewindow.cpp \
    globalqmlengine.cpp \
    logger.cpp \
    main.cpp \
    pdfwindow.cpp \
    qmltyperegistrator.cpp \
    qmlwindow.cpp \
    settingswindow.cpp \
    translatorregistrator.cpp \
    txtwindow.cpp

HEADERS += \
    csvwindow.h \
    dataview.h \
    docxwindow.h \
    exceptions.h \
    filewindow.h \
    globalqmlengine.h \
    logger.h \
    mainwindow.h \
    pdfwindow.h \
    qmltyperegistrator.h \
    qmlwindow.h \
    settingswindow.h \
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
    docxwindow.qml \
    csvwindow.qml \
    pdfwindow.qml \
    txtwindow.qml \
    images/united-states.png \
    images/poland.png \
    images/ukraine.png \
    images/lock_edit.png \
    images/unlock_edit.png \
    storage.js \
    project_en.qm \
    project_pl.qm \
    project_uk.qm

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../lib/duckx/release/ -lduckx
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../lib/duckx/debug/ -lduckx
else:unix: LIBS += -L$$PWD/../../lib/duckx/ -lduckx

INCLUDEPATH += $$PWD/../../include/duckx
DEPENDPATH += $$PWD/../../include/duckx

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../lib/duckx/release/libduckx.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../lib/duckx/debug/libduckx.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../lib/duckx/release/duckx.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../lib/duckx/debug/duckx.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../lib/duckx/libduckx.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../lib/pugixml/release/ -lpugixml
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../lib/pugixml/debug/ -lpugixml
else:unix: LIBS += -L$$PWD/../../lib/pugixml/ -lpugixml

INCLUDEPATH += $$PWD/../../include/pugixml
DEPENDPATH += $$PWD/../../include/pugixml

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../lib/pugixml/release/libpugixml.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../lib/pugixml/debug/libpugixml.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../lib/pugixml/release/pugixml.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../lib/pugixml/debug/pugixml.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../lib/pugixml/libpugixml.a

INCLUDEPATH += $$PWD/../../include/zip
DEPENDPATH += $$PWD/../../include/zip

DISTFILES += \
    Info.plist \
    SimpleRead.rc \
    csvwindow.qml \
    docxwindow.qml \
    pdfwindow.qml \
    settingswindow.qml \
    storage.js \
    txtwindow.qml

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../lib/pdfmm/release/ -lpdfmm
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../lib/pdfmm/debug/ -lpdfmm
else:unix: LIBS += -L$$PWD/../../lib/pdfmm/ -lpdfmm

INCLUDEPATH += $$PWD/../../include/pdfmm
DEPENDPATH += $$PWD/../../include/pdfmm

INCLUDEPATH += $$PWD/../../include/rapidcsv
DEPENDPATH += $$PWD/../../include/rapidcsv
