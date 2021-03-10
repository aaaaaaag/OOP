//
// Created by denis on 02.03.2021.
//

#include <cmath>
#include "DotStructUtils.h"

void Move(mainShape_t& shape, utilData& data)
{
    if (shape.shapeCoords == nullptr)
        return;
    for (int i = 0; i < shape.coordsNumb; i++)
    {
        shape.shapeCoords[i].coords.coordX += data.updateParams.moveCoords.xMove;
        shape.shapeCoords[i].coords.coordY += data.updateParams.moveCoords.yMove;
        shape.shapeCoords[i].coords.coordZ += data.updateParams.moveCoords.zMove;
    }
    data.centerDot.coordX += data.updateParams.moveCoords.xMove;
    data.centerDot.coordY += data.updateParams.moveCoords.yMove;
    data.centerDot.coordZ += data.updateParams.moveCoords.zMove;
}

void RotateXAxis(mainShape_t& shape, utilData data)
{
    if (shape.shapeCoords == nullptr)
        return;
    double newDegrees = data.updateParams.rotateCoords.xRotateDegrees * 3.14 / 180;
    for (int i = 0; i < shape.coordsNumb; i++)
    {
        shapeDot curDot = shape.shapeCoords[i];
        shape.shapeCoords[i].coords.coordY = data.centerDot.coordY + (curDot.coords.coordY - data.centerDot.coordY) * cos(newDegrees)
                - (curDot.coords.coordZ - data.centerDot.coordZ) * sin(newDegrees);
        shape.shapeCoords[i].coords.coordZ = data.centerDot.coordZ + (curDot.coords.coordY - data.centerDot.coordY) * sin(newDegrees)
                + (curDot.coords.coordZ - data.centerDot.coordZ) * cos(newDegrees);
    }
}

void RotateYAxis(mainShape_t& shape, utilData data)
{
    double newDegrees = data.updateParams.rotateCoords.yRotateDegrees * 3.14 / 180;
    for (int i = 0; i < shape.coordsNumb; i++)
    {
        shapeDot curDot = shape.shapeCoords[i];
        shape.shapeCoords[i].coords.coordX = data.centerDot.coordX + (curDot.coords.coordX - data.centerDot.coordX) * cos(newDegrees)
                                             - (curDot.coords.coordZ - data.centerDot.coordZ) * sin(newDegrees);
        shape.shapeCoords[i].coords.coordZ = data.centerDot.coordZ + (curDot.coords.coordX - data.centerDot.coordX) * sin(newDegrees)
                                             + (curDot.coords.coordZ - data.centerDot.coordZ) * cos(newDegrees);
    }
}

void RotateZAxis(mainShape_t& shape, utilData data)
{
    if (shape.shapeCoords == nullptr)
        return;
    double newDegrees = data.updateParams.rotateCoords.zRotateDegrees * 3.14 / 180;
    for (int i = 0; i < shape.coordsNumb; i++)
    {
        shapeDot curDot = shape.shapeCoords[i];
        shape.shapeCoords[i].coords.coordX = data.centerDot.coordX + (curDot.coords.coordX - data.centerDot.coordX) * cos(newDegrees)
                                             - (curDot.coords.coordY - data.centerDot.coordY) * sin(newDegrees);
        shape.shapeCoords[i].coords.coordY = data.centerDot.coordY + (curDot.coords.coordX - data.centerDot.coordX) * sin(newDegrees)
                                             + (curDot.coords.coordY - data.centerDot.coordY) * cos(newDegrees);
    }
}

void Rotate(mainShape_t& shape, utilData data)
{
    RotateXAxis(shape, data);
    RotateYAxis(shape, data);
    RotateZAxis(shape, data);
}

void Zoom(mainShape_t& shape, utilData data)
{
    if (shape.shapeCoords == nullptr)
        return;
    for (int i = 0; i < shape.coordsNumb; i++)
    {
        shape.shapeCoords[i].coords.coordX = data.centerDot.coordX +
                (shape.shapeCoords[i].coords.coordX - data.centerDot.coordX) * data.updateParams.scaleCoords.xScaleKoef;
        shape.shapeCoords[i].coords.coordY = data.centerDot.coordY +
                (shape.shapeCoords[i].coords.coordY - data.centerDot.coordY) * data.updateParams.scaleCoords.yScaleKoef;
        shape.shapeCoords[i].coords.coordZ = data.centerDot.coordZ +
                (shape.shapeCoords[i].coords.coordZ - data.centerDot.coordZ) * data.updateParams.scaleCoords.zScaleKoef;
    }
}


void SetShapeCenter(mainShape_t shape, utilData& data)
{
    if (shape.coordsNumb < 1 || shape.shapeCoords == nullptr)
        return;
    dot maxDot = shape.shapeCoords[0].coords;
    dot minDot = shape.shapeCoords[0].coords;
    for (int i = 0; i < shape.coordsNumb; i++)
    {
        auto curDot = shape.shapeCoords[i].coords;
        if (curDot.coordX > maxDot.coordX)
            maxDot.coordX = curDot.coordX;
        else if (curDot.coordX < minDot.coordX)
            minDot.coordX = curDot.coordX;
        if (curDot.coordY > maxDot.coordY)
            maxDot.coordY = curDot.coordY;
        else if (curDot.coordY < minDot.coordY)
            minDot.coordY = curDot.coordY;
        if (curDot.coordZ > maxDot.coordZ)
            maxDot.coordZ = curDot.coordZ;
        else if (curDot.coordZ < minDot.coordZ)
            minDot.coordZ = curDot.coordZ;
    }
    data.centerDot.coordX = (maxDot.coordX - minDot.coordX) / 2;
    data.centerDot.coordY = (maxDot.coordY - minDot.coordY) / 2;
    data.centerDot.coordZ = (maxDot.coordZ - minDot.coordZ) / 2;
}