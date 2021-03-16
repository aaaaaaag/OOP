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

    formX->addRow("X koef: ", m_pXZoomLine);
    formY->addRow("Y koef: ", m_pYZoomLine);
    formZ->addRow("Z koef: ", m_pZZoomLine);

    this->addLayout(formX);
    this->addLayout(formY);
    this->addLayout(formZ);

    auto button = new ZoomButton(inActionSlots, this);
    this->addWidget(button);

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
