//
// Created by denis on 20.02.2021.
//

#ifndef LAB_01_MAINMENU_H
#define LAB_01_MAINMENU_H

#include "QWidget"
#include "DotStruct.h"
#include "ActionSlots.h"
#include "memory"
#define MAX_MENU_WIDE 200
#define MAX_MENU_HEIGHT 300

class MainMenu: public QWidget {
public:

    explicit MainMenu(const std::shared_ptr<ActionSlots>& inActionSlots);

};


#endif //LAB_01_MAINMENU_H
