//
// Created by denis on 20.02.2021.
//

#include "Qt/ZoomButton.h"

#include <utility>
#include "QMessageBox"

ZoomButton::ZoomButton(std::shared_ptr<ActionSlots> inActionSlots, ZoomShapeUI* inShape)
{
    m_pActionSlots = std::move(inActionSlots);
    m_pShapeUI = inShape;
    setText("Zoom");
    UpdateUtilData();
    connect(this, &QPushButton::clicked, m_pActionSlots.get(), &ActionSlots::Scale);
}

void ZoomButton::UpdateUtilData() {
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
        QMessageBox::critical(this, "Ошибка ", "Поле коэфециентов масштабирования не содержит целое число.", QMessageBox::Ok);
        return;
    }
    auto utilData = m_pActionSlots->GetUtilData();
    utilData->updateParams.scaleCoords.xScaleKoef = std::stoi(xLine);
    utilData->updateParams.scaleCoords.yScaleKoef = std::stoi(yLine);
    utilData->updateParams.scaleCoords.zScaleKoef = std::stoi(zLine);
    m_pActionSlots->SetUtilsData(utilData);
}
