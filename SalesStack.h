#pragma once
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <string>
#include <stack>
#include <mutex>

class SalesStack {
private:
    std::stack<std::string> m_stack;
    std::mutex m_mutex;
    int m_maxSize;

public:
    SalesStack(int maxSize = 100);
    ~SalesStack();

    bool push(const std::string& crop);
    std::string pop();
    bool isEmpty() const;
    int size() const;
    void display() const;
};