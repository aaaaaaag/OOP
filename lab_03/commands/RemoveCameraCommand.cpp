#include "RemoveCameraCommand.h"

#include <utility>

namespace commands {

RemoveCameraCommand::RemoveCameraCommand(std::string objectName):
        m_objectName(std::move(objectName)) {}

void RemoveCameraCommand::execute(std::shared_ptr<intermediary::Intermediary> intermediary) {
    intermediary->removeCamera(m_objectName);
}

} // namespace commands
