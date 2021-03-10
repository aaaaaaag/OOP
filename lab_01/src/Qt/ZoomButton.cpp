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
    //UpdateUtilData();
    connect(this, &QPushButton::clicked, this, &ZoomButton::UpdateUtilData);
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
    //auto utilData = m_pActionSlots->GetUtilData();
    m_pActionSlots->m_data->updateParams.scaleCoords.xScaleKoef = std::stoi(xLine);
    m_pActionSlots->m_data->updateParams.scaleCoords.yScaleKoef = std::stoi(yLine);
    m_pActionSlots->m_data->updateParams.scaleCoords.zScaleKoef = std::stoi(zLine);
    //m_pActionSlots->SetUtilsData(utilData);
    m_pActionSlots->Scale();
}
