//
// Created by denis on 28.02.2021.
//

#ifndef LAB_01_DOTFILEIO_H
#define LAB_01_DOTFILEIO_H

#include "DotStruct.h"

struct FileWorkData
{
    char *filename;
};

int LoadShapeFromFile(const FileWorkData& fileData, mainShape_t& mainShape);

#endif //LAB_01_DOTFILEIO_H
