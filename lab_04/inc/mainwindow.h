#pragma once

#include <QMainWindow>
#include <lift.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow() override;

private slots:
    void onButtonCabinClicked(int num);
    void floorReached(int num);

private:
  Ui::MainWindow *ui;
  Lift lift;
};