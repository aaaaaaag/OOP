//
// Created by denis on 04.03.2021.
//

#include <Errors.h>
#include "Logic.h"
#include "DotFileIO.h"
#include "DotStructUtils.h"

int ApplyAction(UtilsStruct& data, CanvasStruct& graphic, const choose& userChoose)
{
    if (!graphic.canvas) return NULL_POINTER;
    static mainShape_t mainShape = initShape();
    int operationStatus = OK;
    auto updateCoordData = data.coordChangeData;
    switch (userChoose) {
        case GetShapeFromFile:
            operationStatus = LoadShapeFromFile(mainShape, data.fileData);
            break;
        case MoveShape:
            operationStatus = Move(mainShape, updateCoordData.moveCoords);
            break;
        case RotateShape:
            operationStatus = Rotate(mainShape, updateCoordData.rotateCoords);
            break;
        case ScaleShape:
            operationStatus = Zoom(mainShape, updateCoordData.scaleCoords);
            break;
        case Quit:
            operationStatus = freeAll(mainShape);
            break;
        case Draw:
            operationStatus = FillGraphicsWidget(graphic, mainShape);
            break;
    }
    return operationStatus;
}
