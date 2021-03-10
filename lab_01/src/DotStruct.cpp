//
// Created by denis on 10.03.2021.
//

#include "DotStruct.h"

void freeAll(mainShape_t& shape)
{
    for (int i = 0; i < shape.coordsNumb; i++)
        free(shape.shapeCoords[i].linkNodesNumbers);
    free(shape.shapeCoords);
}