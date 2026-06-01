#define WIN32_LEAN_AND_MEAN
#define NOMINMAX

#include "ConsoleColors.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <string>
#include <mutex>

#include "HarvestQueue.h"
#include "SalesStack.h"
#include "FarmGraph.h"
#include "FarmManager.h"
#include "Compiler.h"

using namespace std;

// Global mutex for thread safety
mutex g_mutex;
bool g_running = true;

// Thread function for inserting crops
void insertCropsThread(HarvestQueue& queue, const vector<string>& crops) {
    for (const auto& crop : crops) {
        this_thread::sleep_for(chrono::milliseconds(150));
        {
            lock_guard<mutex> lock(g_mutex);
            queue.enqueue(crop);
        }
    }
    g_running = false;
}

// Thread function for traversing graph
void traverseGraphThread(FarmGraph& graph, int start) {
    this_thread::sleep_for(chrono::milliseconds(300));
    {
        lock_guard<mutex> lock(g_mutex);
        graph.BFS(start);
    }
}

// Generate final report
void generateReport(HarvestQueue& hq, SalesStack& ss, FarmGraph& fg,
    FarmManager& fm, Compiler& comp) {
    setColor(15);
    cout << "\n============================================================" << endl;
    cout << "              FINAL FARM MANAGEMENT REPORT              " << endl;
    cout << "============================================================" << endl;
    setColor(7);

    cout << endl;
    hq.display();
    cout << endl;
    ss.display();
    cout << endl;
    fg.display();
    cout << endl;
    fm.displayAll();
    cout << endl;
    comp.displayStatus();

    setColor(10);
    cout << "\n[REPORT] Generation complete" << endl;
    setColor(7);
}

int main() {
    setColor(11);
    cout << "============================================================" << endl;
    cout << "            FARM MANAGEMENT SYSTEM - v1.0               " << endl;
    cout << "                    Group 1 - CC2                       " << endl;
    cout << "============================================================" << endl;
    cout << endl;
    setColor(7);

    try {
        // Create all components
        HarvestQueue harvestQueue;
        SalesStack salesStack;
        FarmGraph farmGraph;
        FarmManager farmManager;
        Compiler compiler;

        // ========== PART A: Queue Demo ==========
        setColor(14);
        cout << "\n========== PART A: HARVEST QUEUE (FIFO) ==========\n" << endl;
        setColor(7);

        harvestQueue.enqueue("Maize");
        harvestQueue.enqueue("Wheat");
        harvestQueue.enqueue("Sorghum");
        harvestQueue.display();

        harvestQueue.dequeue();
        harvestQueue.display();

        // ========== PART A: Stack Demo ==========
        setColor(14);
        cout << "\n========== PART A: SALES STACK (LIFO) ==========\n" << endl;
        setColor(7);

        salesStack.push("Maize");
        salesStack.push("Wheat");
        salesStack.display();

        salesStack.pop();
        salesStack.display();

        // ========== PART A: Graph Demo ==========
        setColor(14);
        cout << "\n========== PART A: IRRIGATION GRAPH ==========\n" << endl;
        setColor(7);

        farmGraph.addPlot(1);
        farmGraph.addPlot(2);
        farmGraph.addPlot(3);
        farmGraph.addPlot(4);
        farmGraph.addIrrigationEdge(1, 2);
        farmGraph.addIrrigationEdge(2, 3);
        farmGraph.addIrrigationEdge(3, 4);
        farmGraph.display();
        farmGraph.BFS(1);
        farmGraph.DFS(1);

        // ========== PART B: Compiler Demo ==========
        setColor(14);
        cout << "\n========== PART B: COMPILER SIMULATION ==========\n" << endl;
        setColor(7);

        compiler.processCommand("ADD_CROP Maize");
        compiler.processCommand("ADD_CROP Wheat");
        compiler.processCommand("HARVEST Maize");
        compiler.processCommand("HARVEST Barley");
        compiler.processCommand("SELL Maize");
        compiler.processCommand("SELL Wheat");
        compiler.processCommand("BAD_COMMAND Corn");

        // ========== PART C: Parallel Programming ==========
        setColor(14);
        cout << "\n========== PART C: PARALLEL THREADS ==========\n" << endl;
        setColor(7);

        vector<string> newCrops;
        newCrops.push_back("Soybean");
        newCrops.push_back("Barley");
        newCrops.push_back("Oats");

        thread t1(insertCropsThread, ref(harvestQueue), newCrops);
        thread t2(traverseGraphThread, ref(farmGraph), 1);

        t1.join();
        t2.join();

        harvestQueue.display();

        // ========== PART E: Farm Array ==========
        setColor(14);
        cout << "\n========== PART E: FARM ARRAY ==========\n" << endl;
        setColor(7);

        farmManager.insertFarm(101, "North Field", "Maize", 50000, 32000);
        farmManager.insertFarm(102, "South Valley", "Wheat", 45000, 28000);
        farmManager.insertFarm(103, "East Plains", "Sorghum", 38000, 25000);
        farmManager.insertFarm(104, "West Hills", "Barley", 42000, 27000);
        farmManager.insertFarm(105, "Central Farm", "Oats", 35000, 22000);

        farmManager.insertFarm(106, "Overflow", "Rye", 10000, 5000);

        farmManager.displayAll();
        farmManager.searchByID(103);
        farmManager.searchByID(999);

        // ========== PART D: Final Report ==========
        setColor(14);
        cout << "\n========== PART D: SUMMARY REPORT ==========\n" << endl;
        setColor(7);

        generateReport(harvestQueue, salesStack, farmGraph, farmManager, compiler);

        setColor(10);
        cout << "\n============================================================" << endl;
        cout << "              PROGRAM COMPLETED SUCCESSFULLY             " << endl;
        cout << "============================================================" << endl;
        setColor(7);

    }
    catch (const exception& e) {
        setColor(12);
        cerr << "\n[FATAL ERROR] " << e.what() << endl;
        cerr << "Program terminated" << endl;
        setColor(7);
        return 1;
    }

    cout << "\nPress Enter to exit...";
    cin.get();

    return 0;
}