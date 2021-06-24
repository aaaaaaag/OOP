#include <objects/model/model.h>
#include "visitor.h"
#include <memory>

Model::Model(const Model &_model) {
    _details = _model.get_details();
}

void Model::reform(const Point &move_coeff, const Point &scale_coeff, const Point &turn_coeff) {
    _details->reform(move_coeff, scale_coeff, turn_coeff);
}

void Model::accept(std::shared_ptr<BaseVisitor> _visitor) {
    _visitor->visit(*this);
}

std::vector<std::shared_ptr<Object>> &Model::get_objects() {
    std::vector<std::shared_ptr<Object>> c;
    return c;
}

Point Model::get_pos() {
    return Point();
}
