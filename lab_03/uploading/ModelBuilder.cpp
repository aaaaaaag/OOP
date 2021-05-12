#include "ModelBuilder.h"

#include <memory>
#include <utility>

namespace uploading {

void ModelBuilder::reset(std::string name) {
    m_pModel.reset();
    m_pModel = std::make_shared<Model>(std::move(name));
}

void ModelBuilder::addPoint(math::Point &point) {
    m_pModel->addPoint(point);
}

void ModelBuilder::addEdge(size_t first, size_t second) {
    m_pModel->addEdge(first, second);
}

std::shared_ptr<objects::Model> ModelBuilder::getResult() {
    return m_pModel;
}

} // namespace uploading
