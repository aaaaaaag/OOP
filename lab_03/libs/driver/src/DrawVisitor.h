//
// Created by denis on 25.06.2021.
//

#ifndef LAB_03_DRAWVISITOR_H
#define LAB_03_DRAWVISITOR_H
#include <utility>

#include "visitor.h"
#include "drawer/abstract_drawer.h"
#include "objects/object.h"
class DrawVisitor: public BaseVisitor{

public:

    DrawVisitor(std::shared_ptr<AbstractDrawer> inDraw, std::shared_ptr<Object> cam):
            _cam(std::move(cam)),
            _drawer(std::move(inDraw)){};

    void visit(const Camera &cam) override {

    }

    void visit(const Model& model) override ;

    void visit(const Composite &composite) override {

    }

private:
    Point proect_point(const Point &point);
    std::shared_ptr<AbstractDrawer> _drawer;
    std::shared_ptr<Object> _cam;

};


#endif //LAB_03_DRAWVISITOR_H
