//
// Created by denis on 20.02.2021.
//

#include "Qt/PaintHouse.h"

#include <utility>
#include <QtGui/QPainter>
#include <cmath>
#include <QtWidgets/QMessageBox>
#include "Qt/MainMenu.h"

#define MAX_WINDOW_WIDE 1400
#define MAX_WINDOW_HEIGHT 900

void PaintHouse::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event)
    QPainter paint(this);

    QColor coordLineColor(255, 0, 0, 255);

    QPen apen = QPen(coordLineColor);
    apen.setWidth(5);
    paint.setPen(apen);

    paint.drawLine(QLine(0,0,MAX_WINDOW_WIDE,0));
    paint.drawLine(QLine(0,0,0,MAX_WINDOW_HEIGHT));

    paint.drawText(QPoint(6,13), "0,0");
    for (int i = 1; i < 14; i++)
    {
        int numb = 150 * i;
        QString qString;
        qString.setNum(numb);
        paint.drawText(QPoint(6,numb - 5), qString);
        paint.drawText(QPoint(numb - 20,15), qString);
    }


    QPen pen1(Qt::black,2, Qt::SolidLine);
    paint.setPen(pen1);

    for (const auto& housePart: m_pCurrentHouse->GetHouseParts())
    {
        auto shapeDots = housePart.first->GetDots();
        shapeDots.push_back(shapeDots.front());
        if (housePart.second == IHouseShapesFabric::housePartName::CircleWindow)
        {

            for (auto i = 0; i < shapeDots.size() - 6; i++)
            {
                paint.drawLine(shapeDots[i].first, shapeDots[i].second, shapeDots[i + 1].first, shapeDots[i + 1].second);
            }

            for (int i = shapeDots.size() - 5; i < shapeDots.size() - 2; i += 2)
            {
                paint.drawLine(shapeDots[i].first, shapeDots[i].second, shapeDots[i + 1].first, shapeDots[i + 1].second);
            }

           // paint.drawLine(shapeDots[1].first, shapeDots[1].second, shapeDots[2].first, shapeDots[2].second);
           // paint.drawLine(shapeDots[3].first, shapeDots[3].second, shapeDots[4].first, shapeDots[4].second);
        }
        else if (housePart.second == IHouseShapesFabric::housePartName::Door)
        {
            paint.drawLine(shapeDots[1].first, shapeDots[1].second, shapeDots[2].first, shapeDots[2].second);
            paint.drawLine(shapeDots[2].first, shapeDots[2].second, shapeDots[3].first, shapeDots[3].second);
            paint.drawLine(shapeDots[3].first, shapeDots[3].second, shapeDots[4].first, shapeDots[4].second);
            paint.drawLine(shapeDots[4].first, shapeDots[4].second, shapeDots[1].first, shapeDots[1].second);
            paint.drawLine(shapeDots[1].first, shapeDots[1].second, shapeDots[3].first, shapeDots[3].second);
            paint.drawLine(shapeDots[2].first, shapeDots[2].second, shapeDots[4].first, shapeDots[4].second);
        }
        else
        {
            for (int i = 0; i < shapeDots.size() - 1; i++)
                paint.drawLine(shapeDots[i].first, shapeDots[i].second, shapeDots[i + 1].first, shapeDots[i + 1].second);
        }
    }
    auto maxDot = m_pCurrentHouse->GetMaxWindowSize();

    auto setWidth = MAX_MENU_WIDE + maxDot.first * 1.2;
    auto setHeight = maxDot.second * 1.2;
    if (setHeight > MAX_WINDOW_HEIGHT)
        setHeight = MAX_WINDOW_HEIGHT;
    if (setWidth > MAX_WINDOW_WIDE)
        setWidth = MAX_WINDOW_WIDE;
    m_pParent->resize(setWidth, setHeight);

    QString name = "Center (";
    std::string firstArg = std::to_string(static_cast<int>(m_pCurrentHouse->GetHouseCenter().first));
    std::string secondArg = std::to_string(static_cast<int>(m_pCurrentHouse->GetHouseCenter().second));
    name.append(firstArg.data());
    name.append(", ");
    name.append(secondArg.data());
    name.append(")");

    m_pParent->setWindowTitle(name);
}

PaintHouse::PaintHouse(std::shared_ptr<MyHouse> inHouse, QWidget *parent) {
    m_pCurrentHouse = std::move(inHouse);
    m_pParent = parent;
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void PaintHouse::setHouse(std::shared_ptr<MyHouse> inHouse) {
    if (inHouse->GetMinWindowSize().first < 0 || inHouse->GetMinWindowSize().second < 0)
    {
        QMessageBox::critical(this, "Ошибка ", "Фигура после применения изменений уйдет(полностью или частично) за границы экрана", QMessageBox::Ok);
        inHouse->GetPreviousData();
        return;
    }
    if (inHouse->GetMaxWindowSize().first >= MAX_WINDOW_WIDE - MAX_MENU_WIDE)
    {
        QMessageBox::critical(this, "Ошибка ", "Отображение фигуры превысит или будет равно максимальную ширину окна(1200 пикселей)", QMessageBox::Ok);
        inHouse->GetPreviousData();
        return;
    }
    if (inHouse->GetMaxWindowSize().second >= MAX_WINDOW_HEIGHT)
    {
        QMessageBox::critical(this, "Ошибка ", "Отображение фигуры превысит или будет равно максимальную высоту окна(900 пикселей)", QMessageBox::Ok);
        inHouse->GetPreviousData();
        return;
    }
    m_pCurrentHouse = std::move(inHouse);
    this->repaint();
}

void PaintHouse::setPreviousHouse() {
    m_pCurrentHouse->GetPreviousData();
    this->repaint();
}

