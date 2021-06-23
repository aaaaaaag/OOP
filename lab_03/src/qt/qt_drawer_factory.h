#pragma once

#include <memory>


#include <drawer/abstract_drawer_factory.h>
#include <qt/drawer/qt_drawer.h>


class QtDrawerFactory : public AbstractDrawerFactory {
public:
    explicit QtDrawerFactory(QGraphicsScene *scene);

    std::unique_ptr<AbstractDrawer> create_graphics() override {
        return std::unique_ptr<AbstractDrawer>(new QtDrawer(_scene));
    }

private:
    QGraphicsScene *_scene;
};
