//
// Created by denis on 08.03.2021.
//

#ifndef LAB_01_OOP_DOTACTIONSTRUCT_H
#define LAB_01_OOP_DOTACTIONSTRUCT_H

typedef struct moveCoords
{
    double xMove;
    double yMove;
    double zMove;
} moveCoords_t;

typedef struct rotateCoords
{
    double xRotateDegrees;
    double yRotateDegrees;
    double zRotateDegrees;
} rotateCoords_t;

typedef struct scaleCoords
{
    double xScaleKoef;
    double yScaleKoef;
    double zScaleKoef;
} scaleCoords_t;

#endif //LAB_01_OOP_DOTACTIONSTRUCT_H
