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

    unsigned int linksNumb;
    int* linkNodesNumbers;
} myDot;


typedef struct mainShape
{
    unsigned int coordsNumb;
    shapeDot* shapeCoords;

    DotActionStruct updateParams;
} mainShape_t;

#endif //LAB_01_DOTSTRUCT_H
