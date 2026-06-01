#pragma once
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <string>
#include <mutex>

struct FarmRecord {
    int farmID;
    std::string location;
    std::string crop;
    double revenue;
    double expenses;

    double getProfit() const;
};

class FarmManager {
private:
    static const int MAX_FARMS = 5;
    FarmRecord m_farms[MAX_FARMS];
    int m_count;
    mutable std::mutex m_mutex;

    void printFarm(const FarmRecord& farm) const;

public:
    FarmManager();
    ~FarmManager();

    bool insertFarm(int id, const std::string& location, const std::string& crop,
        double revenue, double expenses);
    bool searchByID(int id) const;
    void displayAll() const;
    int getCount() const;
};