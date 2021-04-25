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
    shape.isInit = false;
    return SUCCESS_FREE;
}

int InitDots(dotsStruct& dots)
{
    dots.coordsNumb = 0;
    dots.shapeCoords = nullptr;
    return OK;
}

int InitLinks(linksStruct& links)
{
    links.linksNumb = 0;
    links.linkNodesNumbers = nullptr;
    return OK;
}

int InitCenter(dot& center)
{
    center.coordX = 0;
    center.coordY = 0;
    center.coordZ = 0;
    return OK;
}

mainShape_t& initShape()
{
    static mainShape_t shape;
    InitDots(shape.dots);
    InitLinks(shape.links);
    InitCenter(shape.center);
    shape.isInit = true;
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


int SetShapeCenter(dot& centerDot, const dotsStruct& dots)
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

int checkLink(const link& link, unsigned int maxDots)
{
    if (link.from < 0 || link.from > maxDots || link.to < 0 || link.to > maxDots)
        return INCORRECT_ARG;
    return OK;
}

int checkLinksOnCorrect(const dotsStruct& dots, const linksStruct& links)
{
    int error = OK;
    for (unsigned int i = 0; i < links.linksNumb && error == OK; i++)
        error = checkLink(links.linkNodesNumbers[i], dots.coordsNumb);
    return error;
}

int isShapeCorrect(const mainShape_t& shape)
{
    if (!shape.isInit)
        return INCORRECT_ARG;
    return checkLinksOnCorrect(shape.dots, shape.links);
}