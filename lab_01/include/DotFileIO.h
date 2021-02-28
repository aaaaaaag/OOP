//
// Created by denis on 28.02.2021.
//

#ifndef LAB_01_DOTFILEIO_H
#define LAB_01_DOTFILEIO_H

#include "vector"
#include "DotStruct.h"

std::vector<myDots> getDotsFromFile(std::string fileName, int &error);

int setDotsToFile(std::string fileName, std::vector<myDots> inVDots);


#endif //LAB_01_DOTFILEIO_H
