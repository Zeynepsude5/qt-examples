#include "mainwindow.h"
#include "userinfo.h"
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QRadioButton>
#include <QCheckBox>
#include <QComboBox>
#include <QListWidget>
#include <QLineEdit>
#include <QLabel>
#include <QTreeWidget>
#include <QSlider>
#include <QProgressBar>
#include <QStatusBar>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Get User Info");

    UserInfo info;

    QLabel *nameLabel = new QLabel("Name:");
    QLineEdit *nameEdit = new QLineEdit;

    QLabel *ageLabel = new QLabel("choose your age:");
    QSlider *ageSlider = new QSlider(Qt::Horizontal);
    ageSlider->setRange(1, 100);
    QProgressBar *ageProgress = new QProgressBar;
    ageProgress->setRange(1, 100);
    ageProgress->setValue(18);

    QLabel *colorLabel = new QLabel("Favorite color:");
    QComboBox *colorCombo = new QComboBox;
    colorCombo->addItems({"Blue", "Green", "Red", "Black", "White"});

    QLabel *hobbyLabel = new QLabel("Choose your hobbies :");
    QListWidget *hobbyList = new QListWidget;
    hobbyList->addItems({"Sport", "Reading", "Music", "Writing", "Designing"});
    hobbyList->setSelectionMode(QAbstractItemView::MultiSelection);

    QCheckBox *confirmCheck = new QCheckBox("I confirm the information that I gave");

    QTreeWidget *summaryTree = new QTreeWidget;
    summaryTree->setHeaderLabel("Summary of your informations");

    // ---- Buton ----
    QPushButton *submitButton = new QPushButton("Save and Show");

    QStatusBar *status = new QStatusBar;

    QVBoxLayout *layout = new QVBoxLayout;

    layout->addWidget(nameLabel);
    layout->addWidget(nameEdit);

    layout->addWidget(ageLabel);
    layout->addWidget(ageSlider);
    layout->addWidget(ageProgress);

    layout->addWidget(colorLabel);
    layout->addWidget(colorCombo);

    layout->addWidget(hobbyLabel);
    layout->addWidget(hobbyList);

    layout->addWidget(confirmCheck);
    layout->addWidget(summaryTree);
    layout->addWidget(submitButton);
    layout->addWidget(status);

    window.setLayout(layout);


    QObject::connect(ageSlider, &QSlider::valueChanged, [&](int value){
        ageProgress->setValue(value);
        info.age = value;
    });


    QObject::connect(colorCombo, &QComboBox::currentTextChanged, [&](const QString &color){
        info.favoriteColor = color;
        status->showMessage("Renk seçildi: " + color);
    });


    QObject::connect(submitButton, &QPushButton::clicked, [&]() {
    if (!confirmCheck->isChecked()) {
    QMessageBox::warning(&window, "Warning", "Please confirm the informations that you gave.");
    return;
    }


    info.name = nameEdit->text();
    info.hobbies.clear();
    for (QListWidgetItem *item : hobbyList->selectedItems()) {
        info.hobbies.append(item->text());
    }


    summaryTree->clear();
    QTreeWidgetItem *root = new QTreeWidgetItem(summaryTree, {"User Informations"});
    new QTreeWidgetItem(root, {"Name: " + info.name});
    new QTreeWidgetItem(root, {"Age: " + QString::number(info.age)});
    new QTreeWidgetItem(root, {"Favorite color: " + info.favoriteColor});
    new QTreeWidgetItem(root, {"Hobbies: " + info.hobbies.join(", ")});


    QMessageBox::information(&window, "Summary", "Information got succesfully.");
    });


    window.show();
    return app.exec();
}
