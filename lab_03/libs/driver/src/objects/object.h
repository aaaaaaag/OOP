#pragma once

#include <memory>


#include <objects/model/details/point/point.h>

#include <utility>
#include <vector>

class Object;
class ModelDetails;
using Iterator = std::vector<std::shared_ptr<Object>>::iterator;
class BaseVisitor;
class Object {
public:
    Object() = default;
    virtual ~Object() = default;

    virtual bool add(const std::shared_ptr<Object> &) { return false; };
    virtual bool remove(const Iterator &) { return false; };

    virtual Iterator begin() { return Iterator(); };
    virtual Iterator end() { return Iterator(); };

    virtual std::string getName() { return _name; };
    virtual void setName(std::string name) {_name = std::move(name);};

    virtual bool is_visible() { return false; }
    [[nodiscard]] virtual bool is_composite() const { return false; };
    virtual void accept(std::shared_ptr<BaseVisitor> visitor) = 0;
    virtual void reform(const Point &move, const Point &scale, const Point &turn) = 0;
    [[nodiscard]] virtual std::shared_ptr<ModelDetails> get_details() const = 0;
    virtual std::vector<std::shared_ptr<Object>> &get_objects() = 0;
    virtual Point get_pos() = 0;
protected:

    std::string _name;

};

class VisibleObject : public Object {
public:
    VisibleObject() = default;
    ~VisibleObject() override = default;

    bool is_visible() override { return true; }
};

class InvisibleObject : public Object {
public:
    InvisibleObject() = default;
    ~InvisibleObject() override = default;

    bool is_visible() override { return false; }
};