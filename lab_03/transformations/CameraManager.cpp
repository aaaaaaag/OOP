#include "CameraManager.h"
#include "cmath"
namespace transformations {

void CameraManager::yaw(const std::shared_ptr<Camera>& camera, double angle) {
    double cur_angle = camera->getZAngle();
    camera->setZAngle(angle / 180. * M_PI + cur_angle);
}

void CameraManager::roll(const std::shared_ptr<objects::Camera>& camera, double angle) {
    double cur_angle = camera->getXAngle();
    camera->setXAngle(angle / 180. * M_PI + cur_angle);
}

void CameraManager::pitch(const std::shared_ptr<objects::Camera>& camera, double angle) {
    double cur_angle = camera->getYAngle();
    camera->setYAngle(angle / 180. * M_PI + cur_angle);
}

} // namespace transformations
