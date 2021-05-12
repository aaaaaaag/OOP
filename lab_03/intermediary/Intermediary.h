#ifndef INTERMEDIARY_H
#define INTERMEDIARY_H

#include <memory>
#include "../exceptions/ObjectTypeException.h"
#include "../math/Point.h"
#include "../render/Renderer.h"
#include "../transformations/Transformer.h"
#include "../transformations/CameraManager.h"
#include "../uploading/FileLoader.h"
#include "../uploading/ModelLoader.h"
#include "../scene/SceneManager.h"
#include "../objects/Model.h"

namespace intermediary {

using objects::Object;
using objects::Model;
using objects::Camera;
using render::BaseDrawer;
using math::Point;

class Intermediary {
public:
    Intermediary();

    void addModel(std::string fileName, std::string modelName);
    void addCamera(std::string cameraName);
    void setCamera(std::string cameraName);
    void removeCamera(const std::string& cameraName);
    void removeModel(const std::string& modelName);

    void transformCamera(const std::string& cameraName, Point &move, Point &rotate);
    void transformModel(const std::string& modelName, Point &move, Point &scale, Point &rotate);

    void draw(std::shared_ptr<BaseDrawer> drawer);
private:
    std::shared_ptr<render::Renderer> m_pRenderer;
    uploading::ModelLoader m_loader;
    transformations::Transformer m_transformer;
    transformations::CameraManager m_cameraManager;
    scene::SceneManager m_sceneManager;
};

}

#endif // INTERMEDIARY_H
