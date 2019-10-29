#ifndef CODEINCMENU_H
#define CODEINCMENU_H

#include "../stdafx.h"

class Menu : public QMenuBar
{
public:
    Menu();

private:
    // 设置菜单的显示
    void Menu_File(void);
};

#endif // CODEINCMENU_H
