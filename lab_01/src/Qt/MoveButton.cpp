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
    //UpdateUtilData();
    connect(this, &QPushButton::clicked, this, &MoveButton::UpdateUtilData);
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
    //auto utilData = m_pActionSlots->GetUtilData();
    m_pActionSlots->m_data->updateParams.moveCoords.xMove = std::stoi(xLine);
    m_pActionSlots->m_data->updateParams.moveCoords.yMove = std::stoi(yLine);
    m_pActionSlots->m_data->updateParams.moveCoords.zMove = std::stoi(zLine);
    //m_pActionSlots->SetUtilsData(utilData);
    m_pActionSlots->Move();
}