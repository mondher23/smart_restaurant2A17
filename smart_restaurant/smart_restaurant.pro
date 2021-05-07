QT       += core gui sql printsupport charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    achat.cpp \
    achatwindow.cpp \
    avis.cpp \
    carte.cpp \
    client.cpp \
    clientwindow.cpp \
    connection.cpp \
    excel.cpp \
    fonction.cpp \
    fournisseur.cpp \
    ingredients.cpp \
    main.cpp \
    mainwindow.cpp \
    personnels.cpp \
    personnelwindow.cpp \
    plats.cpp \
    platswindow.cpp \
    specialites.cpp \
    vente.cpp \
    ventewindow.cpp

HEADERS += \
    achat.h \
    achatwindow.h \
    avis.h \
    carte.h \
    client.h \
    clientwindow.h \
    connection.h \
    excel.h \
    fonction.h \
    fournisseur.h \
    ingredients.h \
    mainwindow.h \
    personnels.h \
    personnelwindow.h \
    plats.h \
    platswindow.h \
    specialites.h \
    vente.h \
    ventewindow.h

FORMS += \
    achatwindow.ui \
    clientwindow.ui \
    mainwindow.ui \
    personnelwindow.ui \
    platswindow.ui \
    ventewindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
