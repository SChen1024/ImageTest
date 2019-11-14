#ifndef STDAFX_H
#define STDAFX_H

// 预编译头

//系统标准库文件  C++
#include <iostream>
#include <memory>
#include <vector>
#include <math.h>
#include <time.h>
#include <ctime>

// C++ 文件库操作
#include <stdlib.h>
#include <stdio.h>

// QT库
#include <QtGui>
#include <QtWidgets>
#include <QMenuBar>
#include <QMainWindow>

// opencv
#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"

// #include "doctest.h"
//#include "catch.hpp"

// 处理 所有异常  自定义异常处理
#include "./utils/SpdLogger.h"
#include "./utils/myException.h"


// 自定义文件
#include "./inc/imagetest.h"
// #include "./inc/menu.h"


#endif // STDAFX_H
