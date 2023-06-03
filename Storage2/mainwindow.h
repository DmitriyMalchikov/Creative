#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sostwindow.h"
#include "dostwindow.h"
#include "zakazwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_dostavka_clicked();

    void on_sostoyanie_clicked();

    void on_zakaz_clicked();

private:
    Ui::MainWindow *ui;
    SostWindow* sostwindow;
    DostWindow* dostwindow;
    ZakazWindow* zakwindow;
};
#endif // MAINWINDOW_H
