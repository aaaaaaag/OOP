//
// Created by denis on 08.03.2021.
//

#ifndef LAB_01_OOP_MOVESHAPEUI_H
#define LAB_01_OOP_MOVESHAPEUI_H

#include <memory>
#include "QWidget"
#include "QVBoxLayout"
#include "ActionSlots.h"

class MoveShapeUI: public QVBoxLayout{
public:

    MoveShapeUI(const std::shared_ptr<ActionSlots>& inActionSlots);

    QLineEdit* GetXLine();

    QLineEdit* GetYLine();

    QLineEdit* GetZLine();

private:

    QLineEdit *m_pXMoveLine;
    QLineEdit *m_pYMoveLine;
    QLineEdit *m_pZMoveLine;
};


#endif //LAB_01_OOP_MOVESHAPEUI_H
