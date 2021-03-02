//
// Created by denis on 28.02.2021.
//

#include <fstream>
#include "DotFileIO.h"
#include "StringAnalizator.h"
#include "Errors.h"
#include "iostream"

std::ifstream GetLink(std::ifstream file, std::pair<std::string, std::string>& link, int &error)
{
    std::string from, to;
    file >> from;
    if (file.eof()) {
        error = INCORRECT_FILE_DATA;
        return file;
    }
    file >> to;
    link.first = from;
    link.second = to;
    return file;
}


std::ifstream GetDotBaseInfoFromFile(std::ifstream file, myDots &dot, int &error)
{
    std::string dotName;
    file >> dotName;
    std::vector<int> vCoords;
    vCoords.reserve(3);
    for (int i = 0; i < 3; i++)
    {
        std::string coord;
        file >> coord;
        if (!IsInt(coord))
        {
            error = FAIL_READ_FILE_DATA;
            return file;
        }
        vCoords[i] = std::stoi(coord);
    }
    dot = myDots {vCoords[0], vCoords[1], vCoords[2], dotName};
    error = OK;
    return file;
}


std::map<std::string, myDots> GetDotsFromFile(const std::string& fileName, int &error)
{
    error = OK;
    std::map<std::string, myDots> vResDots;
    std::ifstream dotFile(fileName);
    if (!dotFile) {
        error = FAIL_OPEN_FILE;
        return vResDots;
    }
    std::string coordCount, linkCount;
    dotFile >> coordCount;
    dotFile >> linkCount;
    if (!IsInt(coordCount) || !IsInt(coordCount)) {
        error = FAIL_READ_FILE_DATA;
        return vResDots;
    }

    int readCoordsCount = 0;
    while (!dotFile.eof() && readCoordsCount < std::stoi(coordCount)) {
        myDots dot;
        dotFile = GetDotBaseInfoFromFile(std::move(dotFile), dot, error);
        if (error != OK)
            return vResDots;
        vResDots.emplace(dot.dotName, dot);
        readCoordsCount++;
    }
    if (readCoordsCount != std::stoi(coordCount)) {
        error = INCORRECT_FILE_DATA;
        return vResDots;
    }
    int readCoordsLinks = 0;
    while (!dotFile.eof() && readCoordsLinks < std::stoi(linkCount)) {
        std::pair<std::string, std::string> pLink;
        dotFile = GetLink(std::move(dotFile), pLink, error);
        if (error == OK) {
            auto indexFrom = vResDots.find(pLink.first);
            auto indexTo = vResDots.find(pLink.second);
            if (indexFrom == vResDots.end() || indexTo == vResDots.end())
                error = INCORRECT_FILE_DATA;
            else
                indexFrom->second.m_vLinkNodes.push_back(pLink.second);
        }
        if (error != OK)
            return vResDots;
    }
    return vResDots;
}


