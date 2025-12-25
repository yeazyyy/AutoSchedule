QT       += core gui sql printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addbranchdialog.cpp \
    addcancellationsdialog.cpp \
    addcoachdialog.cpp \
    addcurrentcompetitionsdialog.cpp \
    addeventdialog.cpp \
    addgroupsdialog.cpp \
    addgrouptypedialog.cpp \
    addplacedialog.cpp \
    addpupilsdialog.cpp \
    addranksdialog.cpp \
    addtimedialog.cpp \
    addtrainingdialog.cpp \
    confirmdialog.cpp \
    database.cpp \
    databasewindow.cpp \
    editbranchdialog.cpp \
    editgroupdialog.cpp \
    editorganizationsdialog.cpp \
    editpupildialog.cpp \
    main.cpp \
    mainwindow.cpp \
    organizationswindow.cpp \
    schedule.cpp

HEADERS += \
    addbranchdialog.h \
    addcancellationsdialog.h \
    addcoachdialog.h \
    addcurrentcompetitionsdialog.h \
    addeventdialog.h \
    addgroupsdialog.h \
    addgrouptypedialog.h \
    addplacedialog.h \
    addpupilsdialog.h \
    addranksdialog.h \
    addtimedialog.h \
    addtrainingdialog.h \
    confirmdialog.h \
    database.h \
    databasewindow.h \
    editbranchdialog.h \
    editgroupdialog.h \
    editorganizationsdialog.h \
    editpupildialog.h \
    mainwindow.h \
    organizationswindow.h \
    schedule.h

FORMS += \
    addbranchdialog.ui \
    addcancellationsdialog.ui \
    addcoachdialog.ui \
    addcurrentcompetitionsdialog.ui \
    addeventdialog.ui \
    addgroupsdialog.ui \
    addgrouptypedialog.ui \
    addplacedialog.ui \
    addpupilsdialog.ui \
    addranksdialog.ui \
    addtimedialog.ui \
    addtrainingdialog.ui \
    confirmdialog.ui \
    databasewindow.ui \
    editbranchdialog.ui \
    editgroupdialog.ui \
    editorganizationsdialog.ui \
    editpupildialog.ui \
    mainwindow.ui \
    organizationswindow.ui \
    schedule.ui

TRANSLATIONS += \
    QtLanguage_en.ts \
    QtLanguage_ru.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=
