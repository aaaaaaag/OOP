//
// Created by denis on 12.03.2021.
//

#include <Errors.h>
#include "Qt/CanvasStruct.h"

int initCanvas(CanvasStruct& canvasStruct)
{
    canvasStruct.canvas = new QGraphicsView;
    canvasStruct.height = 600;
    canvasStruct.width = 600;
    canvasStruct.canvas->setMinimumSize(canvasStruct.width, canvasStruct.height);
    canvasStruct.canvas->setMaximumSize(canvasStruct.width, canvasStruct.height);

    auto scene = new QGraphicsScene;
    canvasStruct.mainPen = new QPen(QColor(0, 0, 0));
    canvasStruct.canvas->setScene(scene);
    return OK;
}

int drawLine(CanvasStruct& canvasStruct, dot from, dot to)
{
    canvasStruct.canvas->scene()->addLine(from.coordX, from.coordY, to.coordX, to.coordY, *canvasStruct.mainPen);
    return OK;
}

int clear(CanvasStruct& canvasStruct)
{
    canvasStruct.canvas->scene()->clear();
    return OK;
}