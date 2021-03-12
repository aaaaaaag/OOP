//
// Created by denis on 28.02.2021.
//

#include "DotFileIO.h"
#include "Errors.h"
#include "cstdio"

int OpenFile(char* fileName, FILE* file)
{
    file = fopen(fileName, "r");
    if (!file)
        return FAIL_OPEN_FILE;
    return OK;
}

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
    mainShape.shapeCoords = static_cast<shapeDot *>(malloc(dotsNumb * sizeof(shapeDot)));
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

int FillShapeDotLinksWithNegativeUnits(shapeDot &dot)
{
    if (dot.linkNodesNumbers == nullptr && dot.linksNumb)
        return INCORRECT_LINK_DOT_INDEX;
    for (int link = 0; link < dot.linksNumb; link++)
        dot.linkNodesNumbers[link] = -1;
    return OK;
}


int FillShapeDotsLinksWithNegativeUnits(mainShape_t &mainShape)
{
    if (mainShape.shapeCoords == nullptr && mainShape.coordsNumb > 0)
        return INCORRECT_ARG;
    int error = OK;
    for(int i = 0; i < mainShape.coordsNumb; i++)
    {
        error = FillShapeDotLinksWithNegativeUnits(mainShape.shapeCoords[i]);
        if (error != OK)
            return error;
    }
    return error;
}

int AllocDotLinks(shapeDot &dot, const int linksCount)
{
    dot.linksNumb = linksCount;
    dot.linkNodesNumbers = static_cast<int *>(malloc(linksCount * sizeof(int)));
    if (!dot.linkNodesNumbers)
        return ALLOC_ERROR;
    return OK;
}

int GetLinksCountFromFile(FILE *file, mainShape_t &mainShape)
{
    if (!file) {
        return FAIL_OPEN_FILE;
    }
    int linksCount;
    int error = ReadIntFromFile(file, linksCount);
    if (error != OK)
        return error;

    for (int i = 0; i < mainShape.coordsNumb; i++) {
        if ((error = AllocDotLinks(mainShape.shapeCoords[i], linksCount)) != OK)
            return error;
    }
    return error;
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

    auto dotFrom = mainShape.shapeCoords[dotLinkFrom];
    int i;
    for (i = 0; i < dotFrom.linksNumb; i++)
    {
        if (dotFrom.linkNodesNumbers[i] == -1) {
            dotFrom.linkNodesNumbers[i] = dotLinkTo;
            break;
        }
    }
    if (i == dotFrom.linksNumb)
        error = INCORRECT_FILE_DATA_STRUCTURE;
    return error;
}

int ReadAllLinksFromFile(FILE *file, mainShape_t &mainShape)
{
    if (!file)
        return FAIL_OPEN_FILE;
    int error = OK;
    if ((error = GetLinksCountFromFile(file, mainShape)) != OK)
        return error;
    if ((error = FillShapeDotsLinksWithNegativeUnits(mainShape)) != OK)
        return error;
    for (int i = 0; i < mainShape.shapeCoords[0].linksNumb; i++) {
        if ((error = ReadLinkFromFile(file, mainShape)) != OK)
            break;
    }
    return error;
}

int ReadDots(FILE *file, shapeDot* dots, const unsigned int dotsNumb)
{
    int error = OK;
    for (int i = 0; i < dotsNumb; i++) {
        if ((error = ReadDotFromFile(file, dots[i].coords)) != OK)
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
//    error = OpenFile(fileName, file);
//    if (error != OK)
//        return error;

    if ((error = ReadAllDotsFromFile(file, mainShape)) != OK) {
        fclose(file);
        return error;
    }
    error = ReadAllLinksFromFile(file, mainShape);
    fclose(file);
    return error;
}


