//
// Created by denis on 20.02.2021.
//

#include "Qt/ZoomButton.h"
#include "QMessageBox"

ZoomButton::ZoomButton(std::shared_ptr<MyHouse> inHouse, QLineEdit *editLineX, QLineEdit *editLineY, QLineEdit *xZoomCenter, QLineEdit *yZoomCenter, PaintHouse *painter)
{
    m_pHouse = std::move(inHouse);
    m_pLineZoomX = editLineX;
    m_pLineZoomY = editLineY;
    m_pPainter = painter;
    m_pXCenter = xZoomCenter;
    m_pYCenter = yZoomCenter;
    setText("Zoom");
    connect(this, &QPushButton::clicked, this, &ZoomButton::ZoomHouse);
}

void ZoomButton::ZoomHouse() {
    auto zoomX = m_pLineZoomX->text().toStdString();
    auto zoomY = m_pLineZoomY->text().toStdString();
    auto xLine = m_pXCenter->text().toStdString();
    auto yLine = m_pYCenter->text().toStdString();


    if (m_pHouse) {
        try {
            std::stof(zoomX);
        }
        catch (std::invalid_argument) {
            QMessageBox::critical(this, "Ошибка ", "Неверный ввод коэффициента масштабирования по X", QMessageBox::Ok);
            return;
        }
        try {
            std::stof(zoomY);
        }
        catch (std::invalid_argument) {
            QMessageBox::critical(this, "Ошибка ", "Неверный ввод коэффициента масштабирования по Y", QMessageBox::Ok);
            return;
        }
        try {
            std::stof(xLine);
        }
        catch (std::invalid_argument) {
            QMessageBox::critical(this, "Ошибка ", "Поле центра масштабирования координаты Х не содержит целое число", QMessageBox::Ok);
            return;
        }
        try {
            std::stof(yLine);
        }
        catch (std::invalid_argument) {
            QMessageBox::critical(this, "Ошибка ", "Поле центра масштабирования координаты Y не содержит целое число", QMessageBox::Ok);
            return;
        }
        auto dot = std::pair<float, float>(std::stof(xLine), std::stof(yLine));
        m_pHouse->Zoom(std::stof(zoomX), std::stof(zoomY), dot);
        if (m_pHouse->GetMaxWindowSize().first - m_pHouse->GetMinWindowSize().first < 10 || m_pHouse->GetMaxWindowSize().second - m_pHouse->GetMinWindowSize().second <= 10)
        {
            m_pHouse->GetPreviousData();
            QMessageBox::critical(this, "Ошибка ", "Невозможно отобразить такой маленький объект", QMessageBox::Ok);
            return;
        }
        m_pPainter->setHouse(m_pHouse);
    }
}
