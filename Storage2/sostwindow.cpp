#include "sostwindow.h"
#include "ui_sostwindow.h"
#include <QMessageBox>

SostWindow::SostWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SostWindow)
{
    ui->setupUi(this);
    double wooddif = ui->woodtek->value() / ui->woodmax->value() * 100;
    double irondif = ui->irontek->value() / ui->ironmax->value() * 100;
    double alumdif = ui->alumtek->value() / ui->alummax->value() * 100;
    double golddif = ui->goldtek->value() / ui->goldmax->value() * 100;
    double plumdif = ui->plumtek->value() / ui->plummax->value() * 100;
    double rezdif = ui->reztek->value() / ui->rezmax->value() * 100;
    ui->woodbar->setValue(wooddif);
    ui->ironbar->setValue(irondif);
    ui->alumbar->setValue(alumdif);
    ui->goldbar->setValue(golddif);
    ui->plumbar->setValue(plumdif);
    ui->rezbar->setValue(rezdif);
}

SostWindow::~SostWindow()
{
    delete ui;
}

void SostWindow::on_menuButtonSost_clicked()
{
    this->hide();
    emit showMenu();
}

void SostWindow::updateMaterialsDost(int wood,int iron,int alum,int gold,int plum,int rez)
{
    int woodnew = ui->woodtek->value() - wood;
    int ironnew = ui->irontek->value() - iron;
    int alumnew = ui->alumtek->value() - alum;
    int goldnew = ui->goldtek->value() - gold;
    int plumnew = ui->plumtek->value() - plum;
    int reznew = ui->reztek->value() - rez;

    if (woodnew < 0 || ironnew < 0 || alumnew < 0 || goldnew < 0 || plumnew < 0 || reznew < 0) {
        QMessageBox::critical(this, "Ошибка", "Не хватает материалов для доставки!");
    }
    else
    {
        ui->irontek->display(ironnew);
        ui->alumtek->display(alumnew);
        ui->goldtek->display(goldnew);
        ui->plumtek->display(plumnew);
        ui->reztek->display(reznew);
        ui->woodtek->display(woodnew);
        double wooddif = ui->woodtek->value() / ui->woodmax->value() * 100;
        double irondif = ui->irontek->value() / ui->ironmax->value() * 100;
        double alumdif = ui->alumtek->value() / ui->alummax->value() * 100;
        double golddif = ui->goldtek->value() / ui->goldmax->value() * 100;
        double plumdif = ui->plumtek->value() / ui->plummax->value() * 100;
        double rezdif = ui->reztek->value() / ui->rezmax->value() * 100;
        ui->woodbar->setValue(wooddif);
        ui->ironbar->setValue(irondif);
        ui->alumbar->setValue(alumdif);
        ui->goldbar->setValue(golddif);
        ui->plumbar->setValue(plumdif);
        ui->rezbar->setValue(rezdif);
        QMessageBox::information(this, "Доставлено", "Материалы успешно доставлены!");
    }
}

void SostWindow::updateMaterialsZak(int woodzak,int ironzak,int alumzak,int goldzak,int plumzak,int rezzak) {
    int woodnew = ui->woodtek->value() + woodzak;
    int ironnew = ui->irontek->value() + ironzak;
    int alumnew = ui->alumtek->value() + alumzak;
    int goldnew = ui->goldtek->value() + goldzak;
    int plumnew = ui->plumtek->value() + plumzak;
    int reznew = ui->reztek->value() + rezzak;

    if (woodnew > ui->woodmax->value() || ironnew > ui->ironmax->value() || goldnew > ui->goldmax->value() || alumnew > ui->alummax->value() || plumnew > ui->plummax->value() || reznew > ui->rezmax->value()) {
        QMessageBox::warning(this, "Переполнение склада", "Случилось переполнение склада! Лишние материалы, которые не поместились на склад, возвращены обратно отправителю!");
        if (woodnew > ui->woodmax->value()) {
            ui->woodtek->display(ui->woodmax->value());
        }
        else {
            ui->woodtek->display(woodnew);
        }
        if (ironnew > ui->ironmax->value()) {
            ui->irontek->display(ui->ironmax->value());
        }
        else {
            ui->irontek->display(ironnew);
        }
        if (alumnew > ui->alummax->value()) {
            ui->alumtek->display(ui->alummax->value());
        }
        else {
            ui->alumtek->display(alumnew);
        }
        if (goldnew > ui->goldmax->value()) {
            ui->goldtek->display(ui->goldmax->value());
        }
        else {
            ui->goldtek->display(goldnew);
        }
        if (plumnew > ui->plummax->value()) {
            ui->plumtek->display(ui->plummax->value());
        }
        else {
            ui->plumtek->display(plumnew);
        }
        if (reznew > ui->rezmax->value()) {
            ui->reztek->display(ui->rezmax->value());
        }
        else {
            ui->reztek->display(reznew);
        }
    }
    else {
        ui->irontek->display(ironnew);
        ui->alumtek->display(alumnew);
        ui->goldtek->display(goldnew);
        ui->plumtek->display(plumnew);
        ui->reztek->display(reznew);
        ui->woodtek->display(woodnew);

        QMessageBox::information(this, "Успешный заказ", "Материалы успешно доставлены на склад!");
    }
    double wooddif = ui->woodtek->value() / ui->woodmax->value() * 100;
    double irondif = ui->irontek->value() / ui->ironmax->value() * 100;
    double alumdif = ui->alumtek->value() / ui->alummax->value() * 100;
    double golddif = ui->goldtek->value() / ui->goldmax->value() * 100;
    double plumdif = ui->plumtek->value() / ui->plummax->value() * 100;
    double rezdif = ui->reztek->value() / ui->rezmax->value() * 100;
    ui->woodbar->setValue(wooddif);
    ui->ironbar->setValue(irondif);
    ui->alumbar->setValue(alumdif);
    ui->goldbar->setValue(golddif);
    ui->plumbar->setValue(plumdif);
    ui->rezbar->setValue(rezdif);
}
