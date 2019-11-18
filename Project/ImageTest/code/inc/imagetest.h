#ifndef IMAGETEST_H
#define IMAGETEST_H

#include "../stdafx.h"
#include <QMainWindow>


class QAction;
class QListWidget;
class QMenu;
class QTextEdit;

/**
 * @class   ImageTest imagetest.h code\inc\imagetest.h
 *
 * @brief   An image test.
 *
 * @author  IRIS_Chen
 * @date    2019/11/14
 */

class ImageTest : public QMainWindow
{
    Q_OBJECT

public:
    explicit ImageTest(QWidget *parent = nullptr);

private slots:
    void about();
    void SystemInfo();  

private:
    void CreateMenubar();
    void CreateDockWindows();   
    void CreateMain();  // 主要显示窗体


    QTextEdit *mTextEdit_;
    QListWidget *mCustomerWindow_;

    QMenu *mMenu_;

};

#endif // IMAGETEST_H
