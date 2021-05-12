#include "AddCameraCommand.h"

#include <utility>

namespace commands {

AddCameraCommand::AddCameraCommand(std::string name): m_name(std::move(name)) {}

void AddCameraCommand::execute(std::shared_ptr<intermediary::Intermediary> intermediary) {
    intermediary->addCamera(m_name);
}

} // namespace commands
