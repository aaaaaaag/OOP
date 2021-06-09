#include <QDebug>
#include "../inc/control_panel.hpp"

control_panel::control_panel(QObject *parent) : QObject(parent)
{
    for (size_t i = 0; i < 10; i++)
    {
        m_vIsTarget.push_back(false);
    }

    QObject::connect(this, SIGNAL(panel_new_target(long, direction)), this, SLOT(busy(long, direction)));
}

void control_panel::new_target(long floor)
{
    qDebug() << "Get new floor target: " << floor;
    m_vIsTarget[floor - 1] = true;

    next_target();
}

void control_panel::next_target()
{
    if (m_vIsTarget[m_currentFloor - 1])
        emit panel_new_target(m_currentFloor, STAY);
    else if (m_state == FREE)
    {
        for (size_t i = 0; i < m_vIsTarget.size(); i++)
            if (m_vIsTarget[i])
            {
                if (i + 1 > m_currentFloor)
                    emit panel_new_target(i + 1, UP);
                else
                    emit panel_new_target(i + 1, DOWN);
                break;
            }
    }
}

void control_panel::busy(long floor, const direction &_direction)
{
    if (m_state == FREE)
    {
        m_state = BUSY;
        m_currentTarget = floor;
        m_currentDirection = _direction;
    }
    else if (m_state == BUSY)
    {
        m_currentFloor = floor;
        if (m_vIsTarget[floor - 1])
        {
            m_vIsTarget[floor - 1] = false;
            emit cabin_achieved_target();
        }
        else
            qDebug() << "Passed floor: " << floor;
    }
}

void control_panel::free(long floor)
{
    m_state = FREE;
    m_currentFloor = floor;
    next_target();
}
