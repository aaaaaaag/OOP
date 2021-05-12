#include "Scene.h"

namespace scene {

Scene::Scene(): m_objects(new Composite) {}

void Scene::removeModel(const std::shared_ptr<Object>& obj) {
    auto i = m_objects->getIndex(obj);
    if (i > -1)
        m_objects->remove(size_t(i));
}

void Scene::removeCamera(const std::string& cameraName) {
    m_cameras.erase(cameraName);
}

std::shared_ptr<Composite> Scene::getModelsComposite() {
    return m_objects;
}

std::shared_ptr<Camera> Scene::getCamera(const std::string& cameraName) {
    return m_cameras.at(cameraName);
}

std::shared_ptr<Object> Scene::getObject(const std::string& modelName) {
    auto objects = m_objects->getObjects();
    for (auto &obj: objects) {
        if (obj->getName() == modelName)
            return obj;
    }

    throw exceptions::ObjectSearchException();
}

void Scene::addModel(const std::shared_ptr<Model>& obj) {
    m_objects->add(obj);
}

void Scene::addCamera(const std::shared_ptr<Camera>& obj) {
    m_cameras.emplace(obj->getName(), obj);
}

std::vector<std::shared_ptr<Object>> Scene::getObjects() {
    return m_objects->getObjects();
}

} // namespace scene
