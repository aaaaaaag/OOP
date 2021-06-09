#include <QDebug>
#include "../inc/cabin.hpp"

cabin::cabin(QObject *parent) : QObject(parent)
{
    m_crossFloorTimer.setSingleShot(true);

    QObject::connect(&m_doors, SIGNAL(doors_closed()), this, SLOT(stay_closed()));
    QObject::connect(this, SIGNAL(cabin_stopped()), &m_doors, SLOT(start_opening()));
    QObject::connect(&m_crossFloorTimer, SIGNAL(timeout()), this, SLOT(move()));
    QObject::connect(this, SIGNAL(cabin_called()), this, SLOT(move()));
}

void cabin::move()
{
    if (m_state != START_MOVING && m_state != MOVE)
        return;

    if (m_state == MOVE)
        m_currentFloor += m_currentDirection;

    m_state = MOVE;
    emit cabin_crossed_floor(m_currentFloor, m_currentDirection);
    m_crossFloorTimer.start(CROSS_FLOOR_TIME);
}

void cabin::stay_not_closed()
{
    if (m_state != MOVE && m_state != WAIT)
        return;

    if (m_state == MOVE)
        qDebug() << "Cabin move......  passed floor: " << m_currentFloor;

    m_state = WAIT;
    emit cabin_stopped();
}

void cabin::stay_closed()
{
    if (m_state != WAIT)
        return;

    m_state = STOP;
    qDebug() << "Cabin waiting";

    emit cabin_stay_closed(m_currentFloor);
}

void cabin::start_moving(long floor, const direction &dir)
{
    if (m_state != STOP)
        return;

    m_state = START_MOVING;
    m_currentDirection = dir;

    emit cabin_called();
}
