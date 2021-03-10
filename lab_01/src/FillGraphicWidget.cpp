//
// Created by denis on 09.03.2021.
//

#include <QMessageBox>
#include "FillGraphicWidget.h"

void FillGraphicsWidget(CanvasWidget *canvasWidget, mainShape_t *shape)
{
    if (shape->coordsNumb <= 0 || shape->shapeCoords == nullptr || !canvasWidget)
    {
        QMessageBox::critical(nullptr, "Ошибка ", "Нет фигуры для совершения действий. Загрузите ее", QMessageBox::Ok);
        return;
    }
    canvasWidget->Clear();
    for (int i = 0; i < shape->coordsNumb; i++)
    {
        auto curDot = shape->shapeCoords[i];
        for (int j = 0; j < curDot.linksNumb; j++)
        {
            if (curDot.linkNodesNumbers[j] != -1)
                canvasWidget->DrawLine(curDot.coords.coordX, curDot.coords.coordY,
                                   shape->shapeCoords[curDot.linkNodesNumbers[j]].coords.coordX, shape->shapeCoords[curDot.linkNodesNumbers[j]].coords.coordY);
        }
    }
}