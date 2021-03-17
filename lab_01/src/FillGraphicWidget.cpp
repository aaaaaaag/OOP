//
// Created by denis on 09.03.2021.
//

#include "FillGraphicWidget.h"
#include "Errors.h"

int FillGraphicsWidget(CanvasStruct& canvasWidget, const dotsStruct& dots, const linksStruct& links)
{
    if (dots.coordsNumb <= 0 || dots.shapeCoords == nullptr || !canvasWidget.canvas) return INCORRECT_ARG;
    int error = clear(canvasWidget);
    for (int i = 0; i < links.linksNumb && error == OK; i++)
    {
        auto curLink = links.linkNodesNumbers[i];
        auto DotFrom = dots.shapeCoords[curLink.from];
        auto DotTo = dots.shapeCoords[curLink.to];
        error = drawLine(canvasWidget, DotFrom, DotTo);
    }
    return error;
}