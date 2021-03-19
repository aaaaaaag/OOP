//
// Created by denis on 02.03.2021.
//

#ifndef LAB_01_OOP_DOTSTRUCTUTILS_H
#define LAB_01_OOP_DOTSTRUCTUTILS_H

#include "map"
#include "DotStruct.h"

struct MoveCoords_t
{
    double xMove;
    double yMove;
    double zMove;
};

struct RotateCoords_t
{
    double xRotateDegrees;
    double yRotateDegrees;
    double zRotateDegrees;
};

struct ScaleCoords_t
{
    double xScaleKoef;
    double yScaleKoef;
    double zScaleKoef;
};

int Move(mainShape_t& shape, const MoveCoords_t& moveCoords);

int Rotate(mainShape_t& shape, const RotateCoords_t& rotateCoords);

int Zoom(mainShape_t& shape, const ScaleCoords_t& scaleCoords);



#endif //LAB_01_OOP_DOTSTRUCTUTILS_H
