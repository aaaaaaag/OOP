#pragma once

#include <QObject>

#include <constants.h>
#include <control_panel.h>
#include <door.h>

enum cabin_state {
    MOVE = 0,
    WAIT,
    STOP
};

class Cabin : public QObject {
    Q_OBJECT

public:
    explicit Cabin(QObject *parent = nullptr);

signals:
    void cabinCalled();
    void cabinCrossingFloor(int floor, direction d);
    void cabinReachedTarget(int floor);
    void cabinStopped(int floor);

public slots:
    void cabinMove();
    void cabinStopping();
    void cabinCall(int floor, direction dir);
    void cabinFindTarget();

private:
    int m_currentFloor;
    int m_target;
    bool m_hasTarget;
    cabin_state m_currentCabinState;
    direction m_currentDirection;
    Doors m_doors;
    QTimer m_crossingFloorTimer;
};
