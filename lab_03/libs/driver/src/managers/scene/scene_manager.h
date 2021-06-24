#pragma once

#include <scene/scene.h>
#include <managers/base_manager.h>

class SceneManager : public BaseManager
{
public:
    SceneManager();
    SceneManager(const SceneManager&) = delete;
    SceneManager& operator=(const SceneManager&) = delete;
    ~SceneManager() = default;

    [[nodiscard]] std::shared_ptr<Scene> get_scene() const;
    [[nodiscard]] std::shared_ptr<Object> get_cam() const;

    void set_scene(std::shared_ptr<Scene> scene_);
    void set_cam(const std::string &cam_numb);

private:
    std::shared_ptr<Scene> _scene;
    std::shared_ptr<Object> current_cam;
};
