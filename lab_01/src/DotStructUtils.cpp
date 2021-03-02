//
// Created by denis on 02.03.2021.
//

#include <cmath>
#include "DotStructUtils.h"

void Move(allDots& vDots, int moveX, int moveY, int moveZ)
{
    for (auto &elem: vDots)
    {
        elem.second.coords.coordX += moveX;
        elem.second.coords.coordY += moveY;
        elem.second.coords.coordZ += moveZ;
    }
}

void RotateXAxis(allDots& vDots, int rotateAngle)
{
    double newDegrees = rotateAngle * 3.14 / 180;
    for(auto &dot: vDots)
    {
        const auto& tmpDot = dot;
        dot.second.coords.coordY = tmpDot.second.coords.coordY * cos(newDegrees) + tmpDot.second.coords.coordZ * sin(newDegrees);
        dot.second.coords.coordZ = -tmpDot.second.coords.coordY * sin(newDegrees) + tmpDot.second.coords.coordZ * cos(newDegrees);
    }
}

void RotateYAxis(allDots& vDots, int rotateAngle)
{
    double newDegrees = rotateAngle * 3.14 / 180;
    for(auto &dot: vDots)
    {
        const auto& tmpDot = dot;
        dot.second.coords.coordX = tmpDot.second.coords.coordX * cos(newDegrees) + tmpDot.second.coords.coordZ * sin(newDegrees);
        dot.second.coords.coordZ = -tmpDot.second.coords.coordX * sin(newDegrees) + tmpDot.second.coords.coordZ * cos(newDegrees);
    }
}

void RotateZAxis(allDots& vDots, int rotateAngle)
{
    double newDegrees = rotateAngle * 3.14 / 180;
    for(auto &dot: vDots)
    {
        const auto& tmpDot = dot;
        dot.second.coords.coordX = tmpDot.second.coords.coordX * cos(newDegrees) + tmpDot.second.coords.coordY * sin(newDegrees);
        dot.second.coords.coordY = -tmpDot.second.coords.coordX * sin(newDegrees) + tmpDot.second.coords.coordY * cos(newDegrees);
    }
}

void Rotate(allDots& vDots, int rotateX, int rotateY, int rotateZ)
{
    RotateXAxis(vDots, rotateX);
    RotateYAxis(vDots, rotateY);
    RotateZAxis(vDots, rotateZ);
}

void Zoom(allDots& vDots, dotCoords zoomCenter, double kX, double kY, double kZ)
{
    for (auto &dot: vDots)
    {
        dot.second.coords.coordX = zoomCenter.coordX + (dot.second.coords.coordX - zoomCenter.coordX) * kX;
        dot.second.coords.coordY = zoomCenter.coordY + (dot.second.coords.coordY - zoomCenter.coordY) * kY;
        dot.second.coords.coordZ = zoomCenter.coordZ + (dot.second.coords.coordZ - zoomCenter.coordZ) * kZ;
    }
}