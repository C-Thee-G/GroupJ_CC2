#include "SalesStack.h"
#include "ConsoleColors.h"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <mutex>

using namespace std;

SalesStack::SalesStack(int maxSize) : m_maxSize(maxSize) {}

SalesStack::~SalesStack() {}

bool SalesStack::push(const string& crop) {
    lock_guard<mutex> lock(m_mutex);

    try {
        if (m_stack.size() >= m_maxSize) {
            throw runtime_error("Sales record stack is full");
        }

        m_stack.push(crop);
        setColor(10);
        cout << "[STACK] Sale recorded: " << crop << endl;
        setColor(7);
        return true;
    }
    catch (const exception& e) {
        setColor(12);
        cerr << "[STACK ERROR] " << e.what() << endl;
        setColor(7);
        return false;
    }
}

string SalesStack::pop() {
    lock_guard<mutex> lock(m_mutex);

    try {
        if (m_stack.empty()) {
            throw runtime_error("No sales to undo");
        }

        string crop = m_stack.top();
        m_stack.pop();
        setColor(13);
        cout << "[STACK] Sale undone: " << crop << endl;
        setColor(7);
        return crop;
    }
    catch (const exception& e) {
        setColor(12);
        cerr << "[STACK ERROR] " << e.what() << endl;
        setColor(7);
        return "";
    }
}

bool SalesStack::isEmpty() const {
    return m_stack.empty();
}

int SalesStack::size() const {
    return m_stack.size();
}

void SalesStack::display() const {
    setColor(11);
    cout << "___________________________________" << endl;
    cout << "Sales Stack (LIFO) - Recent Sales:" << endl;
    cout << "___________________________________" << endl;
    setColor(7);

    if (m_stack.empty()) {
        setColor(14);
        cout << "  [Empty]" << endl;
        setColor(7);
        return;
    }

    stack<string> temp = m_stack;
    vector<string> items;
    while (!temp.empty()) {
        items.push_back(temp.top());
        temp.pop();
    }

    for (size_t i = 0; i < items.size(); i++) {
        cout << "  " << (i + 1) << ". " << items[i];
        if (i == 0) cout << " (most recent)";
        cout << endl;
    }

    setColor(11);
    cout << "___________________________________" << endl;
    setColor(7);
}