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

void CanvasWidget::DrawLine(dot from, dot to) {
    this->scene->addLine(from.coordX, from.coordY, to.coordX, to.coordY, *mainPen);
}

void CanvasWidget::Clear() {
    scene->clear();
}


