//
// Created by denis on 20.02.2021.
//

#ifndef LAB_01_ROTATEBUTTON_H
#define LAB_01_ROTATEBUTTON_H

#include <memory>
#include <MyHouse.h>
#include <QtWidgets/QLineEdit>
#include "QPushButton"
#include "PaintHouse.h"

class RotateButton: public QPushButton {
public:

    RotateButton(std::shared_ptr<MyHouse> inHouse, QLineEdit *editLineDegrees, QLineEdit *xRotateCenter, QLineEdit *yRotateCenter, PaintHouse *painter, QWidget *parent);


private slots:

    void RotateHouse();

private:

    QWidget *m_pParent;
    PaintHouse *m_pPainter;
    std::shared_ptr<MyHouse> m_pHouse;
    QLineEdit *m_pLineDegrees;
    QLineEdit *m_pRotateCenterX;
    QLineEdit *m_pRotateCenterY;
};


#endif //LAB_01_ROTATEBUTTON_H
