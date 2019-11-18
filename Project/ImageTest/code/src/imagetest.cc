#include "../inc/imagetest.h"

#include <QtWidgets>

/**
 * @fn  ImageTest::ImageTest(QWidget *parent)
 *
 * @brief   Initializes a new instance of the ImageTest class
 *
 * @author  IRIS_Chen
 * @date    2019/11/14
 *
 * @param [in,out]  parent  If non-null, the parent
 */

ImageTest::ImageTest(QWidget *parent) :
    QMainWindow(parent),
    mTextEdit_(new QTextEdit)
{    
    CreateMenubar();
    CreateDockWindows();

    setCentralWidget(mTextEdit_);
    CreateMain();

    // this->setMinimumSize(QSize(960, 540));  // 设置 窗口尺寸

    setWindowTitle(tr("Image Test Lab"));
    setUnifiedTitleAndToolBarOnMac(true);
}

/**
 * @fn  void ImageTest::about()
 *
 * @brief   关于软件信息
 *
 * @author  IRIS_Chen
 * @date    2019/11/14
 */

void ImageTest::about()
{
   QMessageBox::about(this, tr("About Dock Widgets"),
            tr("Image Test Platform to test Algorithm  "
               "<a href='https://github.com/SChen1024/ImageTest'>See URL</a> " ));
}

/**
 * @fn  void ImageTest::SystemInfo()
 *
 * @brief   显示系统相关信息
 *
 * @author  IRIS_Chen
 * @date    2019/11/14
 */

void ImageTest::SystemInfo()
{
    QMessageBox::about(this, tr("About Dock Widgets"),
                       tr("Image Test Platform to test Algorithm  "
                          "<a href='https://github.com/SChen1024/ImageTest'>See URL</a> "));
}

/**
 * @fn  void ImageTest::CreateMenubar(void)
 *
 * @brief   创建菜单栏
 *
 * @author  IRIS_Chen
 * @date    2019/11/14
 */

void ImageTest::CreateMenubar(void)
{
    // 文件菜单
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    
    {
        // 添加文件
        QAction *newLetterAct = new QAction(tr("&New"), this);
        newLetterAct->setShortcuts(QKeySequence::New);
        newLetterAct->setStatusTip(tr("Create a blank image"));
        fileMenu->addAction(newLetterAct);

        // 打开
        QAction *menu_new = new QAction(tr("&Open"), this);
        menu_new->setShortcuts(QKeySequence::Open);
        menu_new->setStatusTip("Open File");
        fileMenu->addAction(menu_new);

        // 保存
        QAction *saveAct = new QAction(tr("&Save..."), this);
        saveAct->setShortcuts(QKeySequence::Save);
        saveAct->setStatusTip(tr("Save the current file"));
        fileMenu->addAction(saveAct);

        // 分割线
        fileMenu->addSeparator();

        // 退出
        QAction *quitAct = fileMenu->addAction(tr("&Quit"), this, &QWidget::close);
        quitAct->setShortcuts(QKeySequence::Quit);
        quitAct->setStatusTip(tr("Quit the application"));
    }


    // 编辑菜单
    QMenu *editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(tr("&Transpose"));
    editMenu->addAction(tr("&Rotate 90"));
    editMenu->addAction(tr("&Rotate 180"));
    editMenu->addAction(tr("&Rotate 270"));
    editMenu->addAction(tr("&FlipLeft2Right"));
    editMenu->addAction(tr("&FlipTop2Bottom"));

    // 窗口显示
    mMenu_ = menuBar()->addMenu(tr("&View"));

    // 测试 
    QMenu *testMenu = menuBar()->addMenu(tr("&Test"));
    // 帮助
    QMenu *helpMenu = menuBar()->addMenu(tr("&Help"));
    
    {
        // 本机信息
        QAction *systemAct = helpMenu->addAction(tr("&SystemInfo"), this, &ImageTest::SystemInfo);
        systemAct->setStatusTip(tr("Show the System Info"));

        // 关于本软件
        QAction *aboutAct = helpMenu->addAction(tr("&About"), this, &ImageTest::about);
        aboutAct->setStatusTip(tr("Show the application's About box"));

        // 关于QT
        QAction *aboutQtAct = helpMenu->addAction(tr("About &Qt"), qApp, &QApplication::aboutQt);
        aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
    }
}

// 创建 Dock windows 显示
void ImageTest::CreateDockWindows(void)
{

    QDockWidget *dock = new QDockWidget(tr("Properties"), this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    mCustomerWindow_ = new QListWidget(dock);
    mCustomerWindow_->addItems(QStringList()
           << tr("Test item 1")
           << tr("Test item 2")
           << tr("Test item 3")
           << tr("Test item 4")
           << tr("Test item 5")
           << tr("Test item 6"));
    dock->setWidget(mCustomerWindow_);
    addDockWidget(Qt::RightDockWidgetArea, dock);
    mMenu_->addAction(dock->toggleViewAction());

}

void ImageTest::CreateMain()
{
    mTextEdit_->clear();

    QTextCursor cursor(mTextEdit_->textCursor());
    cursor.movePosition(QTextCursor::Start);
    QTextFrame *topFrame = cursor.currentFrame();
    QTextFrameFormat topFrameFormat = topFrame->frameFormat();
    topFrameFormat.setPadding(16);
    topFrame->setFrameFormat(topFrameFormat);

    QTextCharFormat textFormat;
    QTextCharFormat boldFormat;
    boldFormat.setFontWeight(QFont::Bold);
    QTextCharFormat italicFormat;
    italicFormat.setFontItalic(true);

    QTextTableFormat tableFormat;
    tableFormat.setBorder(1);
    tableFormat.setCellPadding(16);
    tableFormat.setAlignment(Qt::AlignRight);
    cursor.insertTable(1, 1, tableFormat);
    cursor.insertText("The Firm", boldFormat);
    cursor.insertBlock();
    cursor.insertText("321 City Street", textFormat);
    cursor.insertBlock();
    cursor.insertText("Industry Park");
    cursor.insertBlock();
    cursor.insertText("Some Country");
    cursor.setPosition(topFrame->lastPosition());
    cursor.insertText(QDate::currentDate().toString("d MMMM yyyy"), textFormat);
    cursor.insertBlock();
    cursor.insertBlock();
    cursor.insertText("Dear ", textFormat);
    cursor.insertText("NAME", italicFormat);
    cursor.insertText(",", textFormat);
    for (int i = 0; i < 3; ++i)
        cursor.insertBlock();
    cursor.insertText(tr("Yours sincerely,"), textFormat);
    for (int i = 0; i < 3; ++i)
        cursor.insertBlock();
    cursor.insertText("The Boss", textFormat);
    cursor.insertBlock();
    cursor.insertText("ADDRESS", italicFormat);

}
