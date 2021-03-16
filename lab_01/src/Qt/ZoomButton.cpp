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
    connect(this, &QPushButton::clicked, this, &ZoomButton::UpdateUtilData);
}

int SetScaleCoords(scaleCoords_t& scaleCoords, int xLine, int yLine, int zLine)
{
    scaleCoords.xScaleKoef = xLine;
    scaleCoords.yScaleKoef = yLine;
    scaleCoords.zScaleKoef = zLine;
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
    auto data = m_pActionSlots->m_data;
    SetScaleCoords(data->scaleCoords, std::stoi(xLine), std::stoi(yLine), std::stoi(zLine));
    m_pActionSlots->Scale();
}
