//
// Created by denis on 08.03.2021.
//

#ifndef LAB_01_OOP_UTILSTRUCT_H
#define LAB_01_OOP_UTILSTRUCT_H

#include "DotStruct.h"

typedef struct UtilsStruct
{
    dot centerDot;
    moveCoords_t moveCoords;
    rotateCoords_t rotateCoords;
    scaleCoords_t scaleCoords;
    char *filename;
} utilData;


#endif //LAB_01_OOP_UTILSTRUCT_H
