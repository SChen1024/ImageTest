#include "../inc/imagetest.h"
#include "ui_imagetest.h"


ImageTest::ImageTest(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ImageTest)
{
    ui->setupUi(this);
}

ImageTest::~ImageTest()
{
    delete ui;
}

// 初始化窗口显示
void ImageTest::Init(void)
{

}
