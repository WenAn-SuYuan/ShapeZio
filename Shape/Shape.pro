QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    GlobalArray.cpp \
    belt.cpp \
    bomb.cpp \
    circle.cpp \
    leftcircle.cpp \
    main.cpp \
    mainscene.cpp \
    maplabel.cpp \
    playscene.cpp \
    rightcircle.cpp \
    scissor.cpp \
    shop.cpp \
    shovel.cpp \
    startbutton.cpp \
    task.cpp \
    trashbin.cpp \
    triangle.cpp

HEADERS += \
    GlobalArray.h \
    belt.h \
    bomb.h \
    circle.h \
    leftcircle.h \
    mainscene.h \
    maplabel.h \
    playscene.h \
    rightcircle.h \
    scissor.h \
    shop.h \
    shovel.h \
    startbutton.h \
    task.h \
    trashbin.h \
    triangle.h

FORMS += \
    mainscene.ui

TRANSLATIONS += \
    Shape_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
