//
// Created by denis on 28.02.2021.
//

#include "DotFileIO.h"
#include "Errors.h"
#include "cstdio"
int ReadIntFromFile(FILE *const file, int &readNumb)
{
    if (!file) return FAIL_OPEN_FILE;
    if (feof(file)) return INCORRECT_FILE_DATA_STRUCTURE;
    else if (fscanf(file, "%d", &readNumb) != 1) return FAIL_READ_FILE_DATA;
    return OK;
}

int ReadDoubleFromFile(FILE *const file, double &readNumb)
{
    if (!file) return FAIL_OPEN_FILE;
    if (feof(file)) return INCORRECT_FILE_DATA_STRUCTURE;
    else if (fscanf(file, "%lf", &readNumb) != 1) return FAIL_READ_FILE_DATA;
    return OK;
}

int GetDotsCountFromFile(FILE *const file, dotsStruct &dots)
{
    if (!file)
        return FAIL_OPEN_FILE;
    int dotsNumb;
    auto error = ReadIntFromFile(file, dotsNumb);
    if (error != OK) return error;

    dots.coordsNumb = dotsNumb;
    dots.shapeCoords = static_cast<dot *>(malloc(dotsNumb * sizeof(dot)));
    if (!dots.shapeCoords) return ALLOC_ERROR;
    return error;
}

int ReadDotFromFile(FILE *const file, dot &readDot)
{
    if (!file)
        return FAIL_OPEN_FILE;
    int error;
    if ((error = ReadDoubleFromFile(file, readDot.coordX)) != OK) return error;
    if ((error = ReadDoubleFromFile(file, readDot.coordY)) != OK) return error;
    if ((error = ReadDoubleFromFile(file, readDot.coordZ)) != OK) return error;
    return error;
}

int AllocDotLinks(linksStruct &links, const int linksCount)
{
    links.linksNumb = linksCount;
    links.linkNodesNumbers = static_cast<link *>(malloc(linksCount * sizeof(link)));
    if (!links.linkNodesNumbers)
        return ALLOC_ERROR;
    return OK;
}

int GetLinksCountFromFile(FILE *const file, linksStruct &links)
{
    if (!file) return FAIL_OPEN_FILE;
    int linksCount;
    int error = ReadIntFromFile(file, linksCount);

    if (error != OK) return error;
    else if (AllocDotLinks(links, linksCount) != OK) return ALLOC_ERROR;
    return OK;
}

int SetLink(link& inLink, int from, int to)
{
    if (inLink.to == -1 && inLink.from == -1)
    {
        inLink.from = from;
        inLink.to = to;
        return OK;
    }
    return INCORRECT_ARG;
}

int AddLink(linksStruct& links, int from, int to)
{
    int i;
    for (i = 0; i < links.linksNumb; i++)
        if (SetLink(links.linkNodesNumbers[i], from, to) == OK) return OK;
    return INCORRECT_FILE_DATA_STRUCTURE;
}

int ReadLinkFromFile(FILE *const file, linksStruct &links)
{
    if (!file) return FAIL_OPEN_FILE;

    int dotLinkFrom, dotLinkTo, error = OK;
    if ((error = ReadIntFromFile(file, dotLinkFrom)) != OK) return error;
    if ((error = ReadIntFromFile(file, dotLinkTo)) != OK) return error;

    return AddLink(links, dotLinkFrom, dotLinkTo);
}

int SetNegativePointsToLink(link& inLink)
{
    inLink.to = -1;
    inLink.from = -1;
    return OK;
}

int FillShapeLinksNegativeUnits(linksStruct& links)
{
    int error = OK;
    for (unsigned int i = 0; i < links.linksNumb; i++)
        if ((error = SetNegativePointsToLink(links.linkNodesNumbers[i])) != OK) break;
    return error;
}


int ReadAllLinksFromFile(FILE *const file, linksStruct &links)
{
    if (!file) return FAIL_OPEN_FILE;
    int error = OK;
    if ((error = GetLinksCountFromFile(file, links)) != OK) return error;
    if ((error = FillShapeLinksNegativeUnits(links)) != OK) return error;

    for (int i = 0; i < links.linksNumb; i++)
        if ((error = ReadLinkFromFile(file, links)) != OK) break;

    return error;
}

int ReadDots(FILE *const file, dotsStruct& dots)
{
    int error = OK;
    for (int i = 0; i < dots.coordsNumb; i++)
        if ((error = ReadDotFromFile(file, dots.shapeCoords[i])) != OK) return error;
    return error;
}

int ReadAllDotsFromFile(FILE *const file, dotsStruct &dots)
{
    if (!file) return FAIL_OPEN_FILE;
    int error = OK;
    if ((error = GetDotsCountFromFile(file, dots)) != OK) return error;
    error = ReadDots(file, dots);
    return error;
}

int LoadShapeFromFile(mainShape_t& mainShape, const FileWorkData& fileData)
{
    if (!fileData.filename) return FAIL_OPEN_FILE;
    FILE *file = fopen(fileData.filename, "r");
    if (!file) return FAIL_OPEN_FILE;
    int error = OK;
    mainShape_t copyFigure = initShape();
    if ((error = ReadAllDotsFromFile(file, copyFigure.dots)) == OK) {
        if ((error = ReadAllLinksFromFile(file, copyFigure.links)) == OK)
            error = SetShapeCenter(copyFigure.center, copyFigure.dots);
    }
    fclose(file);
    if (error == OK && isShapeCorrect(copyFigure) == OK) {
        error = freeAll(mainShape);
        if (error == OK) mainShape = copyFigure;
    }
    return error;
}


