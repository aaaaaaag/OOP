//
// Created by denis on 20.02.2021.
//

#include "Qt/MoveButton.h"

#include <utility>
#include <QtWidgets/QMessageBox>

MoveButton::MoveButton(std::shared_ptr<MyHouse> inHouse, QLineEdit *editLineX, QLineEdit *editLineY, PaintHouse *painter) {
    m_pHouse = std::move(inHouse);
    m_pLineX = editLineX;
    m_pLineY = editLineY;
    m_pPainter = painter;
    setText("Move");
    connect(this, &QPushButton::clicked, this, &MoveButton::MoveHouse);
}

void MoveButton::MoveHouse() {
    auto xLine = m_pLineX->text().toStdString();
    auto yLine = m_pLineY->text().toStdString();

    if (m_pHouse) {
        try {
            std::stoi(xLine);
        }
        catch (std::invalid_argument) {
            QMessageBox::critical(this, "Ошибка ", "Поле смещения координаты Х содержит не целое число.", QMessageBox::Ok);
            return;
        }
        try {
            std::stoi(yLine);
        }
        catch (std::invalid_argument) {
            QMessageBox::critical(this, "Ошибка ", "Поле смещения координаты Y содержит не целое число.", QMessageBox::Ok);
            return;
        }
        m_pHouse->Move(std::stoi(xLine), std::stoi(yLine));
        m_pPainter->setHouse(m_pHouse);
    }
}
