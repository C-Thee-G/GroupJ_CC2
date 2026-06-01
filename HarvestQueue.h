#pragma once
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <string>
#include <queue>
#include <mutex>

class HarvestQueue {
private:
    std::queue<std::string> m_queue;
    std::mutex m_mutex;
    int m_maxSize;

public:
    HarvestQueue(int maxSize = 100);
    ~HarvestQueue();

    bool enqueue(const std::string& crop);
    std::string dequeue();
    bool isEmpty() const;
    int size() const;
    void display() const;
};