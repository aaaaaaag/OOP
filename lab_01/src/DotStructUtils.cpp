//
// Created by denis on 02.03.2021.
//

#include <cmath>
#include "DotStructUtils.h"
#include "Errors.h"
#include "cmath"

int MoveDot(dot &first, const MoveCoords_t& second)
{
    first.coordX += second.xMove;
    first.coordY += second.yMove;
    first.coordZ += second.zMove;
    return OK;
}

int Move(dotsStruct& dots, dot &centerDot, const MoveCoords_t& moveCoords)
{
    if (dots.shapeCoords == nullptr && dots.coordsNumb != 0) return INCORRECT_ARG;

    for (int i = 0; i < dots.coordsNumb; i++)
        MoveDot(dots.shapeCoords[i], moveCoords);
    MoveDot(centerDot, moveCoords);
    return OK;
}

int RotateDot(double& coord1, double& coord2, double centerCoord1, double centerCoord2, const double& degrees)
{
    double coord1Copy = coord1, coord2Copy = coord2;
    coord1 = centerCoord1 + (coord1Copy - centerCoord1) * cos(degrees) - (coord2Copy - centerCoord2) * sin(degrees);
    coord2 = centerCoord2 + (coord1Copy - centerCoord1) * sin(degrees) + (coord2Copy - centerCoord2) * cos(degrees);
    return OK;
}

int RotateX(dot& rotateDot, const dot& centerDot, const double& degrees)
{
    return RotateDot(rotateDot.coordY, rotateDot.coordZ, centerDot.coordY, centerDot.coordZ, degrees);
}

int RotateY(dot& rotateDot, const dot& centerDot, const double& degrees)
{
    return RotateDot(rotateDot.coordX, rotateDot.coordZ, centerDot.coordX, centerDot.coordZ, degrees);
}

int RotateZ(dot& rotateDot, const dot& centerDot, const double& degrees)
{
    return RotateDot(rotateDot.coordX, rotateDot.coordY, centerDot.coordX, centerDot.coordY, degrees);
}

int RotateXAxis(dotsStruct& dots, const dot& centerDot, const RotateCoords_t& degrees)
{
    if (dots.shapeCoords == nullptr && dots.coordsNumb != 0) return INCORRECT_ARG;
    double newDegrees = degrees.xRotateDegrees * M_PI / 180;
    for (int i = 0; i < dots.coordsNumb; i++) RotateX(dots.shapeCoords[i], centerDot, newDegrees);
    return OK;
}

int RotateYAxis(dotsStruct& dots, const dot& centerDot, const RotateCoords_t& degrees)
{
    if (dots.shapeCoords == nullptr && dots.coordsNumb != 0) return INCORRECT_ARG;
    double newDegrees = degrees.yRotateDegrees * M_PI / 180;
    for (int i = 0; i < dots.coordsNumb; i++) RotateY(dots.shapeCoords[i], centerDot, newDegrees);
    return OK;
}

int RotateZAxis(dotsStruct& dots, const dot& centerDot, const RotateCoords_t& degrees)
{
    if (dots.shapeCoords == nullptr && dots.coordsNumb != 0) return INCORRECT_ARG;
    double newDegrees = degrees.zRotateDegrees * M_PI / 180;
    for (int i = 0; i < dots.coordsNumb; i++) RotateZ(dots.shapeCoords[i], centerDot, newDegrees);
    return OK;
}

int Rotate(dotsStruct& dots, const dot& centerDot, const RotateCoords_t& rotateCoords)
{
    int error = OK;
    if (dots.shapeCoords == nullptr && dots.coordsNumb != 0) return INCORRECT_ARG;
    if ((error = RotateXAxis(dots, centerDot, rotateCoords)) != OK) return error;
    if ((error = RotateYAxis(dots, centerDot, rotateCoords)) != OK) return error;
    if ((error = RotateZAxis(dots, centerDot, rotateCoords)) != OK) return error;
    return error;
}

int ZoomDot(dot& zoomDot, const dot& centerDot, const ScaleCoords_t& scaleCoords)
{
    zoomDot.coordX = centerDot.coordX + (zoomDot.coordX - centerDot.coordX) * scaleCoords.xScaleKoef;
    zoomDot.coordY = centerDot.coordY + (zoomDot.coordY - centerDot.coordY) * scaleCoords.yScaleKoef;
    zoomDot.coordZ = centerDot.coordZ + (zoomDot.coordZ - centerDot.coordZ) * scaleCoords.zScaleKoef;
    return OK;
}


int Zoom(dotsStruct& dots, const dot& centerDot, const ScaleCoords_t& scaleCoords) {
    if (dots.shapeCoords == nullptr && dots.coordsNumb != 0) return INCORRECT_ARG;
    int error = OK;
    for (int i = 0; i < dots.coordsNumb && error == OK; i++)
        error = ZoomDot(dots.shapeCoords[i], centerDot, scaleCoords);
    return error;
}