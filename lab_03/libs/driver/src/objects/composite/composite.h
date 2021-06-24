#pragma once

#include <objects/object.h>

class Composite : public Object {
public:
    Composite() = default;
    explicit Composite(std::shared_ptr<Object> &component);
    explicit Composite(const std::vector<std::shared_ptr<Object>> &vector);

    [[nodiscard]] std::size_t size() const;

    bool add(const std::shared_ptr<Object> &component) override;
    bool remove(const Iterator &iterator) override;

    Iterator begin() override;
    Iterator end() override;

    [[nodiscard]] std::shared_ptr<ModelDetails> get_details() const override;

    Point get_pos() override;

    bool is_visible() override;
    [[nodiscard]] bool is_composite() const override;
    void reform(const Point &move, const Point &scale, const Point &turn) override;
    void accept(std::shared_ptr<BaseVisitor> visitor) override;

    std::vector<std::shared_ptr<Object>> &get_objects() override;

private:
    std::vector<std::shared_ptr<Object>> objects;
};