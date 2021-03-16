//
// Created by denis on 04.03.2021.
//

#include <Errors.h>
#include "Logic.h"
#include "DotFileIO.h"
#include "DotStructUtils.h"

int ApplyAction(utilData& data, CanvasStruct& canvas, choose userChoose)
{
    if (!canvas.canvas)
        return NULL_POINTER;
    static mainShape_t mainShape;
    int error = OK;
    if (mainShape.shapeCoords == nullptr)
        error = initShape(mainShape);

    switch (userChoose) {
        case GetShapeFromFile:
            error = GetDotsFromFile(data.filename, mainShape);
            if (error == OK)
                error = SetShapeCenter(mainShape, data.centerDot);
            break;
        case MoveShape:
            error = Move(mainShape, data.centerDot, data.moveCoords);
            break;
        case RotateShape:
            error = Rotate(mainShape, data.centerDot, data.rotateCoords);
            break;
        case ScaleShape:
            error = Zoom(mainShape, data.centerDot, data.scaleCoords);
            break;
        case Quit:
            error = freeAll(mainShape);
            break;
    }
    if (error == OK)
        error = FillGraphicsWidget(canvas, mainShape);
    return error;
}
