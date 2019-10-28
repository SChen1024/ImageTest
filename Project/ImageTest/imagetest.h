#ifndef IMAGETEST_H
#define IMAGETEST_H

#include <QMainWindow>

#include "opencv2/core.hpp"

namespace Ui {
class ImageTest;
}

class ImageTest : public QMainWindow
{
    Q_OBJECT

public:
    explicit ImageTest(QWidget *parent = 0);
    ~ImageTest();

private:
    Ui::ImageTest *ui;
};

#endif // IMAGETEST_H
