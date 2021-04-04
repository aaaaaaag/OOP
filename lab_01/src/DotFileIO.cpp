//
// Created by denis on 28.02.2021.
//

#include "DotFileIO.h"
#include "Errors.h"
#include "cstdio"

int freeDots(dotsStruct& dots)
{
    free(dots.shapeCoords);
    return OK;
}

int ReadIntFromFile(int &readNumb, FILE *const file)
{
    if (!file) return FAIL_OPEN_FILE;
    if (feof(file)) return INCORRECT_FILE_DATA_STRUCTURE;
    else if (fscanf(file, "%d", &readNumb) != 1) return FAIL_READ_FILE_DATA;
    return OK;
}

int ReadDoubleFromFile(double &readNumb, FILE *const file)
{
    if (!file) return FAIL_OPEN_FILE;
    if (feof(file)) return INCORRECT_FILE_DATA_STRUCTURE;
    else if (fscanf(file, "%lf", &readNumb) != 1) return FAIL_READ_FILE_DATA;
    return OK;
}

int GetDotsCountFromFile(dotsStruct &dots, FILE *const file)
{
    if (!file) return FAIL_OPEN_FILE;

    int dotsNumb;
    auto error = ReadIntFromFile(dotsNumb, file);
    if (error != OK) return error;

    dots.coordsNumb = dotsNumb;
    dots.shapeCoords = static_cast<dot *>(malloc(dotsNumb * sizeof(dot)));
    if (!dots.shapeCoords) return ALLOC_ERROR;
    return error;
}

int ReadDotFromFile(dot &readDot, FILE *const file)
{
    if (!file)
        return FAIL_OPEN_FILE;
    int error;
    if ((error = ReadDoubleFromFile(readDot.coordX, file)) != OK) return error;
    if ((error = ReadDoubleFromFile(readDot.coordY, file)) != OK) return error;
    if ((error = ReadDoubleFromFile(readDot.coordZ, file)) != OK) return error;
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

int GetLinksCountFromFile(linksStruct &links, FILE *const file)
{
    if (!file) return FAIL_OPEN_FILE;
    int linksCount;
    int error = ReadIntFromFile(linksCount, file);

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

int ReadLinkFromFile(linksStruct &links, FILE *const file)
{
    if (!file) return FAIL_OPEN_FILE;

    int dotLinkFrom, dotLinkTo, error = OK;
    if ((error = ReadIntFromFile(dotLinkFrom, file)) != OK) return error;
    if ((error = ReadIntFromFile(dotLinkTo, file)) != OK) return error;

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

    if (error != OK) free(links.linkNodesNumbers);
    return error;
}


int ReadAllLinksFromFile(linksStruct &links, FILE *const file)
{
    if (!file) return FAIL_OPEN_FILE;
    int error = OK;
    if ((error = GetLinksCountFromFile(links, file)) != OK) return error;
    if ((error = FillShapeLinksNegativeUnits(links)) != OK) return error;

    for (int i = 0; i < links.linksNumb && error == OK; i++)
        if ((error = ReadLinkFromFile(links, file)) != OK) free(links.linkNodesNumbers);

    return error;
}

int ReadDots(dotsStruct& dots, FILE *const file)
{
    int error = OK;
    for (int i = 0; i < dots.coordsNumb; i++) {
        if ((error = ReadDotFromFile(dots.shapeCoords[i], file)) != OK) {
            free(dots.shapeCoords);
            return error;
        }
    }
    return error;
}

int ReadAllDotsFromFile(dotsStruct &dots, FILE *const file)
{
    if (!file) return FAIL_OPEN_FILE;
    int error = OK;
    if ((error = GetDotsCountFromFile(dots, file)) != OK) return error;
    return ReadDots(dots, file);
}

int LoadShapeFromFile(mainShape_t& mainShape, const FileWorkData& fileData)
{
    if (!fileData.filename) return FAIL_OPEN_FILE;
    FILE *file = fopen(fileData.filename, "r");
    if (!file) return FAIL_OPEN_FILE;
    int error = OK;
    mainShape_t copyFigure = initShape();
    error = ReadAllDotsFromFile(copyFigure.dots, file);
    if (error == OK) {
        error = ReadAllLinksFromFile(copyFigure.links, file);
        if (error != OK) freeDots(copyFigure.dots);
    }
    fclose(file);
    if (error == OK && (error = SetShapeCenter(copyFigure.center, copyFigure.dots)) != OK)
        error = freeShapeMemory(copyFigure);

    if (error == OK && isShapeCorrect(copyFigure) == OK) {
        error = freeShapeMemory(mainShape);
        if (error == SUCCESS_FREE) mainShape = copyFigure;
    }
    return error;
}