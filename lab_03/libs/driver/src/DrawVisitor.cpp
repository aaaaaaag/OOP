//
// Created by denis on 25.06.2021.
//

#include "DrawVisitor.h"
#include "objects/model/model.h"
Point DrawVisitor::proect_point(const Point &_point) {
    Point new_point(_point);
    Point cam_pos(_cam->get_pos());
    new_point.set_x(new_point.get_x() + cam_pos.get_x());
    new_point.set_y(new_point.get_y() + cam_pos.get_y());

    return new_point;
}

void DrawVisitor::visit(const Model &model) {

    auto points = model.get_details()->get_points();

    auto center = model.get_details()->get_center();
    for (auto edge : model.get_details()->get_edges())
        _drawer->draw_line(
                proect_point(points.at(edge.get_fst()).relative_to(center)),
                proect_point(points.at(edge.get_snd())).relative_to(center));
}
