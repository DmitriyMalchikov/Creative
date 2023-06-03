#ifndef DOSTWINDOW_H
#define DOSTWINDOW_H

#include <QWidget>

namespace Ui {
class DostWindow;
}

class DostWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DostWindow(QWidget *parent = nullptr);
    ~DostWindow();

private slots:
    void on_menuButtonDost_clicked();
    void on_dostavit_clicked();

signals:
    void showMenu();
    void dostMaterials(int,int,int,int,int,int);
private:
    Ui::DostWindow *ui;
};

#endif // DOSTWINDOW_H
