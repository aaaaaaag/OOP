//
// Created by denis on 02.03.2021.
//

#include <cmath>
#include "DotStructUtils.h"
#include "Errors.h"


int addDotToDot(dot &first, dot second)
{
    first.coordX += second.coordX;
    first.coordY += second.coordY;
    first.coordZ += second.coordZ;
    return OK;
}

int Move(mainShape_t& shape, dot &centerDot, MoveCoords_t moveCoords)
{
    if (shape.shapeCoords == nullptr && shape.coordsNumb != 0)
        return INCORRECT_ARG;
    dot moveDot{moveCoords.xMove, moveCoords.yMove, moveCoords.zMove};
    for (int i = 0; i < shape.coordsNumb; i++)
        addDotToDot(shape.shapeCoords[i], moveDot);

    addDotToDot(centerDot, moveDot);
    return OK;
}


int RotateDot(double& coord1, double& coord2, double centerCoord1, double centerCoord2, double degrees)
{
    double coord1Copy = coord1;
    double coord2Copy = coord2;
    coord1 = centerCoord1 + (coord1Copy - centerCoord1) * cos(degrees)
                                         - (coord2Copy - centerCoord2) * sin(degrees);
    coord2 = centerCoord2 + (coord1Copy - centerCoord1) * sin(degrees)
                                         + (coord2Copy - centerCoord2) * cos(degrees);
    return OK;
}

int RotateX(dot& rotateDot, dot centerDot, double degrees)
{
    return RotateDot(rotateDot.coordY, rotateDot.coordZ, centerDot.coordY, centerDot.coordZ, degrees);
}

int RotateY(dot& rotateDot, dot centerDot, double degrees)
{
    return RotateDot(rotateDot.coordX, rotateDot.coordZ, centerDot.coordX, centerDot.coordZ, degrees);
}

int RotateZ(dot& rotateDot, dot centerDot, double degrees)
{
    return RotateDot(rotateDot.coordX, rotateDot.coordY, centerDot.coordX, centerDot.coordY, degrees);
}

int RotateXAxis(mainShape_t& shape, dot centerDot, RotateCoords_t degrees)
{
    if (shape.shapeCoords == nullptr && shape.coordsNumb != 0)
        return INCORRECT_ARG;
    double newDegrees = degrees.xRotateDegrees * 3.14 / 180;
    for (int i = 0; i < shape.coordsNumb; i++)
        RotateX(shape.shapeCoords[i], centerDot, newDegrees);
    return OK;
}

int RotateYAxis(mainShape_t& shape, dot centerDot, RotateCoords_t degrees)
{
    if (shape.shapeCoords == nullptr && shape.coordsNumb != 0)
        return INCORRECT_ARG;
    double newDegrees = degrees.yRotateDegrees * 3.14 / 180;
    for (int i = 0; i < shape.coordsNumb; i++)
        RotateY(shape.shapeCoords[i], centerDot, newDegrees);
    return OK;
}

int RotateZAxis(mainShape_t& shape, dot centerDot, RotateCoords_t degrees)
{
    if (shape.shapeCoords == nullptr && shape.coordsNumb != 0)
        return INCORRECT_ARG;
    double newDegrees = degrees.zRotateDegrees * 3.14 / 180;
    for (int i = 0; i < shape.coordsNumb; i++)
        RotateZ(shape.shapeCoords[i], centerDot, newDegrees);
    return OK;
}

int Rotate(mainShape_t& shape, dot centerDot, RotateCoords_t rotateCoords)
{
    int error = OK;
    if (shape.shapeCoords == nullptr && shape.coordsNumb != 0)
        return INCORRECT_ARG;
    error = RotateXAxis(shape, centerDot, rotateCoords);
    if (error == OK) {
        error = RotateYAxis(shape, centerDot, rotateCoords);
        if (error == OK)
            error = RotateZAxis(shape, centerDot, rotateCoords);
    }
    return error;
}

int ZoomDot(dot& zoomDot, dot centerDot, ScaleCoords_t scaleCoords)
{
    zoomDot.coordX = centerDot.coordX + (zoomDot.coordX - centerDot.coordX) * scaleCoords.xScaleKoef;
    zoomDot.coordY = centerDot.coordY + (zoomDot.coordY - centerDot.coordY) * scaleCoords.yScaleKoef;
    zoomDot.coordZ = centerDot.coordZ + (zoomDot.coordZ - centerDot.coordZ) * scaleCoords.zScaleKoef;
    return OK;
}


int Zoom(mainShape_t& shape, dot centerDot, ScaleCoords_t scaleCoords)
{
    if (shape.shapeCoords == nullptr && shape.coordsNumb != 0)
        return INCORRECT_ARG;
    int error = OK;
    for (int i = 0; i < shape.coordsNumb && error == OK; i++)
    {
        error = ZoomDot(shape.shapeCoords[i], centerDot, scaleCoords);
    }
    return error;
}


int SetMaxDot(dot& maxDot, dot checkDot)
{
    if (maxDot.coordX < checkDot.coordX)
        maxDot.coordX = checkDot.coordX;
    if (maxDot.coordY < checkDot.coordY)
        maxDot.coordY = checkDot.coordY;
    if (maxDot.coordZ < checkDot.coordZ)
        maxDot.coordZ = checkDot.coordZ;
    return OK;
}

int SetMinDot(dot& minDot, dot checkDot)
{
    if (minDot.coordX > checkDot.coordX)
        minDot.coordX = checkDot.coordX;
    if (minDot.coordY > checkDot.coordY)
        minDot.coordY = checkDot.coordY;
    if (minDot.coordZ > checkDot.coordZ)
        minDot.coordZ = checkDot.coordZ;
    return OK;
}


int SetShapeCenter(mainShape_t shape, dot& centerDot)
{
    if (shape.coordsNumb != 0 && shape.shapeCoords == nullptr)
        return INCORRECT_ARG;
    dot maxDot = shape.shapeCoords[0];
    dot minDot = shape.shapeCoords[0];
    for (int i = 0; i < shape.coordsNumb; i++)
    {
        SetMaxDot(maxDot, shape.shapeCoords[i]);
        SetMinDot(minDot, shape.shapeCoords[i]);
    }
    centerDot.coordX = (maxDot.coordX - minDot.coordX) / 2;
    centerDot.coordY = (maxDot.coordY - minDot.coordY) / 2;
    centerDot.coordZ = (maxDot.coordZ - minDot.coordZ) / 2;
    return OK;
}