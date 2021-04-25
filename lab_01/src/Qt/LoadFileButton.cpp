//
// Created by denis on 02.03.2021.
//

#include <QtWidgets/QFileDialog>
#include <utility>
#include "Qt/LoadFileButton.h"


LoadFileButton::LoadFileButton(std::shared_ptr<ActionSlots> actionsDot) {
    setText("Load file");
    m_pActionsDot = std::move(actionsDot);
    connect(this, &QPushButton::clicked, this, &LoadFileButton::Load);
}

void LoadFileButton::Load() {
    QString fileName = QFileDialog::getOpenFileName(nullptr, tr("Open File"),
                                                    "/home/denis/OOP/lab_01/test",
                                                    tr("*.txt"));
    auto a = fileName.toStdString();
    auto b = a.data();
    m_pActionsDot->m_data->fileData.filename = b;
    m_pActionsDot->Load();
}
