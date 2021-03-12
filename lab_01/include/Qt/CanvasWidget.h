//
// Created by denis on 09.03.2021.
//

#ifndef LAB_01_OOP_CANVASWIDGET_H
#define LAB_01_OOP_CANVASWIDGET_H

#include "QGraphicsScene"
#include "QGraphicsView"
#include "DotStruct.h"

class CanvasWidget: public QGraphicsView {
public:

    CanvasWidget();

    void DrawLine(dot from, dot to);

    void Clear();

private:

    QPen *mainPen;
    QGraphicsScene *scene;

};


#endif //LAB_01_OOP_CANVASWIDGET_H
