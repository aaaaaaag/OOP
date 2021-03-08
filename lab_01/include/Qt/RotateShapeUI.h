//
// Created by denis on 08.03.2021.
//

#ifndef LAB_01_OOP_ROTATESHAPEUI_H
#define LAB_01_OOP_ROTATESHAPEUI_H

#include <memory>
#include <QtWidgets/QLineEdit>
#include "QWidget"
#include "QVBoxLayout"
#include "ActionSlots.h"
#include "PaintHouse.h"

class RotateShapeUI: public QVBoxLayout {
public:

    RotateShapeUI(const std::shared_ptr<ActionSlots>& inActionSlots, PaintHouse *painter);

    QLineEdit* GetXLine();

    QLineEdit* GetYLine();

    QLineEdit* GetZLine();

private:

    QLineEdit *m_pXRotateLine;
    QLineEdit *m_pYRotateLine;
    QLineEdit *m_pZRotateLine;
};


#endif //LAB_01_OOP_ROTATESHAPEUI_H
