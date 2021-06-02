#include <cabin.h>

#include <QString>

#include <QDebug>

Cabin::Cabin(QObject *parent): QObject(parent), m_currentFloor(1), m_target(-1), m_hasTarget(false),
                               m_currentCabinState(STOP), m_currentDirection(STAY)
                                {
    m_crossingFloorTimer.setSingleShot(true);

    QObject::connect(this, SIGNAL(cabinCalled()), &m_doors, SLOT(opening()));
    QObject::connect(this, SIGNAL(cabinReachedTarget(int)), this,
                     SLOT(cabinStopping()));
    QObject::connect(this, SIGNAL(cabinStopped(int)), &m_doors, SLOT(opening()));
    QObject::connect(&m_doors, SIGNAL(closedDoors()), this, SLOT(cabinFindTarget()));
    QObject::connect(&m_crossingFloorTimer, SIGNAL(timeout()), this,
                     SLOT(cabinMove()));
}

void Cabin::cabinFindTarget() {
    if (m_currentCabinState != WAIT && m_currentCabinState != STOP)
        return;

    if (m_currentCabinState == WAIT && m_currentFloor == m_target)
        m_currentCabinState = STOP;
    else
        m_currentCabinState = MOVE;

    cabinMove();
}

void Cabin::cabinMove() {
    if (m_currentCabinState == MOVE) {
        if (m_currentFloor == m_target) {
            emit cabinReachedTarget(m_currentFloor);
            return;
        }
        else {
            emit cabinCrossingFloor(m_currentFloor, m_currentDirection);
            m_crossingFloorTimer.start(CROSSING_FLOOR);
        }

        m_currentFloor += m_currentDirection;
    }
}

void Cabin::cabinStopping() {
    if (m_currentCabinState != MOVE)
      return;

    m_currentCabinState = WAIT;
    qDebug() << "Cabin stopped at floor " << QString::number(m_currentFloor) << ".";
    emit cabinStopped(m_currentFloor);
}

void Cabin::cabinCall(int floor, direction dir) {
    m_target = floor;
    m_currentDirection = dir;
    if (m_currentCabinState == WAIT && m_target == m_currentFloor)
        emit cabinCalled();
    else if (m_currentCabinState == STOP)
        cabinFindTarget();
}



