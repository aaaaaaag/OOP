//
// Created by denis on 28.02.2021.
//

#ifndef LAB_01_DOTSTRUCT_H
#define LAB_01_DOTSTRUCT_H

#include <vector>
#include "string"
#include "map"
#include "DotActionStruct.h"


typedef struct dot
{
    double coordX;
    double coordY;
    double coordZ;
}dot;

typedef struct shapeDot
{
    dot coords;

    unsigned int linksNumb = 0;
    int* linkNodesNumbers = nullptr;
} myDot;


typedef struct mainShape
{
    unsigned int coordsNumb = 0;
    shapeDot* shapeCoords = nullptr;
} mainShape_t;

void freeAll(mainShape_t& shape);

#endif //LAB_01_DOTSTRUCT_H
