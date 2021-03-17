//
// Created by denis on 28.02.2021.
//

#ifndef LAB_01_DOTSTRUCT_H
#define LAB_01_DOTSTRUCT_H

#include <vector>
#include "string"
#include "map"


struct dot
{
    double coordX;
    double coordY;
    double coordZ;
};

struct link {
    int from;
    int to;
};

struct dotsStruct
{
    unsigned int coordsNumb;
    dot* shapeCoords;
};

struct linksStruct
{
    unsigned int linksNumb;
    link* linkNodesNumbers;
};

struct mainShape_t
{
    dotsStruct dots;
    linksStruct links;
    dot center;
};

int freeAll(mainShape_t& shape);

mainShape_t& initShape();

int SetShapeCenter(dot& centerDot, const dotsStruct& dots);

#endif //LAB_01_DOTSTRUCT_H
