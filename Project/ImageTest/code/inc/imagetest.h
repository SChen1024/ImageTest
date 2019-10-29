#ifndef IMAGETEST_H
#define IMAGETEST_H

#include "../stdafx.h"
#include "ui_imagetest.h"


namespace Ui {
class ImageTest;
}

class ImageTest : public QMainWindow
{
    Q_OBJECT

public:
    explicit ImageTest(QWidget *parent = nullptr);
    ~ImageTest();

private:
    Ui::ImageTest *ui;

    Menu *menu_;

    // 设置窗口内容
    // Menu

private:
    // function
    void Init();
    void Show();

    void CreateMenubar(void);   // 创建菜单栏
    void CreateLayout(void);  // 布局窗口


    void



};

#endif // IMAGETEST_H
