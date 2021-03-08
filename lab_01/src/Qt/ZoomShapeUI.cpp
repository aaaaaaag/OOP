//
// Created by denis on 08.03.2021.
//

#include <QtWidgets/QFormLayout>
#include "Qt/ZoomShapeUI.h"
#include "Qt/ZoomButton.h"

ZoomShapeUI::ZoomShapeUI(const std::shared_ptr<ActionSlots> &inActionSlots) {
    m_pXZoomLine = new QLineEdit;
    m_pYZoomLine = new QLineEdit;
    m_pZZoomLine = new QLineEdit;

    auto *formX = new QFormLayout();
    auto *formY = new QFormLayout();
    auto *formZ = new QFormLayout();

    formX->addRow("X degrees: ", m_pXZoomLine);
    formY->addRow("Y degrees: ", m_pYZoomLine);
    formZ->addRow("Z degrees: ", m_pZZoomLine);

    this->addLayout(formX);
    this->addLayout(formY);
    this->addLayout(formZ);

    auto button = std::make_shared<ZoomButton>(inActionSlots, this);
}

QLineEdit *ZoomShapeUI::GetXLine() {
    return m_pXZoomLine;
}

QLineEdit *ZoomShapeUI::GetYLine() {
    return m_pYZoomLine;
}

QLineEdit *ZoomShapeUI::GetZLine() {
    return m_pZZoomLine;
}
