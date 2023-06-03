#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sostwindow = new SostWindow();
    connect(sostwindow, &SostWindow::showMenu, this, &MainWindow::show);
    dostwindow = new DostWindow();
    connect(dostwindow, &DostWindow::showMenu, this, &MainWindow::show);
    connect(dostwindow, SIGNAL(dostMaterials(int,int,int,int,int,int)), sostwindow, SLOT(updateMaterialsDost(int,int,int,int,int,int)));
    zakwindow = new ZakazWindow();
    connect(zakwindow, &ZakazWindow::showMenu, this, &MainWindow::show);
    connect(zakwindow, SIGNAL(zakMaterials(int,int,int,int,int,int)), sostwindow, SLOT(updateMaterialsZak(int,int,int,int,int,int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_dostavka_clicked()
{
    this->hide();
    dostwindow->show();
}


void MainWindow::on_sostoyanie_clicked()
{
    this->hide();
    sostwindow->show();
}


void MainWindow::on_zakaz_clicked()
{
    this->hide();
    zakwindow->show();
}

