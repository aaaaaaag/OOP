//
// Created by denis on 28.02.2021.
//

#ifndef LAB_01_DOTSTRUCT_H
#define LAB_01_DOTSTRUCT_H

#include <vector>
#include "string"
#include "map"

typedef struct coord
{
    double coordX;
    double coordY;
    double coordZ;
} dotCoords;

typedef struct dot
{
    dotCoords coords;

    std::string dotName;
    std::vector<std::string> m_vLinkNodes;
} myDots;

typedef std::map<std::string, myDots> allDots;


#endif //LAB_01_DOTSTRUCT_H
