//
// Created by denis on 02.03.2021.
//

#ifndef LAB_01_OOP_DOTSTRUCTUTILS_H
#define LAB_01_OOP_DOTSTRUCTUTILS_H

#include "map"
#include "DotStruct.h"
#include "UtilStruct.h"

int Move(mainShape_t& shape, dot &centerDot, MoveCoords_t moveCoords);

int Rotate(mainShape_t& shape, dot centerDot, RotateCoords_t rotateCoords);

int Zoom(mainShape_t& shape, dot centerDot, ScaleCoords_t scaleCoords);

int SetShapeCenter(mainShape_t shape, dot& centerDot);



#endif //LAB_01_OOP_DOTSTRUCTUTILS_H
