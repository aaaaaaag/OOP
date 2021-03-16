//
// Created by denis on 28.02.2021.
//

#ifndef LAB_01_DOTSTRUCT_H
#define LAB_01_DOTSTRUCT_H

#include <vector>
#include "string"
#include "map"
#include "DotActionStruct.h"


struct dot
{
    double coordX;
    double coordY;
    double coordZ;
};

struct link{
    int from;
    int to;
};

typedef struct mainShape
{
    unsigned int coordsNumb;
    dot* shapeCoords;

    unsigned int linksNumb;
    link* linkNodesNumbers;
} mainShape_t;

int freeAll(mainShape_t& shape);

int initShape(mainShape_t& shape);

#endif //LAB_01_DOTSTRUCT_H
