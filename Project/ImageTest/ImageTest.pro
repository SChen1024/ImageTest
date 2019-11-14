#-------------------------------------------------
#
# Project created by QtCreator 2019-10-28T13:22:26
#
#-------------------------------------------------

QT       += core gui

QT  += multimedia       # 媒体文件支持
QT  += quick qml        # qml 支持

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ImageTest
TEMPLATE = app

# add  c11 支持
CONFIG += c++11
CONFIG += console       # 打开命令行调试

# Add  precompile header
CONFIG += precompile_header
PRECOMPILED_HEADER = code/stdafx.h
# 禁止 4819 警告   代码编码 问题
QMAKE_CXXFLAGS += /wd"4819"

message("==========Start Generate Project==========")

# 版本信息
VERSION = 0.2.9
# 图标
# RC_ICONS = code/ui/Panorama.png  # 图标

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


message("App:  $$TARGET, Version: $$VERSION");

# 在 win32 情况下编译
win32 {
    message("Using Win32 Config")
    # win10   出现出现 找不到 标准文件 需要指定路径
    INCLUDEPATH += "C:/Program Files (x86)/Windows Kits/10/Include/10.0.10240.0/ucrt"
    LIBS += -L"C:/Program Files (x86)/Windows Kits/10/Lib/10.0.10240.0/ucrt/x64"

    DEPEND_PATH  = $$PWD/../depends
    # opencv  库路径
    OPENCV_PATH = $$DEPEND_PATH/opencv
    OPENCV_INC  = $$OPENCV_PATH/include \
                  $$OPENCV_PATH/include/opencv \
                  $$OPENCV_PATH/include/opencv2
    OPENCV_LIB  = $$OPENCV_PATH/lib/opencv_world341.lib \
                  $$OPENCV_PATH/lib/opencv_world341d.lib

    SPDLOG_PATH =  $$DEPEND_PATH/spdlog/
    SPDLOG_INC  =  $$SPDLOG_PATH/include \
                   $$SPDLOG_PATH/include/spdlog

    DOCTEST_PATH = $$DEPEND_PATH/doctest
    DOCTEST_INC  = $$DOCTEST_PATH

    CATCH_PAYH   = $$DEPEND_PATH/catch2
    CATCH_INC   = $$CATCH_PAYH/include

    TINYXML_PATH = $$DEPEND_PATH/tinyxml2/
    TINYXML_INC  = $$TINYXML_PATH/include


    INCLUDEPATH += $$OPENCV_INC \
                   $$SPDLOG_INC \
                   $$TINYXML_INC \
                   $$DOCTEST_INC  \
                   $$CATCH_INC

    LIBS +=     $$OPENCV_LIB \
                $$QWT_LIB
}

message("Include path: $$INCLUDEPATH")
message("Lib path: $$LIBS")


# 工程文件
SOURCES += \
    code/src/imagetest.cc \
    code/main.cpp
HEADERS += \
    code/inc/imagetest.h \
    code/stdafx.h \
    code/utils/myException.h \
    code/utils/SpdLogger.h

DISTFILES += \
    code/ui/image.png

RESOURCES += \
    code/ui/res.qrc


message("================== End Generate =========================")
