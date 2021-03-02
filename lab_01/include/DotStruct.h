//
// Created by denis on 28.02.2021.
//

#ifndef LAB_01_DOTSTRUCT_H
#define LAB_01_DOTSTRUCT_H

#include <vector>
#include "string"

typedef struct dot
{
    int coordX;
    int coordY;
    int coordZ;

    std::string dotName;
    std::vector<std::string> m_vLinkNodes;
} myDots;


#endif //LAB_01_DOTSTRUCT_H
