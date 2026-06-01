#include "FarmManager.h"
#include "ConsoleColors.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <mutex>

using namespace std;

double FarmRecord::getProfit() const {
    return revenue - expenses;
}

FarmManager::FarmManager() : m_count(0) {
    for (int i = 0; i < MAX_FARMS; i++) {
        m_farms[i].farmID = -1;
    }
}

FarmManager::~FarmManager() {}

void FarmManager::printFarm(const FarmRecord& farm) const {
    setColor(15);
    cout << "  +-----------------------------------+" << endl;
    cout << "  | Farm ID:     " << farm.farmID << endl;
    cout << "  | Location:    " << farm.location << endl;
    cout << "  | Crop:        " << farm.crop << endl;
    cout << "  | Revenue:     $" << fixed << setprecision(2) << farm.revenue << endl;
    cout << "  | Expenses:    $" << farm.expenses << endl;
    cout << "  | Profit:      $" << farm.getProfit() << endl;
    cout << "  +-----------------------------------+" << endl;
    setColor(7);
}

bool FarmManager::insertFarm(int id, const string& location, const string& crop,
    double revenue, double expenses) {
    lock_guard<mutex> lock(m_mutex);

    try {
        if (m_count >= MAX_FARMS) {
            throw runtime_error("Farm array is full (max " + to_string(MAX_FARMS) + ")");
        }
        if (id <= 0) {
            throw invalid_argument("Farm ID must be positive");
        }
        if (revenue < 0 || expenses < 0) {
            throw invalid_argument("Revenue and expenses cannot be negative");
        }

        // Check for duplicate ID
        for (int i = 0; i < m_count; i++) {
            if (m_farms[i].farmID == id) {
                throw runtime_error("Farm ID " + to_string(id) + " already exists");
            }
        }

        m_farms[m_count] = { id, location, crop, revenue, expenses };
        m_count++;

        setColor(10);
        cout << "[FARM] Added farm #" << id << " at " << location << endl;
        setColor(7);
        return true;
    }
    catch (const exception& e) {
        setColor(12);
        cerr << "[FARM ERROR] " << e.what() << endl;
        setColor(7);
        return false;
    }
}

bool FarmManager::searchByID(int id) const {
    lock_guard<mutex> lock(m_mutex);

    setColor(11);
    cout << "___________________________________" << endl;
    cout << "Searching for Farm ID: " << id << endl;
    cout << "___________________________________" << endl;
    setColor(7);

    try {
        for (int i = 0; i < m_count; i++) {
            if (m_farms[i].farmID == id) {
                printFarm(m_farms[i]);
                setColor(10);
                cout << "[SEARCH] Farm found!" << endl;
                setColor(7);
                return true;
            }
        }

        throw runtime_error("Farm ID " + to_string(id) + " not found");
    }
    catch (const exception& e) {
        setColor(12);
        cerr << "[SEARCH ERROR] " << e.what() << endl;
        setColor(7);
        return false;
    }
}

void FarmManager::displayAll() const {
    lock_guard<mutex> lock(m_mutex);

    setColor(11);
    cout << "___________________________________" << endl;
    cout << "All Farms (" << m_count << "/" << MAX_FARMS << "):" << endl;
    cout << "___________________________________" << endl;
    setColor(7);

    if (m_count == 0) {
        setColor(14);
        cout << "  [No farms registered]" << endl;
        setColor(7);
        return;
    }

    for (int i = 0; i < m_count; i++) {
        printFarm(m_farms[i]);
        if (i < m_count - 1) cout << endl;
    }

    setColor(11);
    cout << "___________________________________" << endl;
    setColor(7);
}

int FarmManager::getCount() const {
    return m_count;
}