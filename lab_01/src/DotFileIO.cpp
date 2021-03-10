//
// Created by denis on 28.02.2021.
//

#include "DotFileIO.h"
#include "Errors.h"
#include "cstdio"

void SetErrorCodeSuccess(int &error)
{
    error = OK;
}

FILE* OpenFile(char* fileName, int& error)
{
    SetErrorCodeSuccess(error);
    auto file = fopen(fileName, "r");
    if (!file)
        error = FAIL_OPEN_FILE;
    return file;
}

int ReadIntFromFile(FILE *file, int &error)
{
    if (!file) {
        error = FAIL_OPEN_FILE;
        return 0;
    }
    SetErrorCodeSuccess(error);
    int readInt = 0;
    if (feof(file))
        error = INCORRECT_FILE_DATA_STRUCTURE;
    else if (fscanf(file, "%d", &readInt) != 1)
        error = FAIL_READ_FILE_DATA;
    return readInt;
}

void GetDotsCountFromFile(FILE *file, mainShape_t &mainShape, int &error)
{
    if (!file) {
        error = FAIL_OPEN_FILE;
        return;
    }
    auto dotsNumb = ReadIntFromFile(file, error);
    if (error != OK)
        return;

    mainShape.coordsNumb = dotsNumb;
    mainShape.shapeCoords = static_cast<shapeDot *>(malloc(dotsNumb * sizeof(shapeDot)));
    if (!mainShape.shapeCoords)
        error = ALLOC_ERROR;
}

void ReadDotFromFile(FILE *file, shapeDot &readDot, int &error)
{
    if (!file) {
        error = FAIL_OPEN_FILE;
        return;
    }
    readDot.coords.coordX = ReadIntFromFile(file, error);
    if (error != OK)
        return;
    readDot.coords.coordY = ReadIntFromFile(file, error);
    if (error != OK)
        return;
    readDot.coords.coordZ = ReadIntFromFile(file, error);
    if (error != OK)
        return;
}

void FillShapeLinksWithNegativeUnits(mainShape_t &mainShape)
{
    for(int i = 0; i < mainShape.coordsNumb; i++)
    {
        for (int link = 0; link < mainShape.shapeCoords[i].linksNumb; link++)
            mainShape.shapeCoords[i].linkNodesNumbers[link] = -1;
    }
}

void GetLinksCountFromFile(FILE *file, mainShape_t &mainShape, int &error)
{
    if (!file) {
        error = FAIL_OPEN_FILE;
        return;
    }
    auto linksCount = ReadIntFromFile(file, error);
    if (error)
        return;

    for (int i = 0; i < mainShape.coordsNumb; i++) {
        mainShape.shapeCoords[i].linksNumb = linksCount;
        mainShape.shapeCoords[i].linkNodesNumbers = static_cast<int *>(malloc(linksCount * sizeof(int)));
    }
}

void ReadLinkFromFile(FILE *file, mainShape_t &mainShape, int &error)
{
    if (!file) {
        error = FAIL_OPEN_FILE;
        return;
    }
    auto dotLinkFrom = ReadIntFromFile(file, error);
    if (error != OK)
        return;
    auto dotLinkTo = ReadIntFromFile(file, error);
    if (error != OK)
        return;
    else if (dotLinkFrom > mainShape.coordsNumb || dotLinkTo > mainShape.coordsNumb)
    {
        error = INCORRECT_LINK_DOT_INDEX;
        return;
    }
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
}

void ReadAllLinksFromFile(FILE *file, mainShape_t &mainShape, int &error)
{
    if (!file) {
        error = FAIL_OPEN_FILE;
        return;
    }
    GetLinksCountFromFile(file, mainShape, error);
    if (error != OK)
        return;
    FillShapeLinksWithNegativeUnits(mainShape);
    for (int i = 0; i < mainShape.shapeCoords[0].linksNumb; i++) {
        ReadLinkFromFile(file, mainShape, error);
        if (error != OK)
            break;
    }
}


void ReadAllDotsFromFile(FILE *file, mainShape_t &mainShape, int &error)
{
    if (!file) {
        error = FAIL_OPEN_FILE;
        return;
    }
    GetDotsCountFromFile(file, mainShape, error);
    if (error != OK)
        return;

    for (int i = 0; i < mainShape.coordsNumb; i++)
        ReadDotFromFile(file, mainShape.shapeCoords[i], error);
}


mainShape_t GetDotsFromFile(char* fileName, int &error)
{
    mainShape_t mainShape;
    if (!fileName) {
        error = FAIL_OPEN_FILE;
        return mainShape;
    }
    auto file = OpenFile(fileName, error);
    if (error != OK)
        return mainShape;

    ReadAllDotsFromFile(file, mainShape, error);
    if (error == OK)
        ReadAllLinksFromFile(file, mainShape, error);
    fclose(file);
    return mainShape;
}


