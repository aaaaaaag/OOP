//
// Created by denis on 04.03.2021.
//

#include <Errors.h>
#include "Logic.h"
#include "DotFileIO.h"
#include "DotStructUtils.h"


int ApplyAction(utilData& data, CanvasWidget *widget, choose userChoose)
{
    if (!widget)
        return NULL_POINTER;
    static mainShape_t mainShape;
    int error = OK;
    switch (userChoose) {
        case GetShapeFromFile:
            error = GetDotsFromFile(data.filename, mainShape);
            if (error == OK)
                error = SetShapeCenter(mainShape, data);
            break;
        case MoveShape:
            error = Move(mainShape, data);
            break;
        case RotateShape:
            error = Rotate(mainShape, data);
            break;
        case ScaleShape:
            error = Zoom(mainShape, data);
            break;
        case Quit:
            freeAll(mainShape);
            break;
    }
    if (error == OK)
        error = FillGraphicsWidget(widget, &mainShape);
    return error;
}
