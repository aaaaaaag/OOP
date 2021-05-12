#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileDialog>
#include <memory>
#include "DrawLabel.h"
#include "math/Point.h"
#include "commands/AddModelCommand.h"
#include "commands/RenderCommand.h"
#include "commands/SetCamera.h"
#include "commands/AddCameraCommand.h"
#include "commands/TransformModelCommand.h"
#include "commands/YawCameraCommand.h"
#include "commands/RollCameraCommand.h"
#include "commands/PitchCameraCommand.h"
#include "commands/TransformModelCommand.h"
#include "commands/MoveCameraCommand.h"
#include "commands/RemoveModelCommand.h"
#include "commands/RemoveCameraCommand.h"
#include "exceptions/FileOpenException.h"
#include "exceptions/CameraLackException.h"
#include "facade/ViewerFacade.h"
#include "render/QtDrawer.h"

namespace Ui {
class Widget;
}

using facade::ViewerFacade;
using math::Point;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget() override;

public slots:
    void moveObject();
    void scaleObject();
    void rotateObjectX();
    void rotateObjectY();
    void rotateObjectZ();

    void addModel();
    void addCamera();
    void removeObject();
    void setCamera();

private:
    void render();

    Ui::Widget *ui;
    DrawLabel *m_pDrawLabel;
    QPixmap m_pixmap;
    std::unique_ptr<ViewerFacade> m_pFacade;
    size_t m_elementsCount;
};

#endif // WIDGET_H
