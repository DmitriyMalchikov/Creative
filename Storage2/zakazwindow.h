#ifndef ZAKAZWINDOW_H
#define ZAKAZWINDOW_H

#include <QWidget>

namespace Ui {
class ZakazWindow;
}

class ZakazWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ZakazWindow(QWidget *parent = nullptr);
    ~ZakazWindow();
signals:
    void showMenu();
    void zakMaterials(int,int,int,int,int,int);
private slots:
    void on_menuButtonZakaz_clicked();

    void on_zakazat_clicked();

private:
    Ui::ZakazWindow *ui;
};

#endif // ZAKAZWINDOW_H
