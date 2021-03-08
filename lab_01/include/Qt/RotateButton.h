//
// Created by denis on 20.02.2021.
//

#ifndef LAB_01_ROTATEBUTTON_H
#define LAB_01_ROTATEBUTTON_H

#include <memory>
#include <QtWidgets/QLineEdit>
#include "QPushButton"
#include "PaintHouse.h"
#include "ActionSlots.h"
#include "RotateShapeUI.h"

class RotateButton: public QPushButton {
public:

    RotateButton(std::shared_ptr<ActionSlots> inActionSlots, RotateShapeUI* inShape);

private:
    void UpdateUtilData();

    std::shared_ptr<ActionSlots> m_pActionSlots;
    RotateShapeUI *m_pShapeUI;
};


#endif //LAB_01_ROTATEBUTTON_H
