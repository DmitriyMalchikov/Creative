#ifndef BRANCHANDBOUND_H
#define BRANCHANDBOUND_H
#include "mainwindow.h"

struct BranchAndBound {
    int currentVertex;
    vector<int> path;
    int distance;
    BranchAndBound(int vertex, const vector<int>& p, int dist)

        : currentVertex(vertex), path(p), distance(dist) {}

};

pair<int, vector<int>> TSP(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> vertexId(n);
    for (int i = 0; i < n; ++i) {
        vertexId[i] = i;
    }
    int minDistance = 999999;
    vector<int> minPath;

    vector<BranchAndBound> branches;
    branches.emplace_back(vertexId[0], vector<int>{vertexId[0]}, 0);

    while (!branches.empty()) {

        auto currentState = branches.back();
        branches.pop_back();


        if (currentState.path.size() == n) {

            int finalDistance = currentState.distance + graph[currentState.currentVertex][vertexId[0]];
            if (finalDistance < minDistance) {
                minDistance = finalDistance;
                minPath = currentState.path;
                minPath.push_back(vertexId[0]);
            }
        } else {

            for (int i = 1; i < n; ++i) {
                int nextVertex = vertexId[i];


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
