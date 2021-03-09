//
// Created by denis on 04.03.2021.
//

#ifndef LAB_01_OOP_LOGIC_H
#define LAB_01_OOP_LOGIC_H

#include "DotStruct.h"
#include "UtilStruct.h"
#include "Qt/CanvasWidget.h"
#include "FillGraphicWidget.h"
enum choose
{
    GetShapeFromFile = 0,
    SetShapeToFile = 1,
    MoveShape = 2,
    RotateShape = 3,
    ScaleShape = 4
};

int ApplyAction(choose userChoose, mainShape_t& mainShape, utilData data, CanvasWidget *widget);


#endif //LAB_01_OOP_LOGIC_H
