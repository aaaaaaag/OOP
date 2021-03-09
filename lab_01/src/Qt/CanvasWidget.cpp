//
// Created by denis on 09.03.2021.
//

#include "Qt/CanvasWidget.h"

CanvasWidget::CanvasWidget() {
    setMaximumSize(600, 600);
    setMinimumSize(600, 600);
    scene = new QGraphicsScene;
    mainPen = new QPen(QColor(0, 0, 0));
    setScene(scene);
}

void CanvasWidget::DrawLine(double x1, double y1, double x2, double y2) {
    this->scene->addLine(x1, y1, x2, y2, *mainPen);
}

void CanvasWidget::Clear() {
    scene->clear();
}


