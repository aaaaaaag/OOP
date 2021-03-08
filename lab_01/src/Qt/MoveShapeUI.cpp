//
// Created by denis on 08.03.2021.
//

#include <QtWidgets/QLineEdit>
#include <QtWidgets/QFormLayout>
#include "Qt/MoveShapeUI.h"
#include "Qt/MoveButton.h"


MoveShapeUI::MoveShapeUI(const std::shared_ptr<ActionSlots>& inActionSlots) {
    m_pXMoveLine = new QLineEdit;
    m_pYMoveLine = new QLineEdit;
    m_pZMoveLine = new QLineEdit;

    auto *formX = new QFormLayout();
    auto *formY = new QFormLayout();
    auto *formZ = new QFormLayout();

    formX->addRow("X: ", m_pXMoveLine);
    formY->addRow("Y: ", m_pYMoveLine);
    formZ->addRow("Z: ", m_pZMoveLine);

    this->addLayout(formX);
    this->addLayout(formY);
    this->addLayout(formZ);

    auto button = std::make_shared<MoveButton>(inActionSlots, this);
}

QLineEdit *MoveShapeUI::GetXLine() {
    return m_pXMoveLine;
}

QLineEdit *MoveShapeUI::GetYLine() {
    return m_pYMoveLine;
}

QLineEdit *MoveShapeUI::GetZLine() {
    return m_pZMoveLine;
}
