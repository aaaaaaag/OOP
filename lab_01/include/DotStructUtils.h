//
// Created by denis on 02.03.2021.
//

#ifndef LAB_01_OOP_DOTSTRUCTUTILS_H
#define LAB_01_OOP_DOTSTRUCTUTILS_H

#include "map"
#include "DotStruct.h"
#include "UtilStruct.h"

int Move(mainShape_t& shape, utilData& data);

int Rotate(mainShape_t& shape, utilData data);

int Zoom(mainShape_t& shape, utilData data);

int SetShapeCenter(mainShape_t shape, utilData& data);



#endif //LAB_01_OOP_DOTSTRUCTUTILS_H
