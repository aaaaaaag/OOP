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
    connect(this, &QPushButton::clicked, m_pActionSlots.get(), &ActionSlots::Rotate);
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
        QMessageBox::critical(this, "Ошибка ", "Поле смещения координаты содержит не целое число.", QMessageBox::Ok);
        return;
    }
    auto utilData = m_pActionSlots->GetUtilData();
    utilData->updateParams.rotateCoords.xRotateDegrees = std::stoi(xLine);
    utilData->updateParams.rotateCoords.yRotateDegrees = std::stoi(yLine);
    utilData->updateParams.rotateCoords.zRotateDegrees = std::stoi(zLine);
    m_pActionSlots->SetUtilsData(utilData);
}


