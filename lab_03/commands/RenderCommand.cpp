#include "RenderCommand.h"

#include <utility>

namespace commands {

RenderCommand::RenderCommand(std::shared_ptr<render::BaseDrawer> drawer):
        m_pDrawer(std::move(drawer)) {}

void RenderCommand::execute(std::shared_ptr<Intermediary> intermediary) {
    intermediary->draw(m_pDrawer);
}

} // namespace commands
