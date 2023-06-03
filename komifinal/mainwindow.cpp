#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "branchandbound.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addVertexButton_clicked()
{
    bool ok;
    int vertexIndex = QInputDialog::getInt(this, tr("Add Vertex"), tr("Enter vertex index:"), 0, 0, 999999, 1, &ok);
    if (ok) {
        int n = graph.size();
        for (int i = 0; i < n; ++i) {
            graph[i].push_back(0); // Добавляем нулевые веса для новой вершины
        }
        vector<int> newRow(n + 1, 0);
        graph.push_back(newRow); // Добавляем новую строку в матрицу смежности
        update();
    }
}


void MainWindow::on_removeVertexButton_clicked()
{
    bool ok;
    int vertexIndex = QInputDialog::getInt(this, tr("Remove Vertex"), tr("Enter vertex index:"), 0, 0, 999999, 1, &ok);
    if (ok && vertexIndex >= 0 && vertexIndex < graph.size()) {
        graph.erase(graph.begin() + vertexIndex); // Удаляем строку матрицы смежности
        for (auto& row : graph) {
            row.erase(row.begin() + vertexIndex); // Удаляем столбец матрицы смежности
        }
        update();
    }
}


void MainWindow::on_addEdgeButton_clicked()
{
    bool ok;
    int vertexIndex1 = QInputDialog::getInt(this, tr("Add Edge"), tr("Enter first vertex index:"), 0, 0, 999999, 1, &ok);
    if (ok && vertexIndex1 >= 0 && vertexIndex1 < graph.size()) {
        int vertexIndex2 = QInputDialog::getInt(this, tr("Add Edge"), tr("Enter second vertex index:"), 0, 0, 999999, 1, &ok);
        if (ok && vertexIndex2 >= 0 && vertexIndex2 < graph.size()) {
            int weight = QInputDialog::getInt(this, tr("Add Edge"), tr("Enter edge weight:"), 0, 0, 999999, 1, &ok);
            if (ok) {
                graph[vertexIndex1][vertexIndex2] = weight;
                graph[vertexIndex2][vertexIndex1] = weight;
                update();
            }
        }
    }
}


void MainWindow::on_removeEdgeButton_clicked()
{
    bool ok;
    int vertexIndex1 = QInputDialog::getInt(this, tr("Remove Edge"), tr("Enter first vertex index:"), 0, 0, 999999, 1, &ok);
    if (ok && vertexIndex1 >= 0 && vertexIndex1 < graph.size()) {
        int vertexIndex2 = QInputDialog::getInt(this, tr("Remove Edge"), tr("Enter second vertex index:"), 0, 0, 999999, 1, &ok);
        if (ok && vertexIndex2 >= 0 && vertexIndex2 < graph.size()) {
            graph[vertexIndex1][vertexIndex2] = 0;
            graph[vertexIndex2][vertexIndex1] = 0;
            update();
        }
    }
}

void MainWindow::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.translate(300,220);
    painter.setBrush(Qt::yellow);
    // Рисуем вершины графа
    double R = 2 * M_PI / int(graph.size());
    int radius = 20;
    for (int i = 0; i < int(graph.size()); i++) {
        double x = qCos(i * R) * 200;
        double y = qSin(i * R) * 200;

        painter.drawEllipse(QPointF(x, y), radius, radius);
        painter.drawText(QRectF(x - radius, y - radius, radius * 2, radius * 2), Qt::AlignCenter, QString::number(i));
    }

    // Рисуем ребра графа
    painter.setPen(Qt::red);
    for (int i = 0; i < int(graph.size()); ++i) {
        for (int j = i + 1; j < int(graph.size()); ++j) {
            if (graph[i][j] != 0) {
                double x1 = qCos(i * R) * 200;
                double y1 = qSin(i * R) * 200;
                double x2 = qCos(j * R) * 200;
                double y2 = qSin(j * R) * 200;
                painter.drawLine(QPointF(x1, y1), QPointF(x2, y2));

                int weight = graph[i][j];
                double dx = x2 - x1;
                double dy = y2 - y1;
                double vlen = qSqrt(dx * dx + dy * dy);
                double dx2 = dy / vlen ;
                double dy2 = -dx / vlen ;
                painter.drawText(QRectF((x1 + x2) / 2 + dx2 , (y1 + y2) / 2 + dy2, 20, 10), Qt::AlignCenter, QString::number(weight));
            }
        }
    }

    // Выводим минимальное расстояние и путь
    painter.setPen(Qt::black);
    painter.drawText(QRectF(-270, 200, 300, 30), Qt::AlignLeft, "Минимальная длина пути: " + QString::number(minDistance));

    // Рисуем минимальный путь
    painter.setPen(Qt::green);
    for (int i = 0; i < int(minPath.size()) - 1; ++i) {
        int vertex1 = minPath[i];
        int vertex2 = minPath[i + 1];

        double x1 = qCos(vertex1 * R) * 200;
        double y1 = qSin(vertex1 * R) * 200;
        double x2 = qCos(vertex2 * R) * 200;
        double y2 = qSin(vertex2 * R) * 200;

        painter.drawLine(QPointF(x1, y1), QPointF(x2, y2));
    }
    painter.setPen(Qt::black);
    QString pathText = "Кратчайший путь: ";
    for (int i = 0; i < int(minPath.size()); ++i) {
        pathText += QString::number(minPath[i]);
        if (i != int(minPath.size()) - 1) {
            pathText += " -> ";
        }
    }
    painter.drawText(QRectF(-270, 235, 300, 30), Qt::AlignLeft, pathText);
}

void MainWindow::update() {
    pair<int, vector<int>> result = solveTravelingSalesmanProblem(graph);
    minDistance = result.first;
    minPath = result.second;

    QWidget::update();
}
