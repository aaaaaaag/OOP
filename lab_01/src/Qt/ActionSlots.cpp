//
// Created by denis on 08.03.2021.
//

#include <iostream>
#include "Qt/ActionSlots.h"
#include "Logic.h"

ActionSlots::ActionSlots(mainShape_t &shape, utilData &data, CanvasWidget *paint): m_shape(&shape), m_data(&data), m_pPaint(paint) {
}

void ActionSlots::Move() {
    ApplyAction(choose::MoveShape, *m_shape, *m_data, m_pPaint);
    m_pPaint->repaint();
}

void ActionSlots::Rotate() {
    ApplyAction(choose::RotateShape, *m_shape, *m_data, m_pPaint);
    m_pPaint->repaint();
}

void ActionSlots::Scale() {
    ApplyAction(choose::RotateShape, *m_shape, *m_data, m_pPaint);
    m_pPaint->repaint();
}

void ActionSlots::Load() {
    ApplyAction(choose::GetShapeFromFile, *m_shape, *m_data, m_pPaint);
    m_pPaint->repaint();
    for (int i = 0; i < m_shape->coordsNumb; i++)
    {
        auto dot = m_shape->shapeCoords[i];
        std::cout << "Dot coords" << std::endl;
        std::cout << "X: " << dot.coords.coordX << std::endl;
        std::cout << "Y: " << dot.coords.coordY << std::endl;
        std::cout << "Z: " << dot.coords.coordZ << std::endl;
        std::cout << "Links" << std::endl;
        for (int j = 0; j < dot.linksNumb; j++)
        {
            std::cout << dot.linkNodesNumbers[j] << std::endl;
        }
    }
}

utilData *ActionSlots::GetUtilData() {
    return m_data;
}

void ActionSlots::SetUtilsData(utilData *inData) {
    m_data = inData;
}

CanvasWidget *ActionSlots::GetCanvas() {
    return m_pPaint;
}
