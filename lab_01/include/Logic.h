//
// Created by denis on 04.03.2021.
//

#ifndef LAB_01_OOP_LOGIC_H
#define LAB_01_OOP_LOGIC_H

#include "DotStruct.h"
#include "Qt/CanvasStruct.h"
#include "FillGraphicWidget.h"
#include "DotStructUtils.h"
enum choose
{
    GetShapeFromFile = 0,
    MoveShape = 1,
    RotateShape = 2,
    ScaleShape = 3,
    Quit = 4
};

struct UtilsStruct
{
    dot centerDot;
    MoveCoords_t moveCoords;
    RotateCoords_t rotateCoords;
    ScaleCoords_t scaleCoords;
    char *filename;
};


int ApplyAction(UtilsStruct& data, CanvasStruct& canvas, choose userChoose);


#endif //LAB_01_OOP_LOGIC_H
