//
// Created by denis on 09.03.2021.
//

#ifndef LAB_01_OOP_CANVASWIDGET_H
#define LAB_01_OOP_CANVASWIDGET_H

#include "QGraphicsScene"
#include "QGraphicsView"

class CanvasWidget: public QGraphicsView {
public:

    CanvasWidget();

    void DrawLine(double x1, double y1, double x2, double y2);

    void Clear();

private:

    QPen *mainPen;
    QGraphicsScene *scene;

};


#endif //LAB_01_OOP_CANVASWIDGET_H
