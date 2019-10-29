#include "../inc/menu.h"

Menu::Menu()
{
    Menu_File();
}

void Menu::Menu_File(void)
{

    QAction *Act_file_new = new QAction(QIcon("../Image/file/New.png"), tr("新建"), this);
    Act_file_new->setShortcut(Qt::Key_Control & Qt::Key_N);
    //Act_file_new->setStatusTip(tr("新建图像"));
    connect(Act_file_new, SIGNAL(triggered()), this, SLOT(File_new()));

    QAction *Act_file_open = new QAction(QIcon("../Image/file/Open.png"), tr("打开"), this);
    Act_file_open->setShortcuts(QKeySequence::Open);
    //Act_file_open->setStatusTip(tr("打开图像"));
    connect(Act_file_open, SIGNAL(triggered()), this, SLOT(File_open()));

    QAction *Act_file_save = new QAction(QIcon("../Image/file/Save.png"), tr("保存"), this);
    Act_file_save->setShortcuts(QKeySequence::Save);
    //Act_file_save->setStatusTip(tr("保存图像"));
    connect(Act_file_save, SIGNAL(triggered()), this, SLOT(File_save()));

    QAction *Act_file_saveas = new QAction(QIcon("../Image/file/SaveAs.png"), tr("另存为"), this);
    Act_file_saveas->setShortcuts(QKeySequence::SaveAs);
    //Act_file_saveas->setStatusTip(tr("图像另存为"));
    connect(Act_file_saveas, SIGNAL(triggered()), this, SLOT(File_saveas()));

    QAction *Act_file_close = new QAction(QIcon("../Image/file/Close.png"), tr("关闭"), this);
    Act_file_close->setShortcuts(QKeySequence::Close);
    //Act_file_close->setStatusTip(tr("关闭软件"));

    QMenu *file = addMenu(tr("文件"));
    file->addAction(Act_file_new);
    file->addAction(Act_file_open);
    file->addAction(Act_file_save);
    file->addAction(Act_file_saveas);
    file->addSeparator();						//添加一个分割器
    file->addAction(Act_file_close);

}
