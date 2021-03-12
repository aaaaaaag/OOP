//
// Created by denis on 12.03.2021.
//

#ifndef LAB_01_OOP_CANVASSTRUCT_H
#define LAB_01_OOP_CANVASSTRUCT_H

#include "QGraphicsView"
#include "DotStruct.h"

struct CanvasStruct
{
    QGraphicsView *canvas;
    QPen *mainPen;
    int height;
    int width;
};

int initCanvas(CanvasStruct& canvasStruct);

int drawLine(CanvasStruct& canvasStruct, dot from, dot to);

int clear(CanvasStruct& canvasStruct);

#endif //LAB_01_OOP_CANVASSTRUCT_H
