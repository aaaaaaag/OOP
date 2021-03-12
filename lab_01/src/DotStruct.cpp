//
// Created by denis on 10.03.2021.
//

#include "DotStruct.h"
#include "Errors.h"

int freeAll(mainShape_t& shape)
{
    for (int i = 0; i < shape.coordsNumb; i++)
        free(shape.shapeCoords[i].linkNodesNumbers);
    free(shape.shapeCoords);
    return OK;
}

int initShape(mainShape_t& shape)
{
    shape.shapeCoords = nullptr;
    shape.coordsNumb = 0;
    return OK;
}