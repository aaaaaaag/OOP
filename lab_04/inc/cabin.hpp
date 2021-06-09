#ifndef CABIN_H
#define CABIN_H

#include <QObject>
#include <QTimer>
#include "doors.hpp"

#include "direction.hpp"

#define CROSS_FLOOR_TIME 3000

class cabin : public QObject
{
    Q_OBJECT

    enum cabin_state
    {
        STOP,
        START_MOVING,
        MOVE,
        WAIT,
    };

public:
    explicit cabin(QObject *parent = nullptr);

signals:
    void cabin_called();
    void cabin_stopped();
    void cabin_crossed_floor(long, const direction &_direction);
    void cabin_stay_closed(long floor);

public slots:
    void move();
    void stay_not_closed();
    void stay_closed();
    void start_moving(long floor, const direction &dir);

private:
    long m_currentFloor = 1;
    direction m_currentDirection = STAY;
    doors m_doors;
    cabin_state m_state = STOP;
    QTimer m_crossFloorTimer;
};

#endif // CABIN_H
