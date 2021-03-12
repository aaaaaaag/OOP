//
// Created by denis on 08.03.2021.
//

#include "Qt/ActionSlots.h"
#include "Logic.h"

ActionSlots::ActionSlots(utilData *data, CanvasStruct& paint): m_data(data), m_pPaint(paint) {
}

void ActionSlots::Move() {
    ApplyAction(*m_data, m_pPaint, choose::MoveShape);
}

void ActionSlots::Rotate() {
    ApplyAction(*m_data, m_pPaint,choose::RotateShape);
}

void ActionSlots::Scale() {
    ApplyAction(*m_data, m_pPaint, choose::ScaleShape);
}

void ActionSlots::Load() {
    ApplyAction(*m_data, m_pPaint, choose::GetShapeFromFile);
    int i = 0;
}

CanvasStruct *ActionSlots::GetCanvas() {
    return &m_pPaint;
}
