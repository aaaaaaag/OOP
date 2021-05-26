#include <cabin.h>

#include <QString>

#include <QDebug>

Cabin::Cabin(QObject *parent): QObject(parent), m_currentFloor(1), m_target(-1), m_newTarget(false),
                               m_currentCabinState(STOP), m_currentDirection(STAY)
                                {
    m_crossingFloorTimer.setSingleShot(true);

    QObject::connect(this, SIGNAL(cabinCalled()), &m_doors, SLOT(startClosing()));
    QObject::connect(this, SIGNAL(cabinReachedTarget(int)), this,
                     SLOT(cabinStopping()));
    QObject::connect(this, SIGNAL(cabinStopped(int)), &m_doors,
                     SLOT(startOpening()));
    QObject::connect(&m_doors, SIGNAL(closedDoors()), this, SLOT(cabinMove()));
    QObject::connect(&m_crossingFloorTimer, SIGNAL(timeout()), this,
                     SLOT(cabinMove()));
}

void Cabin::cabinMove() {
    if (m_newTarget && m_currentCabinState == WAIT) {
        m_currentCabinState = MOVE;

        if (m_currentFloor == m_target)
            emit cabinReachedTarget(m_currentFloor);
        else
            m_crossingFloorTimer.start(CROSSING_FLOOR);
        return;
    }

    if (m_currentCabinState == MOVE) {
        m_currentCabinState = MOVE;
        m_currentFloor += m_currentDirection;

        if (m_currentFloor == m_target)
            emit cabinReachedTarget(m_currentFloor);
        else {
            emit cabinCrossingFloor(m_currentFloor, m_currentDirection);
            m_crossingFloorTimer.start(CROSSING_FLOOR);
        }
    }
}

void Cabin::cabinStopping() {
    if (m_currentCabinState != MOVE)
      return;

    m_currentCabinState = STOP;
    qDebug() << "Cabin stopped at floor " << QString::number(m_currentFloor) << ".";
    emit cabinStopped(m_currentFloor);
}

void Cabin::cabinCall(int floor, direction dir) {
    if (m_currentCabinState != STOP) {
        if (dir == m_currentDirection) m_target = floor;
        qDebug() << "next target: " << m_target << ".";
        return;
    }

    m_newTarget = true;
    m_currentCabinState = WAIT;
    m_target = floor;
    qDebug() << "next target: " << m_target << ".";
    m_currentDirection = dir;
    emit cabinCalled();
}
