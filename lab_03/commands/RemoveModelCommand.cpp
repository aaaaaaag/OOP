#include "RemoveModelCommand.h"

#include <utility>

namespace commands {

RemoveModelCommand::RemoveModelCommand(std::string objectName):
        m_objectName(std::move(objectName)) {}

void RemoveModelCommand::execute(std::shared_ptr<intermediary::Intermediary> intermediary) {
    intermediary->removeModel(m_objectName);
}

} // namespace commands
