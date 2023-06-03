#ifndef BRANCHANDBOUND_H
#define BRANCHANDBOUND_H
#include "mainwindow.h"

struct BranchAndBound {
    int currentVertex; // Текущая вершина
    vector<int> path; // Пройденный путь
    int distance; // Текущее расстояние

    BranchAndBound(int vertex, const vector<int>& p, int dist)
        : currentVertex(vertex), path(p), distance(dist) {}

};

pair<int, vector<int>> solveTravelingSalesmanProblem(const vector<vector<int>>& graph) {
    int n = graph.size(); // Количество вершин графа
    vector<int> vertexIndices(n);
    for (int i = 0; i < n; ++i) {
        vertexIndices[i] = i; // Индексы вершин
    }
    int minDistance = 999999; // Минимальное расстояние
    vector<int> minPath; // Кратчайший путь

    vector<BranchAndBound> branches; // Структура данных для хранения состояний ветвей
    // Инициализируем начальное состояние
    branches.emplace_back(vertexIndices[0], vector<int>{vertexIndices[0]}, 0);

    while (!branches.empty()) {
        // Извлекаем состояние ветви с наиболее перспективным расстоянием
        auto currentState = branches.back();
        branches.pop_back();

        // Проверяем, является ли текущее состояние допустимым (все вершины посещены)
        if (currentState.path.size() == n) {
            // Добавляем расстояние от последней вершины к исходной
            int finalDistance = currentState.distance + graph[currentState.currentVertex][vertexIndices[0]];
            if (finalDistance < minDistance) {
                minDistance = finalDistance;
                minPath = currentState.path;
                minPath.push_back(vertexIndices[0]);
            }
        } else {
            // Создаем и добавляем новые состояния ветвей
            for (int i = 1; i < n; ++i) {
                int nextVertex = vertexIndices[i]; // Следующая вершина

                // Проверяем, что вершина еще не посещена
                if (find(currentState.path.begin(), currentState.path.end(), nextVertex) == currentState.path.end()) {
                    int distanceToNext = graph[currentState.currentVertex][nextVertex];
                    if (distanceToNext != 0 && currentState.distance + distanceToNext < minDistance) {
                        vector<int> newPath = currentState.path;
                        newPath.push_back(nextVertex);

                        branches.emplace_back(nextVertex, newPath, currentState.distance + distanceToNext);
                    }
                }
            }
        }
    }

    return make_pair(minDistance, minPath);
}
#endif // BRANCHANDBOUND_H
