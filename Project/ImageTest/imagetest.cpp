#include "imagetest.h"
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
