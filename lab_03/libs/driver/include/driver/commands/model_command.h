#pragma once

#include <cstddef>
#include <memory>

#include <commands/base_command.h>
#include <objects/object.h>


class ModelBaseCommand : public BaseCommand {};

class MoveModel : public ModelBaseCommand {
public:
    MoveModel() = delete;
    MoveModel(const double &dx, const double &dy, const double &dz, std::string mnumb);
    ~MoveModel() override = default;

    void execute() override;

private:
    std::string model_numb;

    double dx, dy, dz;
};

class ScaleModel : public ModelBaseCommand {
public:
    ScaleModel() = delete;
    ScaleModel(const double &kx, const double &ky, const double &kz, std::string mnumb);
    ~ScaleModel() override = default;

    void execute() override;

private:
    std::string model_numb;

    double kx, ky, kz;
};

class RotateModel : public ModelBaseCommand {
public:
    RotateModel() = delete;
    RotateModel(const double &ox, const double &oy, const double &oz, std::string mnumb);
    ~RotateModel() override = default;

    void execute() override;

private:
    std::string model_numb;

    double ox, oy, oz;
};

class ReformModel : public ModelBaseCommand {
public:
    ReformModel() = delete;
    ReformModel(std::string numb, Point move, Point scale, Point turn);
    ~ReformModel() override = default;

    void execute() override;

private:
    std::string model_numb;

    Point move, scale, turn;
};

class LoadModel : public ModelBaseCommand {
public:
    LoadModel() = delete;
    explicit LoadModel(std::string fname, std::string modelName);
    ~LoadModel() override = default;

    void execute() override;

private:
    std::string _modelName;
    std::string fname;
};

class ExportModel : public ModelBaseCommand {
public:
    ExportModel() = delete;
    explicit ExportModel(std::string fname);
    ~ExportModel() override = default;

    void execute() override;

private:
    std::string fname;
};

class AddModel : public ModelBaseCommand {
public:
    AddModel() = delete;
    explicit AddModel(std::shared_ptr<Object> model);
    ~AddModel() override = default;

    void execute() override;

private:
    std::shared_ptr<Object> model;
};

class RemoveModel : public ModelBaseCommand {
public:
    RemoveModel() = delete;
    explicit RemoveModel(std::string model_numb);
    ~RemoveModel() override = default;

    void execute() override;

private:
    std::string model_numb;
};

class ModelCount : public ModelBaseCommand {
public:
    ModelCount() = delete;
    explicit ModelCount(std::shared_ptr<size_t> &count);
    ~ModelCount() override = default;

    void execute() override;

private:
    std::shared_ptr<size_t> &_count;
};
