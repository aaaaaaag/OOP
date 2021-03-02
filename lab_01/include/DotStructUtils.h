//
// Created by denis on 02.03.2021.
//

#ifndef LAB_01_OOP_DOTSTRUCTUTILS_H
#define LAB_01_OOP_DOTSTRUCTUTILS_H

#include "map"
#include "DotStruct.h"

void Move(allDots& vDots, int moveX, int moveY, int moveZ);

void Rotate(allDots& vDots, int rotateX, int rotateY, int rotateZ);

void Zoom(allDots& vDots, dotCoords zoomCenter, double kX, double kY, double kZ);





#endif //LAB_01_OOP_DOTSTRUCTUTILS_H
