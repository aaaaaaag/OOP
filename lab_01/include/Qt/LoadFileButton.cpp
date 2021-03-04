//
// Created by denis on 02.03.2021.
//

#include <QtWidgets/QFileDialog>
#include "LoadFileButton.h"
#include "DotFileIO.h"


LoadFileButton::LoadFileButton(QWidget *paintWidget, allDots& getDots) {
    setText("Load file");
    m_pDots = &getDots;
    m_pPaintWidget = paintWidget;
    connect(this, &QPushButton::clicked, this, &LoadFileButton::Load);
}

void LoadFileButton::Load() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "/home",
                                                    tr("Images (*.png *.txt *.jpg)"));

    int err;
    *m_pDots = GetDotsFromFile(fileName.toStdString(), err);
    
}
