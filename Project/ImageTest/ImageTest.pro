#-------------------------------------------------
#
# Project created by QtCreator 2019-10-28T13:22:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ImageTest
TEMPLATE = app

# add  c11 支持
CONFIG += c++11

# Add  precompile header
CONFIG += precompile_header
PRECOMPILED_HEADER = code/stdafx.h

# add version

# 版本信息
VERSION = 0.2.9
# 图标
# RC_ICONS = Code/ui/icon/Panorama.ico
#名称
QMAKE_TARGET_COMPANY = "S.Chen"

QMAKE_TARGET_PRODUCT = "Image Lab"
# 文件说明
QMAKE_TARGET_DESCRIPTION = "Image Test Lab Soft Platform"
# 版权信息
QMAKE_TARGET_COPYRIGHT = "Copyright S.Chen. All rights reserved."
# 中文（简体）
RC_LANG = 0x0004



# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# add  opencv lib

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../depends/opencv/lib/ -lopencv_world341
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../depends/opencv/lib/ -lopencv_world341d
else:unix:!macx: LIBS += -L$$PWD/../depends/opencv/lib/ -lopencv_world341

INCLUDEPATH += $$PWD/../depends/opencv/include
DEPENDPATH += $$PWD/../depends/opencv/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../depends/opencv/lib/libopencv_world341.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../depends/opencv/lib/libopencv_world341d.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../depends/opencv/lib/opencv_world341.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../depends/opencv/lib/opencv_world341d.lib
else:unix:!macx: PRE_TARGETDEPS += $$PWD/../depends/opencv/lib/libopencv_world341.a


# 工程文件

FORMS += \
    code/ui/imagetest.ui

SOURCES += \
    code/src/imagetest.cc \
    code/src/menu.cc

HEADERS += \
    code/inc/imagetest.h \
    code/inc/menu.h \
    code/stdafx.h
