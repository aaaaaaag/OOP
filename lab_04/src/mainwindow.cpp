#include <QDebug>
#include <mainwindow.h>
#include <design.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  qDebug() << "Lift is staying at 1st floor, doors are closed.\n"
              "Waiting command";

  for (int i = 0; i < ui->cabin_buttons.size(); ++i) {
    connect(ui->cabin_buttons[i], &QPushButton::pressed, this,
            [=, this]() { onButtonCabinClicked(i + 1); });
  }

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onButtonCabinClicked(int num) {
  qDebug() << "In cabin pressed button " << num;
  lift.floor_but_clicked(num);
}

