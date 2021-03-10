//
// Created by denis on 04.03.2021.
//

#include <Errors.h>
#include "Logic.h"
#include "DotFileIO.h"
#include "DotStructUtils.h"


int ApplyAction(choose userChoose, utilData& data, CanvasWidget *widget)
{
    if (!widget)
        return NULL_POINTER;
    static mainShape_t mainShape;
    int error = OK;
    switch (userChoose) {
        case GetShapeFromFile:
            mainShape = GetDotsFromFile(data.filename, error);
            SetShapeCenter(mainShape, data);
            break;
        case MoveShape:
            Move(mainShape, data);
            break;
        case RotateShape:
            Rotate(mainShape, data);
            break;
        case ScaleShape:
            Zoom(mainShape, data);
            break;
        case Quit:
            freeAll(mainShape);
            break;
    }
    if (error == OK)
        FillGraphicsWidget(widget, &mainShape);
    return error;
}
