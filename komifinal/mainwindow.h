#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include <QtMath>
#include <QPainter>
#include <QPair>
using namespace std;

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
    void on_addVertexButton_clicked();

    void on_removeVertexButton_clicked();

    void on_addEdgeButton_clicked();

    void on_removeEdgeButton_clicked();

    void paintEvent(QPaintEvent* event) override;

    void update();
private:
    Ui::MainWindow *ui;
    std::vector<std::vector<int>> graph; // Матрица смежности
    int minDistance; // Минимальное расстояние
    std::vector<int> minPath; // Кратчайший путь
};
#endif // MAINWINDOW_H
