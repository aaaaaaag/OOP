#ifndef LAB4_SCENE_H
#define LAB4_SCENE_H

#include <unordered_map>
#include <memory>
#include "../exceptions/CameraLackException.h"
#include "../exceptions/ObjectSearchException.h"
#include "../objects/Composite.h"
#include "../objects/Model.h"
#include "../objects/Camera.h"

namespace scene {

using namespace objects;

class Scene {
public:
    Scene();

    void addModel(const std::shared_ptr<Model>& obj);
    void addCamera(const std::shared_ptr<Camera>& obj);
    void removeModel(const std::shared_ptr<Object>& obj);
    void removeCamera(const std::string& cameraName);

    std::shared_ptr<Composite> getModelsComposite();
    std::shared_ptr<Camera> getCamera(const std::string& cameraName);
    std::shared_ptr<Object> getObject(const std::string& modelName);
    std::vector<std::shared_ptr<Object>> getObjects();
private:
    std::shared_ptr<Composite> m_objects;
    std::unordered_map<std::string, std::shared_ptr<Camera>> m_cameras;//TODO try to make map
};

} // namespace scene

#endif //LAB4_SCENE_H
