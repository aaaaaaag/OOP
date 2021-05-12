#include "SceneManager.h"

#include <utility>

namespace scene {

SceneManager::SceneManager(): m_pScene(new Scene()){}

std::shared_ptr<Scene> SceneManager::getScene() {
    return m_pScene;
}

void SceneManager::setCurrentCamera(const std::string& cameraName) {
    m_pCurrentCamera = m_pScene->getCamera(cameraName);
}

std::shared_ptr<Camera> SceneManager::getCurrentCamera() {
    if (!m_pCurrentCamera)
        throw exceptions::CameraLackException();
    return m_pCurrentCamera;
}

} // namespace scene
