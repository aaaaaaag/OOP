#include <commands/model_command.h>

#include <load_controller/model/model_load_controller_creator.h>
#include <managers/load/load_manager_creator.h>
#include <managers/reform/reform_manager_creator.h>
#include <managers/scene/scene_manager_creator.h>
#include <utility>

#define cd const double

MoveModel::MoveModel(cd &dx, cd &dy, cd &dz, std::string mnumb) : dx(dx), dy(dy), dz(dz), model_numb(std::move(mnumb)) {}

void MoveModel::execute() {
    Point move(dx, dy, dz);
    Point scale(1, 1, 1);
    Point turn(0, 0, 0);

    std::shared_ptr<Object> model = SceneManagerCreator().create_manager()->get_scene()->getObject(model_numb);
    ReformManagerCreator().create_manager()->reform_object(model, move, scale, turn);
}

ScaleModel::ScaleModel(cd &kx, cd &ky, cd &kz, std::string mnumb) : kx(kx), ky(ky), kz(kz), model_numb(std::move(mnumb)) {}

void ScaleModel::execute() {
    Point move(0, 0, 0);
    Point scale(kx, ky, kz);
    Point turn(0, 0, 0);

    std::shared_ptr<Object> model = SceneManagerCreator().create_manager()->get_scene()->getObject(model_numb);
    ReformManagerCreator().create_manager()->reform_object(model, move, scale, turn);
}

RotateModel::RotateModel(cd &ox, cd &oy, cd &oz, std::string mnumb) : ox(ox), oy(oy), oz(oz), model_numb(std::move(mnumb)) {}

void RotateModel::execute() {
    Point move(0, 0, 0);
    Point scale(1, 1, 1);
    Point turn(ox, oy, oz);

    std::shared_ptr<Object> model = SceneManagerCreator().create_manager()->get_scene()->getObject(model_numb);
    ReformManagerCreator().create_manager()->reform_object(model, move, scale, turn);
}

ReformModel::ReformModel(std::string numb, Point move, Point scale, Point turn) : model_numb(std::move(numb)), move(std::move(move)), scale(std::move(scale)), turn(std::move(turn)) {}

void ReformModel::execute() {
    std::shared_ptr<Object> model = SceneManagerCreator().create_manager()->get_scene()->getObject(model_numb);
    ReformManagerCreator().create_manager()->reform_object(model, move, scale, turn);
}

LoadModel::LoadModel(std::string fname, std::string modelName) : fname(std::move(fname)), _modelName(std::move(modelName)) {}

void LoadModel::execute() {
    auto controller = Load::ModelLoadControllerCreator().create_controller();
    auto manager = Load::LoadManagerCreator().create_manager(controller);

    auto model = manager->load(fname);
    model->setName(_modelName);
    SceneManagerCreator().create_manager()->get_scene()->addObject(model);
}

ExportModel::ExportModel(std::string fname) {
}

void ExportModel::execute() {
}

AddModel::AddModel(std::shared_ptr<Object> model) : model(std::move(model)) {}

void AddModel::execute() {
    SceneManagerCreator().create_manager()->get_scene()->addObject(model);
}

RemoveModel::RemoveModel(std::string model_numb) : model_numb(std::move(model_numb)) {}

void RemoveModel::execute() {
    SceneManagerCreator().create_manager()->get_scene()->removeObject(model_numb);
}

ModelCount::ModelCount(std::shared_ptr<size_t> &count) : _count(count) {}

void ModelCount::execute() {
    (*_count) = SceneManagerCreator().create_manager()->get_scene()->get_composite()->get_objects().size();
}
