#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "../BaseManager.h"
#include "../exceptions/CameraLackException.h"
#include "Scene.h"

namespace scene {

class SceneManager: public BaseManager {
public:
    SceneManager();

    std::shared_ptr<Scene> getScene();
    void setCurrentCamera(const std::string& cameraName);
    std::shared_ptr<objects::Camera> getCurrentCamera();
private:
    std::shared_ptr<Scene> m_pScene;
    std::shared_ptr<objects::Camera> m_pCurrentCamera;
};

} // namespace scene

#endif // SCENE_MANAGER_H
