QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    distributeur.cpp \
    distributeurfenetre.cpp \
    main.cpp \
    mainwindow.cpp \
    monnayeur.cpp \
    produit.cpp \
    stock.cpp

HEADERS += \
    distributeur.h \
    distributeurfenetre.h \
    mainwindow.h \
    monnayeur.h \
    produit.h \
    stock.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    ProjetCDistributeur_fr_DZ.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
