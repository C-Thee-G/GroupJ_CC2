#include "FarmGraph.h"
#include "ConsoleColors.h"
#include <iostream>
#include <queue>
#include <stdexcept>
#include <mutex>

using namespace std;

FarmGraph::FarmGraph() {}

FarmGraph::~FarmGraph() {}

void FarmGraph::addPlot(int plotId) {
    lock_guard<mutex> lock(m_mutex);

    try {
        if (m_adjacency.find(plotId) != m_adjacency.end()) {
            throw runtime_error("Plot already exists");
        }

        m_adjacency[plotId] = vector<int>();
        setColor(10);
        cout << "[GRAPH] Plot " << plotId << " created" << endl;
        setColor(7);
    }
    catch (const exception& e) {
        setColor(12);
        cerr << "[GRAPH ERROR] " << e.what() << endl;
        setColor(7);
    }
}

void FarmGraph::addIrrigationEdge(int plot1, int plot2) {
    lock_guard<mutex> lock(m_mutex);

    try {
        if (m_adjacency.find(plot1) == m_adjacency.end()) {
            throw runtime_error("Plot " + to_string(plot1) + " doesn't exist");
        }
        if (m_adjacency.find(plot2) == m_adjacency.end()) {
            throw runtime_error("Plot " + to_string(plot2) + " doesn't exist");
        }

        m_adjacency[plot1].push_back(plot2);
        m_adjacency[plot2].push_back(plot1);
        setColor(10);
        cout << "[GRAPH] Irrigation: " << plot1 << " <-> " << plot2 << endl;
        setColor(7);
    }
    catch (const exception& e) {
        setColor(12);
        cerr << "[GRAPH ERROR] " << e.what() << endl;
        setColor(7);
    }
}

void FarmGraph::BFS(int start) const {
    lock_guard<mutex> lock(m_mutex);

    setColor(11);
    cout << "___________________________________" << endl;
    cout << "BFS - Starting from Plot " << start << ":" << endl;
    cout << "___________________________________" << endl;
    setColor(7);

    try {
        if (m_adjacency.find(start) == m_adjacency.end()) {
            throw runtime_error("Start plot not found");
        }

        set<int> visited;
        queue<int> q;

        visited.insert(start);
        q.push(start);

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << "  -> Plot " << current << endl;

            for (int neighbor : m_adjacency.at(current)) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
    }
    catch (const exception& e) {
        setColor(12);
        cerr << "[BFS ERROR] " << e.what() << endl;
        setColor(7);
    }

    setColor(11);
    cout << "___________________________________" << endl;
    setColor(7);
}

void FarmGraph::DFS(int start) const {
    lock_guard<mutex> lock(m_mutex);

    setColor(11);
    cout << "___________________________________" << endl;
    cout << "DFS - Starting from Plot " << start << ":" << endl;
    cout << "___________________________________" << endl;
    setColor(7);

    try {
        if (m_adjacency.find(start) == m_adjacency.end()) {
            throw runtime_error("Start plot not found");
        }

        set<int> visited;
        dfsHelper(start, visited);
    }
    catch (const exception& e) {
        setColor(12);
        cerr << "[DFS ERROR] " << e.what() << endl;
        setColor(7);
    }

    setColor(11);
    cout << "___________________________________" << endl;
    setColor(7);
}

void FarmGraph::dfsHelper(int current, set<int>& visited) const {
    visited.insert(current);
    cout << "  -> Plot " << current << endl;

    for (int neighbor : m_adjacency.at(current)) {
        if (visited.find(neighbor) == visited.end()) {
            dfsHelper(neighbor, visited);
        }
    }
}

void FarmGraph::display() const {
    lock_guard<mutex> lock(m_mutex);

    setColor(11);
    cout << "___________________________________" << endl;
    cout << "Irrigation Network:" << endl;
    cout << "___________________________________" << endl;
    setColor(7);

    if (m_adjacency.empty()) {
        setColor(14);
        cout << "  [No plots]" << endl;
        setColor(7);
        return;
    }

    for (const auto& pair : m_adjacency) {
        cout << "  Plot " << pair.first << " connects to: ";
        for (size_t i = 0; i < pair.second.size(); i++) {
            cout << pair.second[i];
            if (i < pair.second.size() - 1) cout << ", ";
        }
        cout << endl;
    }

    setColor(11);
    cout << "___________________________________" << endl;
    setColor(7);
}

bool FarmGraph::hasPlot(int plotId) const {
    return m_adjacency.find(plotId) != m_adjacency.end();
}