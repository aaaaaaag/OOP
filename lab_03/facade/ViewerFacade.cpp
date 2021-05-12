#include "ViewerFacade.h"

namespace facade {

ViewerFacade::ViewerFacade(): m_pIntermediary(new Intermediary) {}

void ViewerFacade::execCommand(commands::BaseCommand *command) {
    if (!command) return;
    command->execute(m_pIntermediary);
}

} // namespace facade
