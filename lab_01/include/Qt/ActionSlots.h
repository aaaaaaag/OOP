//
// Created by denis on 08.03.2021.
//

#ifndef LAB_01_OOP_ACTIONSLOTS_H
#define LAB_01_OOP_ACTIONSLOTS_H

#include "QWidget"
#include "DotStruct.h"
#include "UtilStruct.h"
#include "Qt/CanvasStruct.h"

class ActionSlots: public QObject {
public slots:

    ActionSlots(UtilsStruct *data, CanvasStruct& paint);

    void Move();

    void Rotate();

    void Scale();

    void Load();

    CanvasStruct *GetCanvas();

    UtilsStruct *m_data;

private:
    CanvasStruct m_pPaint;

};


#endif //LAB_01_OOP_ACTIONSLOTS_H
