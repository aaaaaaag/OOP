#ifndef CAMERAROTATOR_H
#define CAMERAROTATOR_H

#include "../BaseManager.h"
#include "../objects/Camera.h"

namespace transformations {

using objects::Camera;

class CameraManager: public BaseManager {
public:
    static void yaw(const std::shared_ptr<Camera>& camera, double angle);// TODO go here
    static void roll(const std::shared_ptr<Camera>& camera, double angle);
    static void pitch(const std::shared_ptr<Camera>& camera, double angle);
};

} // namespace transformations

#endif // CAMERAROTATOR_H
