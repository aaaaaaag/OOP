#include "RollCameraCommand.h"

#include <utility>

namespace commands {

RollCameraCommand::RollCameraCommand(std::string objectName, double angle):
        m_objectName(std::move(objectName)), m_rotationData(angle, 0, 0) {}

void RollCameraCommand::execute(std::shared_ptr<intermediary::Intermediary> intermediary) {
    math::Point moving(0, 0, 0);
    intermediary->transformCamera(m_objectName, moving, m_rotationData);
}

} // namespace commands
