#include "MainWindow.h"
#include "ui_widget.h"

#include <QMessageBox>

Widget::Widget(QWidget *parent):
        QWidget(parent),
        ui(new Ui::Widget),
        m_pFacade(new ViewerFacade),
        m_elementsCount(0) {
    ui->setupUi(this);
    m_pDrawLabel = new DrawLabel(m_pixmap);
    m_pDrawLabel->resize(this->width() - ui->frame->width(), height());
    this->layout()->addWidget(m_pDrawLabel);
    m_pixmap = QPixmap(m_pDrawLabel->width(), m_pDrawLabel->height());
    m_pixmap.fill();
}

Widget::~Widget() {
    delete m_pDrawLabel;
    delete ui;
}

void Widget::moveObject() {
    if (ui->comboBox->count() == 0)
        return;

    std::string obj_name = ui->comboBox->currentText().toStdString();
    int x = ui->spinBox->value();
    int y = ui->spinBox_2->value();
    int z = ui->spinBox_3->value();

    Point moving(x, y, z);
    if (obj_name[0] == 'm') {
        Point rotating(0, 0, 0);
        Point scale(1, 1, 1);
        commands::TransformModelCommand command(obj_name, moving, scale, rotating);
        m_pFacade->execCommand(&command);
    } else {
        commands::MoveCameraCommand command(obj_name, moving);
        m_pFacade->execCommand(&command);
    }

    this->render();
}

void Widget::scaleObject() {
    if (ui->comboBox->count() == 0)
        return;

    std::string objectName = ui->comboBox->currentText().toStdString();
    if (objectName[0] == 'c') {
        QMessageBox::critical(nullptr, "Error", "Couldn't scale camera");
        return;
    }

    double x = ui->doubleSpinBox_7->value(); // TODO check spinBoxes
    double y = ui->doubleSpinBox_6->value();
    double z = ui->doubleSpinBox_5->value();

    Point moving(0, 0, 0);
    Point rotating(0, 0, 0);
    Point scale(x, y, z);
    commands::TransformModelCommand command(objectName, moving, scale, rotating);
    m_pFacade->execCommand(&command);

    this->render();
}

void Widget::rotateObjectX() {
    if (ui->comboBox->count() == 0)
        return;

    std::string objectName = ui->comboBox->currentText().toStdString();
    double angle = ui->doubleSpinBox_4->value();

    if (objectName[0] == 'c') {
        commands::RollCameraCommand command(objectName, angle);
        m_pFacade->execCommand(&command);
    }
    else {
        Point moving(0, 0, 0);
        Point rotating(angle, 0, 0);
        Point scale(1, 1, 1);
        commands::TransformModelCommand command(objectName, moving, scale, rotating);
        m_pFacade->execCommand(&command);
    }

    this->render();
}

void Widget::rotateObjectY() {
    if (ui->comboBox->count() == 0)
        return;

    std::string objectName = ui->comboBox->currentText().toStdString();
    double angle = ui->doubleSpinBox_4->value();
    if (objectName[0] == 'c') {
        commands::PitchCameraCommand command(objectName, angle);
        m_pFacade->execCommand(&command);
    }
    else {
        Point moving(0, 0, 0);
        Point rotating(0, angle, 0);
        Point scale(1, 1, 1);
        commands::TransformModelCommand command(objectName, moving, scale, rotating);
        m_pFacade->execCommand(&command);
    }

    this->render();
}

void Widget::rotateObjectZ() {
    if (ui->comboBox->count() == 0)
        return;

    std::string obj_name = ui->comboBox->currentText().toStdString();
    double angle = ui->doubleSpinBox_4->value();
    if (obj_name[0] == 'c') {
        commands::YawCameraCommand command(obj_name, angle);
        m_pFacade->execCommand(&command);
    }
    else {
        Point moving(0, 0, 0);
        Point rotating(0, 0, angle);
        Point scale(1, 1, 1);
        commands::TransformModelCommand command(obj_name, moving, scale, rotating);
        m_pFacade->execCommand(&command);
    }

    this->render();
}

void Widget::addModel() {
    QString file = QFileDialog::getOpenFileName(this,
                                                QString::fromUtf8("Открыть файл"),
                                                QDir::currentPath(),
                                                "text files (*.txt)");
    if (file.isEmpty())
        return;

    std::string modelName = std::string("model_") + std::to_string(++m_elementsCount);
    std::string fileName = file.toLocal8Bit().constData();
    commands::AddModelCommand command(fileName, modelName);
    try {
        m_pFacade->execCommand(&command);
        this->render();
        ui->comboBox->addItem(modelName.c_str());
    }
    catch(exceptions::FileOpenException& e) {
        QMessageBox::critical(nullptr, "Error", "Couldn't open file");
    }
    catch(std::exception& e) {
        QMessageBox::critical(nullptr, "Error", "Some problems with reading file");
    }
}

void Widget::addCamera() {
    std::string cameraName = std::string("camera_") + std::to_string(++m_elementsCount);
    commands::AddCameraCommand command(cameraName);
    m_pFacade->execCommand(&command);

    ui->comboBox->addItem(cameraName.c_str());
}

void Widget::removeObject() {
    if (ui->comboBox->count() == 0) {
        return;
    }
    std::string objectName = ui->comboBox->currentText().toStdString();
    if (objectName[0] == 'm') {
        commands::RemoveModelCommand command(objectName);
        m_pFacade->execCommand(&command);
    } else {
        commands::RemoveCameraCommand command(objectName);
        m_pFacade->execCommand(&command);
    }

    this->render();
}

void Widget::setCamera() {
    std::string cameraName = ui->comboBox->currentText().toStdString();
    if (cameraName[0] == 'c') {
        commands::SetCameraCommand command(cameraName);
        m_pFacade->execCommand(&command);

        this->render();
    }
    else
        QMessageBox::critical(nullptr, "Error", "You should choose camera");
}

void Widget::render() {
    QPainter painter(&m_pixmap);
    m_pixmap.fill();
    auto drawer = std::make_shared<render::QtDrawer>(&painter);
    auto command = new commands::RenderCommand(drawer);
    try {
        m_pFacade->execCommand(command);
        m_pDrawLabel->update();
    }
    catch(exceptions::CameraLackException& e)
    {
        QMessageBox::critical(nullptr, "Error", "Choose camera to render smth");
    }
    delete command;
}
