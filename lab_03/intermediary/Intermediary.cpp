#include "Intermediary.h"

#include <utility>

namespace intermediary {

Intermediary::Intermediary():
        m_pRenderer(new render::Renderer),
        m_loader(new uploading::FileLoader) {}

void Intermediary::addModel(std::string fileName, std::string modelName)
{
    std::shared_ptr<Model> model = m_loader.loadModel(std::move(fileName), std::move(modelName));
    m_sceneManager.getScene()->addModel(std::shared_ptr<objects::Model>(model));
}

void Intermediary::addCamera(std::string cameraName)
{
    auto camera = new objects::Camera(std::move(cameraName));
    m_sceneManager.getScene()->addCamera(std::shared_ptr<objects::Camera>(camera));
}

void Intermediary::setCamera(std::string cameraName)
{
    m_sceneManager.setCurrentCamera(std::move(cameraName));
}

void Intermediary::removeCamera(const std::string& cameraName)
{
    m_sceneManager.getScene()->removeCamera(cameraName);
}

void Intermediary::removeModel(const std::string& modelName)
{
    auto scene = m_sceneManager.getScene();
    scene->removeModel(scene->getObject(modelName));
}

void Intermediary::transformCamera(const std::string& cameraName, math::Point &move, math::Point &rotate)
{
    auto camera = m_sceneManager.getScene()->getCamera(cameraName);
    m_transformer.moveObject(camera, move.x(), move.y(), move.z());
    m_cameraManager.roll(camera, rotate.x());
    m_cameraManager.pitch(camera, rotate.y());
    m_cameraManager.yaw(camera, rotate.z());
}

void Intermediary::transformModel(const std::string& modelName, math::Point &move, math::Point &scale, math::Point &rotate)
{
    auto obj = m_sceneManager.getScene()->getObject(modelName);
    m_transformer.moveObject(obj, move.x(), move.y(), move.z());
    m_transformer.scaleObject(obj, scale.x(), scale.y(), scale.z());
    m_transformer.rotateObjectX(obj, rotate.x());
    m_transformer.rotateObjectY(obj, rotate.y());
    m_transformer.rotateObjectZ(obj, rotate.z());
}

void Intermediary::draw(std::shared_ptr<BaseDrawer> drawer)
{
    m_pRenderer->setDrawer(std::move(drawer));
    m_pRenderer->setCamera(m_sceneManager.getCurrentCamera());
    m_sceneManager.getScene()->getModelsComposite()->accept(m_pRenderer);
}

} // namespace intermediary
