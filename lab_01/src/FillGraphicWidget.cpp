//
// Created by denis on 09.03.2021.
//

#include <QMessageBox>
#include "FillGraphicWidget.h"
#include "Errors.h"

int FillGraphicsWidget(CanvasWidget *canvasWidget, mainShape_t *shape)
{
    //QMessageBox::critical(nullptr, "Ошибка ", "Нет фигуры для совершения действий. Загрузите ее", QMessageBox::Ok);
    if (shape->coordsNumb <= 0 || shape->shapeCoords == nullptr || !canvasWidget)
        return INCORRECT_ARG;
    canvasWidget->Clear();
    for (int i = 0; i < shape->coordsNumb; i++)
    {
        auto curDot = shape->shapeCoords[i];
        for (int j = 0; j < curDot.linksNumb; j++)
        {
            if (curDot.linkNodesNumbers[j] != -1)
                canvasWidget->DrawLine(curDot.coords, shape->shapeCoords[curDot.linkNodesNumbers[j]].coords);
        }
    }
    return OK;
}