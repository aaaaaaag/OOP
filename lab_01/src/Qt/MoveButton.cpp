//
// Created by denis on 20.02.2021.
//

#include "Qt/MoveButton.h"

#include <utility>
#include <QtWidgets/QMessageBox>

MoveButton::MoveButton(std::shared_ptr<ActionSlots> inActionSlots, MoveShapeUI* inShape) {
    m_pActionSlots = std::move(inActionSlots);
    m_pShapeUI = inShape;
    setText("Move");
    UpdateUtilData();
    connect(this, &QPushButton::clicked, m_pActionSlots.get(), &ActionSlots::Move);
}

void MoveButton::UpdateUtilData() {
    auto xLine = m_pShapeUI->GetXLine()->text().toStdString();
    auto yLine = m_pShapeUI->GetYLine()->text().toStdString();
    auto zLine = m_pShapeUI->GetZLine()->text().toStdString();
    try {
        std::stoi(xLine);
        std::stoi(yLine);
        std::stoi(zLine);
    }
    catch (std::invalid_argument)
    {
        QMessageBox::critical(this, "Ошибка ", "Поле смещения координаты содержит не целое число.", QMessageBox::Ok);
        return;
    }
    auto utilData = m_pActionSlots->GetUtilData();
    utilData->updateParams.moveCoords.xMove = std::stoi(xLine);
    utilData->updateParams.moveCoords.yMove = std::stoi(yLine);
    utilData->updateParams.moveCoords.zMove = std::stoi(zLine);
    m_pActionSlots->SetUtilsData(utilData);
}