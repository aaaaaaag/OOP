//
// Created by denis on 08.03.2021.
//

#include "Qt/ActionSlots.h"
#include "Logic.h"

ActionSlots::ActionSlots(UtilsStruct *data, CanvasStruct& paint): m_data(data), m_pPaint(paint) {
}

void ActionSlots::Move() {
    ApplyAction(*m_data, m_pPaint, choose::MoveShape);
    ApplyAction(*m_data, m_pPaint, choose::Draw);
}

void ActionSlots::Rotate() {
    ApplyAction(*m_data, m_pPaint,choose::RotateShape);
    ApplyAction(*m_data, m_pPaint, choose::Draw);
}

void ActionSlots::Scale() {
    ApplyAction(*m_data, m_pPaint, choose::ScaleShape);
    ApplyAction(*m_data, m_pPaint, choose::Draw);
}

void ActionSlots::Load() {
    ApplyAction(*m_data, m_pPaint, choose::GetShapeFromFile);
    ApplyAction(*m_data, m_pPaint, choose::Draw);
}

CanvasStruct *ActionSlots::GetCanvas() {
    return &m_pPaint;
}
