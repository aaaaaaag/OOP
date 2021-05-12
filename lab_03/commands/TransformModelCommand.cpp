#include "TransformModelCommand.h"

#include <utility>

namespace commands {

TransformModelCommand::TransformModelCommand(std::string objectName, math::Point move, math::Point scale, math::Point rotate):
        m_objectName(std::move(objectName)), m_moveCoords(move), m_scaleCoords(scale), m_rotateCoords(rotate) {}

void TransformModelCommand::execute(std::shared_ptr<intermediary::Intermediary> intermediary) {
    intermediary->transformModel(m_objectName, m_moveCoords, m_scaleCoords, m_rotateCoords);
}

} // namespace commands
