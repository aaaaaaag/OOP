//
// Created by denis on 20.02.2021.
//

#ifndef LAB_01_MOVEBUTTON_H
#define LAB_01_MOVEBUTTON_H

#include "QPushButton"
#include "QLineEdit"
#include "PaintHouse.h"
#include "ActionSlots.h"
#include "MoveShapeUI.h"
#include "memory"

class MoveButton: public QPushButton {
public:

    MoveButton(std::shared_ptr<ActionSlots> inActionSlots, MoveShapeUI* inShape);

private:

    void UpdateUtilData();

    std::shared_ptr<ActionSlots> m_pActionSlots;
    MoveShapeUI *m_pShapeUI;
    PaintHouse *m_pPainter;
};


#endif //LAB_01_MOVEBUTTON_H
