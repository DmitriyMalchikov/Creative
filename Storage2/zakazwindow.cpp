#include "zakazwindow.h"
#include "ui_zakazwindow.h"

ZakazWindow::ZakazWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ZakazWindow)
{
    ui->setupUi(this);
}

ZakazWindow::~ZakazWindow()
{
    delete ui;
}

void ZakazWindow::on_menuButtonZakaz_clicked()
{
    this->hide();
    emit showMenu();
}


void ZakazWindow::on_zakazat_clicked()
{
    int woodzak = ui->woodzakaz->value();
    int ironzak = ui->ironzakaz->value();
    int alumzak = ui->alumzakaz->value();
    int goldzak = ui->goldzakaz->value();
    int plumzak = ui->plumzakaz->value();
    int rezzak = ui->rezzakaz->value();
    emit zakMaterials(woodzak, ironzak,alumzak,goldzak,plumzak,rezzak);
}

