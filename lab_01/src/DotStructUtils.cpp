//
// Created by denis on 02.03.2021.
//

#include <cmath>
#include "DotStructUtils.h"

void Move(mainShape_t& shape, utilData data)
{
    if (shape.shapeCoords == nullptr)
        return;
    for (int i = 0; i < shape.coordsNumb; i++)
    {
        shape.shapeCoords[i].coords.coordX += data.updateParams.moveCoords.xMove;
        shape.shapeCoords[i].coords.coordY += data.updateParams.moveCoords.yMove;
        shape.shapeCoords[i].coords.coordZ += data.updateParams.moveCoords.zMove;
    }
}

void RotateXAxis(mainShape_t& shape, utilData data)
{
    if (shape.shapeCoords == nullptr)
        return;
    double newDegrees = data.updateParams.rotateCoords.xRotateDegrees * 3.14 / 180;
    for (int i = 0; i < shape.coordsNumb; i++)
    {
        shapeDot curDot = shape.shapeCoords[i];
        shape.shapeCoords[i].coords.coordY = curDot.coords.coordY * cos(newDegrees) + curDot.coords.coordZ * sin(newDegrees);
        shape.shapeCoords[i].coords.coordZ = -curDot.coords.coordY * sin(newDegrees) + curDot.coords.coordZ * cos(newDegrees);
    }
}

void RotateYAxis(mainShape_t& shape, utilData data)
{
    double newDegrees = data.updateParams.rotateCoords.yRotateDegrees * 3.14 / 180;
    for (int i = 0; i < shape.coordsNumb; i++)
    {
        shapeDot curDot = shape.shapeCoords[i];
        shape.shapeCoords[i].coords.coordX = curDot.coords.coordX * cos(newDegrees) + curDot.coords.coordZ * sin(newDegrees);
        shape.shapeCoords[i].coords.coordZ = -curDot.coords.coordX * sin(newDegrees) + curDot.coords.coordZ * cos(newDegrees);
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
        shape.shapeCoords[i].coords.coordX = curDot.coords.coordX * cos(newDegrees) + curDot.coords.coordY * sin(newDegrees);
        shape.shapeCoords[i].coords.coordY = -curDot.coords.coordX * sin(newDegrees) + curDot.coords.coordY * cos(newDegrees);
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