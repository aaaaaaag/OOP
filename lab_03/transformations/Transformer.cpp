#include "Transformer.h"
#include "cmath"
namespace transformations {

void Transformer::rotateObjectX(const std::shared_ptr<Object>& obj, double angle) {
    angle = degreesToRadians(angle);
    std::shared_ptr<Matrix> transform_matrix(new RotateOxMatrix(angle));
    obj->transform(transform_matrix);
}

void Transformer::rotateObjectY(const std::shared_ptr<Object>& obj, double angle) {
    angle = degreesToRadians(angle);
    std::shared_ptr<Matrix> transform_matrix(new RotateOyMatrix(angle));
    obj->transform(transform_matrix);
}

void Transformer::rotateObjectZ(const std::shared_ptr<Object>& obj, double angle) {
    angle = degreesToRadians(angle);
    std::shared_ptr<Matrix> transform_matrix(new RotateOzMatrix(angle));
    obj->transform(transform_matrix);
}

void Transformer::moveObject(const std::shared_ptr<Object>& obj, int x, int y, int z) {
    std::shared_ptr<Matrix> transform_matrix(new MoveMatrix(x, y, z));
    obj->transform(transform_matrix);
}

void Transformer::scaleObject(const std::shared_ptr<Object>& obj, double x, double y, double z) {
    std::shared_ptr<Matrix> transform_matrix(new ScaleMatrix(x, y, z));
    obj->transform(transform_matrix);
}

double Transformer::degreesToRadians(double angle) {
    return angle / 180. * M_PI;
}

} // namespace transformations
