//
// Created by denis on 02.03.2021.
//

#ifndef LAB_01_OOP_LOADFILEBUTTON_H
#define LAB_01_OOP_LOADFILEBUTTON_H

#include "QWidget"
#include "QPushButton"
#include "DotStruct.h"
#include "memory"
#include "ActionSlots.h"

class LoadFileButton: public QPushButton {
public:

    explicit LoadFileButton(std::shared_ptr<ActionSlots> actionsDot);

private slots:

    void Load();

private:

    std::shared_ptr<ActionSlots> m_pActionsDot;

};



#endif //LAB_01_OOP_LOADFILEBUTTON_H
