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
    ui->cabin_buttons[i]->setStyleSheet("background-color: red");
    ui->cabin_buttons[i]->setStyleSheet("background-color: white");
  }
  QObject::connect(&lift, SIGNAL(liftReachedFloor(int)), this,
                      SLOT(floorReached(int)));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onButtonCabinClicked(int num) {
  qDebug() << "In cabin pressed button " << num;
  ui->cabin_buttons[num - 1]->setStyleSheet("background-color: red");
  lift.click(num);
}

void MainWindow::floorReached(int num) {
    ui->cabin_buttons[num - 1]->setStyleSheet("background-color: white");
}

