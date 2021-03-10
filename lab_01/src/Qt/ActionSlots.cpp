//
// Created by denis on 08.03.2021.
//

#include "Qt/ActionSlots.h"
#include "Logic.h"

ActionSlots::ActionSlots(utilData *data, CanvasWidget *paint): m_data(data), m_pPaint(paint) {
}

void ActionSlots::Move() {
    ApplyAction(choose::MoveShape, *m_data, m_pPaint);
}

void ActionSlots::Rotate() {
    ApplyAction(choose::RotateShape, *m_data, m_pPaint);
}

void ActionSlots::Scale() {
    ApplyAction(choose::ScaleShape, *m_data, m_pPaint);
}

void ActionSlots::Load() {
    ApplyAction(choose::GetShapeFromFile, *m_data, m_pPaint);
    int i = 0;
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
