//
// Created by denis on 20.02.2021.
//

#ifndef LAB_01_MOVEBUTTON_H
#define LAB_01_MOVEBUTTON_H

#include "QPushButton"
#include "QLineEdit"
#include "MyHouse.h"
#include "PaintHouse.h"

class MoveButton: public QPushButton {
public:

    MoveButton(std::shared_ptr<MyHouse> inHouse, QLineEdit *editLineX, QLineEdit *editLineY, PaintHouse *painter);

private slots:

    void MoveHouse();

private:

    std::shared_ptr<MyHouse> m_pHouse;
    QLineEdit *m_pLineX;
    QLineEdit *m_pLineY;
    PaintHouse *m_pPainter;
};


#endif //LAB_01_MOVEBUTTON_H
