#ifndef SOSTWINDOW_H
#define SOSTWINDOW_H

#include <QWidget>

namespace Ui {
class SostWindow;
}

class SostWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SostWindow(QWidget *parent = nullptr);
    ~SostWindow();

private slots:
    void on_menuButtonSost_clicked();
    void updateMaterialsDost(int,int,int,int,int,int);
    void updateMaterialsZak(int,int,int,int,int,int);
signals:
    void showMenu();
private:
    Ui::SostWindow *ui;
};

#endif // SOSTWINDOW_H
