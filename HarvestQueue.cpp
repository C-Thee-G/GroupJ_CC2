#include "HarvestQueue.h"
#include "ConsoleColors.h"
#include <iostream>
#include <stdexcept>
#include <mutex>

using namespace std;

HarvestQueue::HarvestQueue(int maxSize) : m_maxSize(maxSize) {}

HarvestQueue::~HarvestQueue() {}

bool HarvestQueue::enqueue(const string& crop) {
    lock_guard<mutex> lock(m_mutex);

    try {
        if (m_queue.size() >= m_maxSize) {
            throw runtime_error("Queue is full");
        }

        m_queue.push(crop);
        setColor(10);
        cout << "[QUEUE] Added: " << crop << endl;
        setColor(7);
        return true;
    }
    catch (const exception& e) {
        setColor(12);
        cerr << "[QUEUE ERROR] " << e.what() << " - Cannot add: " << crop << endl;
        setColor(7);
        return false;
    }
}

string HarvestQueue::dequeue() {
    lock_guard<mutex> lock(m_mutex);

    try {
        if (m_queue.empty()) {
            throw runtime_error("No crops to harvest");
        }

        string crop = m_queue.front();
        m_queue.pop();
        setColor(14);
        cout << "[QUEUE] Harvested: " << crop << endl;
        setColor(7);
        return crop;
    }
    catch (const exception& e) {
        setColor(12);
        cerr << "[QUEUE ERROR] " << e.what() << endl;
        setColor(7);
        return "";
    }
}

bool HarvestQueue::isEmpty() const {
    return m_queue.empty();
}

int HarvestQueue::size() const {
    return m_queue.size();
}

void HarvestQueue::display() const {
    setColor(11);
    cout << "___________________________________" << endl;
    cout << "Harvest Queue (FIFO) - Ready to Harvest:" << endl;
    cout << "___________________________________" << endl;
    setColor(7);

    if (m_queue.empty()) {
        setColor(14);
        cout << "  [Empty]" << endl;
        setColor(7);
        return;
    }

    queue<string> temp = m_queue;
    int pos = 1;
    while (!temp.empty()) {
        cout << "  " << pos++ << ". " << temp.front() << endl;
        temp.pop();
    }

    setColor(11);
    cout << "___________________________________" << endl;
    setColor(7);
}