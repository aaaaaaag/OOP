//
// Created by denis on 08.03.2021.
//

#include <QtWidgets/QFormLayout>
#include "RotateShapeUI.h"
#include "RotateButton.h"

RotateShapeUI::RotateShapeUI(const std::shared_ptr<ActionSlots> &inActionSlots, PaintHouse *painter) {
    m_pXRotateLine = new QLineEdit;
    m_pYRotateLine = new QLineEdit;
    m_pZRotateLine = new QLineEdit;

    auto *formX = new QFormLayout();
    auto *formY = new QFormLayout();
    auto *formZ = new QFormLayout();

    formX->addRow("X degrees: ", m_pXRotateLine);
    formY->addRow("Y degrees: ", m_pYRotateLine);
    formZ->addRow("Z degrees: ", m_pZRotateLine);

    this->addLayout(formX);
    this->addLayout(formY);
    this->addLayout(formZ);

    auto button = std::make_shared<RotateButton>(inActionSlots, this);
}

QLineEdit *RotateShapeUI::GetXLine() {
    return m_pXRotateLine;
}

QLineEdit *RotateShapeUI::GetYLine() {
    return m_pYRotateLine;
}

QLineEdit *RotateShapeUI::GetZLine() {
    return m_pZRotateLine;
}
