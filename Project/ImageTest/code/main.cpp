#include "imagetest.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImageTest w;
    w.show();

    return a.exec();
}
