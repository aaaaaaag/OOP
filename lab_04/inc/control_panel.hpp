#ifndef CONTROL_PANEL_H
#define CONTROL_PANEL_H

#include <QObject>
#include <vector>
#include "direction.hpp"

class control_panel : public QObject
{
    Q_OBJECT

    enum panel_state
    {
        FREE,
        BUSY,
    };

public:
    explicit control_panel(QObject *parent = nullptr);
    void new_target(long floor);

public slots:
    void busy(long floor, const direction &_direction);
    void free(long floor);

signals:
    void cabin_achieved_target();
    void panel_new_target(long floor, const direction &_direction);

private:
    void next_target();
    panel_state m_state = FREE;
    long m_currentFloor = 1;
    long m_currentTarget = -1;
    direction m_currentDirection = STAY;
    std::vector<bool> m_vIsTarget;

};

#endif // CONTROL_PANEL_H
