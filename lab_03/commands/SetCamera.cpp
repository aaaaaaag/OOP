#include "SetCamera.h"

#include <utility>

namespace commands {

SetCameraCommand::SetCameraCommand(std::string name): m_name(std::move(name)) {}

void SetCameraCommand::execute(std::shared_ptr<intermediary::Intermediary> intermediary) {
    intermediary->setCamera(m_name);
}

} // namespace commands
