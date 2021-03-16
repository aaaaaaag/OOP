//
// Created by denis on 10.03.2021.
//

#include "DotStruct.h"
#include "Errors.h"

int freeAll(mainShape_t& shape)
{
    free(shape.linkNodesNumbers);
    free(shape.shapeCoords);
    shape.shapeCoords = nullptr;
    shape.linkNodesNumbers = nullptr;
    return SUCCESS_FREE;
}

int initShape(mainShape_t& shape)
{
    shape.shapeCoords = nullptr;
    shape.coordsNumb = 0;
    return OK;
}