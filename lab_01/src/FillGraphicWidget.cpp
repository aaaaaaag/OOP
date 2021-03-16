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
    for (int i = 0; i < shape.linksNumb; i++)
    {
        auto curLink = shape.linkNodesNumbers[i];
        auto DotFrom = shape.shapeCoords[curLink.from];
        auto DotTo = shape.shapeCoords[curLink.to];
        error = drawLine(canvasWidget, DotFrom, DotTo);
    }
    return error;
}