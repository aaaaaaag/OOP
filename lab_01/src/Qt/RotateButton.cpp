//
// Created by denis on 20.02.2021.
//

#include <QtWidgets/QMessageBox>
#include <utility>
#include "Qt/RotateButton.h"

RotateButton::RotateButton(std::shared_ptr<ActionSlots> inActionSlots, RotateShapeUI *inShape) {
    m_pActionSlots = std::move(inActionSlots);
    m_pShapeUI = inShape;
    setText("Rotate");
    //UpdateUtilData();
    connect(this, &QPushButton::clicked, this, &RotateButton::UpdateUtilData);
}

void RotateButton::UpdateUtilData() {
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
        QMessageBox::critical(this, "Ошибка ", "Поле поворота координат содержит не целое число.", QMessageBox::Ok);
        return;
    }
    //auto utilData = m_pActionSlots->GetUtilData();
    m_pActionSlots->m_data->rotateCoords.xRotateDegrees = std::stoi(xLine);
    m_pActionSlots->m_data->rotateCoords.yRotateDegrees = std::stoi(yLine);
    m_pActionSlots->m_data->rotateCoords.zRotateDegrees = std::stoi(zLine);
    //m_pActionSlots->SetUtilsData(utilData);
    m_pActionSlots->Rotate();
}


