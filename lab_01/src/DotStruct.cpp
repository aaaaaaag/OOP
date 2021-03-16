//
// Created by denis on 10.03.2021.
//

#include "DotStruct.h"
#include "Errors.h"

int freeAll(mainShape_t& shape)
{
    free(shape.links.linkNodesNumbers);
    free(shape.dots.shapeCoords);
    shape.dots.shapeCoords = nullptr;
    shape.links.linkNodesNumbers = nullptr;
    return SUCCESS_FREE;
}

mainShape_t& initShape()
{
    static mainShape_t shape;
    shape.dots.coordsNumb = 0;
    shape.dots.shapeCoords = nullptr;
    shape.links.linksNumb = 0;
    shape.links.linkNodesNumbers = nullptr;
    return shape;
}

int SetMaxDot(dot& maxDot, dot checkDot)
{
    if (maxDot.coordX < checkDot.coordX) maxDot.coordX = checkDot.coordX;
    if (maxDot.coordY < checkDot.coordY) maxDot.coordY = checkDot.coordY;
    if (maxDot.coordZ < checkDot.coordZ) maxDot.coordZ = checkDot.coordZ;
    return OK;
}

int SetMinDot(dot& minDot, dot checkDot)
{
    if (minDot.coordX > checkDot.coordX) minDot.coordX = checkDot.coordX;
    if (minDot.coordY > checkDot.coordY) minDot.coordY = checkDot.coordY;
    if (minDot.coordZ > checkDot.coordZ) minDot.coordZ = checkDot.coordZ;
    return OK;
}


int SetShapeCenter(dotsStruct dots, dot& centerDot)
{
    if (dots.coordsNumb != 0 && dots.shapeCoords == nullptr) return INCORRECT_ARG;
    dot maxDot = dots.shapeCoords[0];
    dot minDot = dots.shapeCoords[0];
    for (int i = 0; i < dots.coordsNumb; i++)
    {
        SetMaxDot(maxDot, dots.shapeCoords[i]);
        SetMinDot(minDot, dots.shapeCoords[i]);
    }
    centerDot.coordX = (maxDot.coordX - minDot.coordX) / 2;
    centerDot.coordY = (maxDot.coordY - minDot.coordY) / 2;
    centerDot.coordZ = (maxDot.coordZ - minDot.coordZ) / 2;
    return OK;
}