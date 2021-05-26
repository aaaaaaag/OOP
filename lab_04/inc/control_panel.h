#pragma once

#include <QObject>
#include <QVector>
#include <constants.h>
enum panelState {
    FREE = 0,
    BUSY };

class ControlPanel : public QObject {
    Q_OBJECT

public:
    explicit ControlPanel(QObject *parent = nullptr);
    void setNewFloorTarget(int floor);

signals:
    void setFloorTarget(int floor, direction dir);

public slots:
    void achievedFloor(int floor);
    void passedFloor(int floor);

private:
    bool isNextTargetExist(int &floor);
    void findNewTarget();

    int m_currentFloor;
    int m_currentTarget = -1;

    QVector<bool> m_vIsFloorTarget;
    panelState m_currentPanelState;
    direction m_currentDirection;
};
