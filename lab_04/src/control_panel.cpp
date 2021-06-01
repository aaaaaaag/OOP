#include <control_panel.h>
#include <QDebug>

ControlPanel::ControlPanel(QObject *parent)
    : QObject(parent), m_currentFloor(1), m_currentTarget(-1),
      m_vIsFloorTarget(NUM_FLOORS, false), m_currentPanelState(FREE), m_currentDirection(STAY) {}

void ControlPanel::setNewFloorTarget(int floor) {
    m_currentPanelState = BUSY;
    m_vIsFloorTarget[floor - 1] = true;

    if (m_currentTarget == -1)
      m_currentTarget = floor;

    if ((m_currentDirection == UP && floor < m_currentTarget && floor > m_currentFloor) ||
      (m_currentDirection == DOWN && floor > m_currentTarget && floor < m_currentFloor)) {
      m_currentTarget = floor;
    }

    if (m_currentFloor > m_currentTarget)
        m_currentDirection = DOWN;
    else
        m_currentDirection = UP;

    emit setFloorTarget(m_currentTarget, m_currentDirection);
}

void ControlPanel::achievedFloor(int floor) {
    if (m_currentPanelState != BUSY)
        return;

    m_currentFloor = floor;
    m_vIsFloorTarget[floor - 1] = false;

    if (m_currentFloor == m_currentTarget) {
        m_currentTarget = -1;
        findNewTarget();
    }

    if (isNextTargetExist(floor)) {
        m_currentDirection = (m_currentFloor > m_currentTarget) ? DOWN : UP;
        emit setFloorTarget(floor, m_currentDirection);
    }
    else
        m_currentPanelState = FREE;
}

void ControlPanel::passedFloor(int floor) {
    m_currentFloor = floor;
    qDebug() << "Lift moving... passed floor:" << floor;
}

void ControlPanel::findNewTarget() {
    int state = false;

    if (m_currentDirection == UP) {
        for (int i = NUM_FLOORS; i >= 1 && !state; i--) {
            if (m_vIsFloorTarget[i - 1]) {
                state = true;
                m_currentTarget = i;
            }
        }
        return;
    }

    for (int i = 1; i <= NUM_FLOORS && !state; i++) {
        if (m_vIsFloorTarget[i - 1]) {
            state = true;
            m_currentTarget = i;
        }
    }
}

bool ControlPanel::isNextTargetExist(int &floor) {
    bool state = false;
    if (m_currentTarget > m_currentFloor) {
        bool flag = true;
        for (int i = m_currentFloor; i <= NUM_FLOORS && flag; i++) {
            if (m_vIsFloorTarget[i - 1]) {
                floor = i;
                state = true;
                flag = false;
            }
        }
    }
    else {
        bool flag = true;
        for (int i = m_currentFloor; i >= 1 && flag; i--) {
            if (m_vIsFloorTarget[i - 1]) {
                floor = i;
                state = true;
                flag = false;
            }
        }
    }
    return state;
}
