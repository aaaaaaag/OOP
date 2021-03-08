//
// Created by denis on 04.03.2021.
//

#include <Errors.h>
#include "Logic.h"
#include "DotFileIO.h"
#include "DotStructUtils.h"



int applyAction(choose userChoose, mainShape_t& mainShape, utilData data)
{
    int error = OK;
    switch (userChoose) {
        case GetShapeFromFile:
            mainShape = GetDotsFromFile(data.filename, error);
            break;
        case SetShapeToFile:
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
    }
    return error;
}
