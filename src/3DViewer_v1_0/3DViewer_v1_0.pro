QT       += core gui opengl

macx { QT  +=  openglwidgets }


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG(release, debug|release):DEFINES += QT_NO_DEBUG_OUTPUT
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    gifanim/gifanim.cpp \
    functions/affine_transformations.c \
    functions/reading_obj_file.c \
    info.cpp \
    main.cpp \
    mainwindow.cpp \
    mainwindow_move.cpp \
    mainwindow_rotate.cpp \
    mainwindow_scale.cpp \
    mainwindow_settings.cpp \
    mainwindow_screenshots.cpp \
    movement_controller.cc \
    rotation_controller.cc \
    widget.cpp

HEADERS += \
    functions/affine_transformations.h \
    functions/reading_obj_file.h \
    functions/structs.h \
    info.h \
    mainwindow.h \
    gifanim/gifanim.h \
    movement_controller.h \
    rotation_controller.h \
    widget.h

FORMS += \
    info.ui \
    mainwindow.ui

TRANSLATIONS += \
    3DViewer_v1_0_en_001.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = ../build
else: unix:!android: target.path = ../build
!isEmpty(target.path): INSTALLS += target
