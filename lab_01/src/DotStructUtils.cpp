//
// Created by denis on 02.03.2021.
//

#include <cmath>
#include "DotStructUtils.h"

void Move(mainShape_t& shape)
{
    for (int i = 0; i < shape.coordsNumb; i++)
    {
        shape.shapeCoords[i].coords.coordX += shape.updateParams.moveCoords.xMove;
        shape.shapeCoords[i].coords.coordY += shape.updateParams.moveCoords.yMove;
        shape.shapeCoords[i].coords.coordZ += shape.updateParams.moveCoords.zMove;
    }
}

void RotateXAxis(mainShape_t& shape)
{
    double newDegrees = shape.updateParams.rotateCoords.xRotateDegrees * 3.14 / 180;
    for (int i = 0; i < shape.coordsNumb; i++)
    {
        shapeDot curDot = shape.shapeCoords[i];
        shape.shapeCoords[i].coords.coordY = curDot.coords.coordY * cos(newDegrees) + curDot.coords.coordZ * sin(newDegrees);
        shape.shapeCoords[i].coords.coordZ = -curDot.coords.coordY * sin(newDegrees) + curDot.coords.coordZ * cos(newDegrees);
    }
}

void RotateYAxis(mainShape_t& shape)
{
    double newDegrees = shape.updateParams.rotateCoords.yRotateDegrees * 3.14 / 180;
    for (int i = 0; i < shape.coordsNumb; i++)
    {
        shapeDot curDot = shape.shapeCoords[i];
        shape.shapeCoords[i].coords.coordX = curDot.coords.coordX * cos(newDegrees) + curDot.coords.coordZ * sin(newDegrees);
        shape.shapeCoords[i].coords.coordZ = -curDot.coords.coordX * sin(newDegrees) + curDot.coords.coordZ * cos(newDegrees);
    }
}

void RotateZAxis(mainShape_t& shape)
{
    double newDegrees = shape.updateParams.rotateCoords.zRotateDegrees * 3.14 / 180;
    for (int i = 0; i < shape.coordsNumb; i++)
    {
        shapeDot curDot = shape.shapeCoords[i];
        shape.shapeCoords[i].coords.coordX = curDot.coords.coordX * cos(newDegrees) + curDot.coords.coordY * sin(newDegrees);
        shape.shapeCoords[i].coords.coordY = -curDot.coords.coordX * sin(newDegrees) + curDot.coords.coordY * cos(newDegrees);
    }
}

void Rotate(mainShape_t& shape)
{
    RotateXAxis(shape);
    RotateYAxis(shape);
    RotateZAxis(shape);
}

void Zoom(mainShape_t& shape, dot zoomCenter)
{
    for (int i = 0; i < shape.coordsNumb; i++)
    {
        shape.shapeCoords[i].coords.coordX = zoomCenter.coordX + (shape.shapeCoords[i].coords.coordX - zoomCenter.coordX) * shape.updateParams.scaleCoords.xScaleKoef;
        shape.shapeCoords[i].coords.coordY = zoomCenter.coordY + (shape.shapeCoords[i].coords.coordY - zoomCenter.coordY) * shape.updateParams.scaleCoords.yScaleKoef;
        shape.shapeCoords[i].coords.coordZ = zoomCenter.coordZ + (shape.shapeCoords[i].coords.coordZ - zoomCenter.coordZ) * shape.updateParams.scaleCoords.zScaleKoef;
    }
}