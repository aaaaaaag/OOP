#ifndef LAB4_TRANSFORMER_H
#define LAB4_TRANSFORMER_H

#include <memory>
#include <cmath>
#include "../math/Point.h"
#include "../math/TransformMatrix.h"
#include "../objects/Model.h"
#include "../objects/Camera.h"

namespace transformations {

using namespace math;
using objects::Object;
using objects::Model;
using std::shared_ptr;

class Transformer {
public:

    static void rotateObjectX(const std::shared_ptr<Object>& obj, double angle);
    static void rotateObjectY(const std::shared_ptr<Object>& obj, double angle);
    static void rotateObjectZ(const std::shared_ptr<Object>& obj, double angle);
    static void moveObject(const std::shared_ptr<Object>& obj, int x, int y, int z);
    static void scaleObject(const std::shared_ptr<Object>& obj, double x, double y, double z);

private:

    static double degreesToRadians(double angle);

};

} // namespace transformations

#endif //LAB4_TRANSFORMER_H
