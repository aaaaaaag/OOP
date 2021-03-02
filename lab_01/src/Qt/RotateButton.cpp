//
// Created by denis on 20.02.2021.
//

#include <QtWidgets/QMessageBox>
#include "Qt/RotateButton.h"
#include "Qt/MainMenu.h"

RotateButton::RotateButton(std::shared_ptr<MyHouse> inHouse, QLineEdit *editLineDegrees, QLineEdit *xRotateCenter, QLineEdit *yRotateCenter, PaintHouse *painter, QWidget *parent) {
    m_pHouse = std::move(inHouse);
    m_pLineDegrees = editLineDegrees;
    m_pPainter = painter;
    m_pRotateCenterX = xRotateCenter;
    m_pRotateCenterY = yRotateCenter;
    m_pParent = parent;
    setText("Rotate");
    connect(this, &QPushButton::clicked, this, &RotateButton::RotateHouse);
}

void RotateButton::RotateHouse() {
    auto degreesLine = m_pLineDegrees->text().toStdString();
    auto xLine = m_pRotateCenterX->text().toStdString();
    auto yLine = m_pRotateCenterY->text().toStdString();


    if (m_pHouse) {
        try {
            std::stoi(degreesLine);
        }
        catch (std::invalid_argument) {
            QMessageBox::critical(this, "Ошибка ", "Число градусов должно быть целым", QMessageBox::Ok);
            return;
        }
        try {
            std::stof(xLine);
        }
        catch (std::invalid_argument) {
            QMessageBox::critical(this, "Ошибка ", "Поле центра поворота координаты Х не содержит целое число", QMessageBox::Ok);
            return;
        }
        try {
            std::stof(yLine);
        }
        catch (std::invalid_argument) {
            QMessageBox::critical(this, "Ошибка ", "Поле центра поворота координаты Y не содержит целое число", QMessageBox::Ok);
            return;
        }
        auto dot = std::pair<float, float>(std::stof(xLine), std::stof(yLine));
        auto previousSize = m_pHouse->GetMaxWindowSize();
        m_pHouse->Rotate(std::stoi(degreesLine), dot);
        m_pPainter->setHouse(m_pHouse);
        m_pParent->resize(MAX_MENU_WIDE + previousSize.first * 1.1, previousSize.second * 1.1);
        int i = 0;
    }
}
