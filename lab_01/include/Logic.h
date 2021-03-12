//
// Created by denis on 04.03.2021.
//

#ifndef LAB_01_OOP_LOGIC_H
#define LAB_01_OOP_LOGIC_H

#include "DotStruct.h"
#include "UtilStruct.h"
#include "Qt/CanvasStruct.h"
#include "FillGraphicWidget.h"
enum choose
{
    GetShapeFromFile = 0,
    MoveShape = 1,
    RotateShape = 2,
    ScaleShape = 3,
    Quit = 4
};

int ApplyAction(utilData& data, CanvasStruct& canvas, choose userChoose);


#endif //LAB_01_OOP_LOGIC_H
