//
// Created by denis on 28.02.2021.
//

#include "DotFileIO.h"
#include "Errors.h"
#include "cstdio"

int ReadIntFromFile(FILE *file, int &readNumb)
{
    if (!file)
        return FAIL_OPEN_FILE;
    if (feof(file))
        return INCORRECT_FILE_DATA_STRUCTURE;
    else if (fscanf(file, "%d", &readNumb) != 1)
        return FAIL_READ_FILE_DATA;
    return OK;
}

int ReadDoubleFromFile(FILE *file, double &readNumb)
{
    if (!file)
        return FAIL_OPEN_FILE;
    if (feof(file))
        return INCORRECT_FILE_DATA_STRUCTURE;
    else if (fscanf(file, "%lf", &readNumb) != 1)
        return FAIL_READ_FILE_DATA;
    return OK;
}

int GetDotsCountFromFile(FILE *file, mainShape_t &mainShape)
{
    if (!file)
        return FAIL_OPEN_FILE;
    int dotsNumb;
    auto error = ReadIntFromFile(file, dotsNumb);
    if (error != OK)
        return error;

    mainShape.coordsNumb = dotsNumb;
    mainShape.shapeCoords = static_cast<dot *>(malloc(dotsNumb * sizeof(dot)));
    if (!mainShape.shapeCoords)
        return ALLOC_ERROR;
    return error;
}

int ReadDotFromFile(FILE *file, dot &readDot)
{
    if (!file)
        return FAIL_OPEN_FILE;
    int error;
    if ((error = ReadDoubleFromFile(file, readDot.coordX)) != OK)
        return error;
    if ((error = ReadDoubleFromFile(file, readDot.coordY)) != OK)
        return error;
    if ((error = ReadDoubleFromFile(file, readDot.coordZ)) != OK)
        return error;
    return error;
}

int AllocDotLinks(mainShape_t &shape, const int linksCount)
{
    shape.linksNumb = linksCount;
    shape.linkNodesNumbers = static_cast<link *>(malloc(linksCount * sizeof(link)));
    if (!shape.linkNodesNumbers)
        return ALLOC_ERROR;
    return OK;
}

int GetLinksCountFromFile(FILE *file, mainShape_t &mainShape)
{
    if (!file)
        return FAIL_OPEN_FILE;
    int linksCount;
    int error = ReadIntFromFile(file, linksCount);
    if (error != OK)
        return error;
    else if (AllocDotLinks(mainShape, linksCount) != OK)
        return ALLOC_ERROR;
    return error;
}

int AddLink(link* links, unsigned int linkCount, int from, int to)
{
    int i;
    for (i = 0; i < linkCount; i++)
    {
        if (links[i].to == -1 && links[i].from == -1)
        {
            links[i].from = from;
            links[i].to = to;
            break;
        }
    }
    if (i == linkCount)
        return INCORRECT_FILE_DATA_STRUCTURE;
    return OK;
}

int ReadLinkFromFile(FILE *file, mainShape_t &mainShape)
{
    if (!file)
        return FAIL_OPEN_FILE;

    int dotLinkFrom, dotLinkTo;
    int error = ReadIntFromFile(file, dotLinkFrom);
    if (error != OK)
        return error;
    if ((error = ReadIntFromFile(file, dotLinkTo)) != OK)
        return error;
    else if (dotLinkFrom > mainShape.coordsNumb || dotLinkTo > mainShape.coordsNumb)
        return INCORRECT_LINK_DOT_INDEX;

    return AddLink(mainShape.linkNodesNumbers, mainShape.linksNumb, dotLinkFrom, dotLinkTo);
}

int FillShapeLinksNegativeUnits(link* links, unsigned int linksCount)
{
    for (unsigned int i = 0; i < linksCount; i++)
    {
        links[i].from = -1;
        links[i].to = -1;
    }
    return OK;
}


int ReadAllLinksFromFile(FILE *file, mainShape_t &mainShape)
{
    if (!file)
        return FAIL_OPEN_FILE;
    int error = OK;
    if ((error = GetLinksCountFromFile(file, mainShape)) != OK)
        return error;
    if ((error = FillShapeLinksNegativeUnits(mainShape.linkNodesNumbers, mainShape.linksNumb)) != OK)
        return error;
    for (int i = 0; i < mainShape.linksNumb; i++) {
        if ((error = ReadLinkFromFile(file, mainShape)) != OK)
            break;
    }
    return error;
}

int ReadDots(FILE *file, dot* dots, const unsigned int dotsNumb)
{
    int error = OK;
    for (int i = 0; i < dotsNumb; i++) {
        if ((error = ReadDotFromFile(file, dots[i])) != OK)
            return error;
    }
    return error;
}

int ReadAllDotsFromFile(FILE *file, mainShape_t &mainShape)
{
    if (!file)
        return FAIL_OPEN_FILE;
    int error = OK;
    if ((error = GetDotsCountFromFile(file, mainShape)) != OK)
        return error;

    ReadDots(file, mainShape.shapeCoords, mainShape.coordsNumb);

    return error;
}

int GetDotsFromFile(char* fileName, mainShape_t& mainShape)
{
    if (!fileName)
        return FAIL_OPEN_FILE;
    FILE *file = fopen(fileName, "r");
    if (!file)
        return FAIL_OPEN_FILE;
    int error = OK;

    if ((error = ReadAllDotsFromFile(file, mainShape)) != OK) {
        fclose(file);
        return error;
    }
    error = ReadAllLinksFromFile(file, mainShape);
    fclose(file);
    return error;
}


