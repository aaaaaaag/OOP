#include "YawCameraCommand.h"

#include <utility>

namespace commands {

YawCameraCommand::YawCameraCommand(std::string objectName, double angle):
        m_objectName(std::move(objectName)), m_rotation(0, 0, angle) {}

void YawCameraCommand::execute(std::shared_ptr<intermediary::Intermediary> intermediary) {
    math::Point moving(0, 0, 0);
    intermediary->transformCamera(m_objectName, moving, m_rotation);
}

} // namespace commands
