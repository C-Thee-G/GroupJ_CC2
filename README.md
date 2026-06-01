# Farm Management System - Code Challenge 2
## APM11A1 - Advanced Programming

### Group Information
- **Group Number:** Group 1
- **Project Name:** Group1_CC2
- **Course:** APM11A1 - Advanced Programming
- **University:** University of Johannesburg

---

## Project Overview

The Farm Management System is a comprehensive C++ application demonstrating advanced programming concepts including data structures, compiler phases, parallel programming, array management, and professional reporting. The system helps manage farm operations including crop harvesting, sales tracking, irrigation networks, and farm record management.

---

## Features Implemented

### Part A: Data Structures
- **Harvest Queue (FIFO)** - Manages crops waiting to be harvested
- **Sales Stack (LIFO)** - Tracks recently sold crops
- **Farm Graph** - Irrigation connectivity with BFS/DFS traversal

### Part B: Compiler Phases Simulation
- **Lexical Analysis** - Tokenizes farm operation commands
- **Syntax Analysis** - Validates command structure (ADD_CROP <CropName>)
- **Semantic Analysis** - Ensures logical correctness (crop exists before harvesting)

### Part C: Parallel Programming
- **Thread 1** - Inserts crops into harvest queue
- **Thread 2** - Traverses farm graph for irrigation connectivity
- **Mutex Synchronization** - Protects shared resources

### Part D: Reporting & Error Handling
- Comprehensive summary report generation
- Graceful error handling with descriptive messages
- Color-coded console output for better readability

### Part E: Farm Array
- Fixed-size array (5 farms) storing farm records
- Insert farms with validation
- Search farms by ID with detailed output

### Part F: Code Quality
- Proper indentation and code organization
- Modular function design
- Comprehensive error handling with try-catch blocks
- Detailed comments explaining logic

---

## System Requirements

### Development Environment
- **IDE:** Visual Studio 2019 or 2022
- **Language:** C++17 or later
- **OS:** Windows (for color console output)

### Compiler Settings
- C++ Language Standard: C++17 or C++20
- Character Set: Unicode or Multi-Byte
- Configuration: Debug x64 or Release x64

---

## File Structure
