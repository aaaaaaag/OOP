//
// Created by denis on 28.02.2021.
//

#ifndef LAB_01_DOTSTRUCT_H
#define LAB_01_DOTSTRUCT_H

#include <vector>
#include "string"
#include "map"
#include "DotActionStruct.h"

typedef struct coord
{
    double coordX;
    double coordY;
    double coordZ;
} dotCoords;

typedef struct dot
{
    dotCoords coords;

    char* dotName;
    char** m_vLinkNodes;
} myDots;


typedef struct mainShape
{
    dot* shapeCoords;
    unsigned int coordsNumb;

    DotActionStruct updateParams;
} mainShape_t;

#endif //LAB_01_DOTSTRUCT_H
