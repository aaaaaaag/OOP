//
// Created by denis on 08.03.2021.
//

#ifndef LAB_01_OOP_ACTIONSLOTS_H
#define LAB_01_OOP_ACTIONSLOTS_H

#include "QWidget"
#include "DotStruct.h"
#include "UtilStruct.h"
#include "QPainter"

class ActionSlots: public QObject {
public slots:

    ActionSlots(mainShape_t& shape, utilData &data, QWidget *paint);

    void Move();

    void Rotate();

    void Scale();

    utilData* GetUtilData();

    void SetUtilsData(utilData *inData);

private:
    QWidget *m_pPaint;
    mainShape_t *m_shape;
    utilData *m_data;


};


#endif //LAB_01_OOP_ACTIONSLOTS_H
