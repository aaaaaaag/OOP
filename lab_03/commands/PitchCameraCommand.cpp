#include "PitchCameraCommand.h"

#include <utility>

namespace commands {

PitchCameraCommand::PitchCameraCommand(std::string objectName, double angle):
        m_objectName(std::move(objectName)), m_rotationData(0, angle, 0) {}

void PitchCameraCommand::execute(std::shared_ptr<intermediary::Intermediary> intermediary) {
    math::Point moving(0, 0, 0);
    intermediary->transformCamera(m_objectName, moving, m_rotationData);
}

} // namespace commands
