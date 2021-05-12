#include "MoveCameraCommand.h"

#include <utility>

namespace commands {

MoveCameraCommand::MoveCameraCommand(std::string objectName, math::Point move):
        m_objectName(std::move(objectName)), m_moveCoords(move) {}

void MoveCameraCommand::execute(std::shared_ptr<intermediary::Intermediary> intermediary) {
    math::Point rotation(0, 0, 0);
    intermediary->transformCamera(m_objectName, m_moveCoords, rotation);
}

} // namespace commands
