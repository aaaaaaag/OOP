//
// Created by denis on 04.03.2021.
//

#include <Errors.h>
#include "Logic.h"
#include "DotFileIO.h"
#include "DotStructUtils.h"



int applyAction(choose userChoose, mainShape_t& mainShape)
{
    int error = OK;
    switch (userChoose) {
        case GetShapeFromFile:
            mainShape = GetDotsFromFile("123", error);
        case SetShapeToFile:
            break;
        case MoveShape:
            Move(mainShape);
        case RotateShape:
            Rotate(mainShape);
        case ScaleShape:
            Zoom(mainShape);
    }
}
