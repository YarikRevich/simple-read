QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    csvwindow.cpp \
    dataview.cpp \
    docxwindow.cpp \
    filedialog.cpp \
    main.cpp \
    mainwindow.cpp \
    menubarcreator.cpp \
    pdfwindow.cpp \
    settingswindow.cpp \
    txtwindow.cpp

HEADERS += \
    csvwindow.h \
    dataview.h \
    docxwindow.h \
    filedialog.h \
    mainwindow.h \
    menubarcreator.h \
    pdfwindow.h \
    settingswindow.h \
    txtwindow.h

FORMS += \
    csvwindow.ui \
    docxwindow.ui \
    mainwindow.ui \
    pdfwindow.ui \
    settingswindow.ui \
    txtwindow.ui

TRANSLATIONS += \
    project_en_150.ts \
    project_uk_150.ts \
    project_pl_150.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    project_pl_150.ts \
    project_uk_150.ts
