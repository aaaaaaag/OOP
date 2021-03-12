//
// Created by denis on 09.03.2021.
//

#include "FillGraphicWidget.h"
#include "Errors.h"

int FillGraphicsWidget(CanvasStruct& canvasWidget, mainShape_t shape)
{
    //QMessageBox::critical(nullptr, "Ошибка ", "Нет фигуры для совершения действий. Загрузите ее", QMessageBox::Ok);
    int error = OK;
    if (shape.coordsNumb <= 0 || shape.shapeCoords == nullptr || !canvasWidget.canvas)
        return INCORRECT_ARG;
    clear(canvasWidget);
    for (int i = 0; i < shape.coordsNumb; i++)
    {
        auto curDot = shape.shapeCoords[i];
        for (int j = 0; j < curDot.linksNumb; j++)
        {
            if (curDot.linkNodesNumbers[j] != -1 && error == OK)
                error = drawLine(canvasWidget, curDot.coords, shape.shapeCoords[curDot.linkNodesNumbers[j]].coords);
        }
    }
    return error;
}