#include "dostwindow.h"
#include "ui_dostwindow.h"
#include <QMessageBox>

DostWindow::DostWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DostWindow)
{
    ui->setupUi(this);
}

DostWindow::~DostWindow()
{
    delete ui;
}

void DostWindow::on_menuButtonDost_clicked()
{
    this->hide();
    emit showMenu();
}


void DostWindow::on_dostavit_clicked()
{
    int wood = ui->wooddost->value();
    int iron = ui->irondost->value();
    int alum = ui->alumdost->value();
    int gold = ui->golddost->value();
    int plum = ui->plumdost->value();
    int rez = ui->rezdost->value();
    emit dostMaterials(wood,iron,alum,gold,plum,rez);
}

