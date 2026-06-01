#pragma once
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <string>
#include <vector>
#include <map>
#include <set>
#include <mutex>

class FarmGraph {
private:
    std::map<int, std::vector<int>> m_adjacency;
    mutable std::mutex m_mutex;

    void dfsHelper(int current, std::set<int>& visited) const;

public:
    FarmGraph();
    ~FarmGraph();

    void addPlot(int plotId);
    void addIrrigationEdge(int plot1, int plot2);
    void BFS(int start) const;
    void DFS(int start) const;
    void display() const;
    bool hasPlot(int plotId) const;
};