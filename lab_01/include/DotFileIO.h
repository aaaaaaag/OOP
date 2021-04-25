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

int LoadShapeFromFile(mainShape_t& mainShape, const FileWorkData& fileData);

#endif //LAB_01_DOTFILEIO_H
