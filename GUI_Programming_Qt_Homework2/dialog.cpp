#include "dialog.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    QGridLayout* editLayout = new QGridLayout;
    QHBoxLayout* buttonLayout = new QHBoxLayout;
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    QLabel* decLabel = new QLabel("Decimal");
    QLabel* hexLabel = new QLabel("Hex");
    QLabel* binLabel = new QLabel("Binary");

    decEdit = new QLineEdit;
    hexEdit = new QLineEdit;
    binEdit = new QLineEdit;

    editLayout->addWidget(decLabel, 0, 0);
    editLayout->addWidget(decEdit,  0, 1);
    editLayout->addWidget(hexLabel, 1, 0);
    editLayout->addWidget(hexEdit,  1, 1);
    editLayout->addWidget(binLabel, 2, 0);
    editLayout->addWidget(binEdit,  2, 1);

    QPushButton* exitButton = new QPushButton("Exit");
    buttonLayout->addStretch();
    buttonLayout->addWidget(exitButton);

    mainLayout->addLayout(editLayout);
    // ====== 加上這一行：插入垂直彈簧 ======
    mainLayout->addStretch();
    // ===================================
    mainLayout->addLayout(buttonLayout);



    connect(exitButton, SIGNAL(clicked()), this, SLOT(accept()));

    connect(decEdit, SIGNAL(textChanged(const QString&)), this, SLOT(decChanged(const QString&)));
    connect(hexEdit, SIGNAL(textChanged(const QString&)), this, SLOT(hexChanged(const QString&)));
    connect(binEdit, SIGNAL(textChanged(const QString&)), this, SLOT(binChanged(const QString&)));
}

Dialog::~Dialog()
{
}

void Dialog::decChanged(const QString& newValue)
{
    bool ok;
    int num = newValue.toInt(&ok);
    if (ok) {
        hexEdit->blockSignals(true);
        binEdit->blockSignals(true);

        hexEdit->setText(QString::number(num, 16).toUpper());
        binEdit->setText(QString::number(num, 2));

        hexEdit->blockSignals(false);
        binEdit->blockSignals(false);
    } else {
        hexEdit->clear();
        binEdit->clear();
    }
}

void Dialog::hexChanged(const QString& newValue)
{
    bool ok;
    int num = newValue.toInt(&ok, 16);
    if (ok) {
        decEdit->blockSignals(true);
        binEdit->blockSignals(true);

        decEdit->setText(QString::number(num, 10));
        binEdit->setText(QString::number(num, 2));

        decEdit->blockSignals(false);
        binEdit->blockSignals(false);
    } else {
        decEdit->clear();
        binEdit->clear();
    }
}

void Dialog::binChanged(const QString& newValue)
{
    bool ok;
    int num = newValue.toInt(&ok, 2);
    if (ok) {
        decEdit->blockSignals(true);
        hexEdit->blockSignals(true);

        decEdit->setText(QString::number(num, 10));
        hexEdit->setText(QString::number(num, 16).toUpper());

        decEdit->blockSignals(false);
        hexEdit->blockSignals(false);
    } else {
        decEdit->clear();
        hexEdit->clear();
    }
}
