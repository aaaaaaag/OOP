#include "AddModelCommand.h"

#include <utility>

namespace commands {

AddModelCommand::AddModelCommand(std::string filename, std::string modelName):
        m_fileName(std::move(filename)), m_modelName(std::move(modelName)) {}

void AddModelCommand::execute(std::shared_ptr<intermediary::Intermediary> intermediary) {
    intermediary->addModel(m_fileName, m_modelName);
}

} // namespace commands
