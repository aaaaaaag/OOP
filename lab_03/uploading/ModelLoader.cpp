#include "ModelLoader.h"

namespace uploading {

ModelLoader::ModelLoader(BaseLoader *loader): m_pLoader(loader), m_pBuilder(new ModelBuilder())
{}

std::shared_ptr<objects::Model> ModelLoader::loadModel(std::string sourceName, std::string modelName) {
    m_pLoader->open(sourceName);
    m_pBuilder->reset(modelName);

    std::pair<size_t, size_t> modelInfo = m_pLoader->readModelInfo();

    for (size_t i = 0; i < modelInfo.first; i++) {
        math::Point p = m_pLoader->readPoint();
        m_pBuilder->addPoint(p);
    }

    for (size_t i = 0; i < modelInfo.second; i++) {
        std::pair<size_t, size_t> edgeInfo = m_pLoader->readEdgeInfo();
        m_pBuilder->addEdge(edgeInfo.first, edgeInfo.second);
    }

    m_pLoader->close();
    return m_pBuilder->getResult();
}

} // namespace uploading
