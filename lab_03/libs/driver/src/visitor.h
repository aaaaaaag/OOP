#include <utility>

#pragma once
class Camera;
class Composite;
class Model;

class BaseVisitor
{
public:
    BaseVisitor() = default;
    ~BaseVisitor() = default;

    virtual void visit(const Camera &cam) = 0;
    virtual void visit(const Model &model) = 0;
    virtual void visit(const Composite &composite) = 0;
};
