
# 🌾 FARM MANAGEMENT SYSTEM
## APM11A1 - Advanced Programming
### Group J

---

## 📋 Project Description

The **Farm Management System** is a comprehensive C++ application that simulates real-world farm operations. This project demonstrates advanced programming concepts including data structures, compiler design principles, parallel programming, and array management.

The system manages:
- Crop harvesting queues
- Sales tracking
- Irrigation network connectivity
- Farm record keeping
- Command processing through a three-phase compiler

---

## 👥 Group Information

| **Item** | **Details** |
|----------|-------------|
| **Group Number** | Group J |
| **Project Name** | GroupJ_CC2 |
| **Course Code** | APM11A1 |
| **University** | University of Johannesburg |
| **Submission Date** | June 2026 |

### Group Members
- Member 1: Mongiwethu Eddy Ncube
- Member 2: Sandile Sibeke  
- Member 3: Bongane Sithole
- Member 4: Zizile Ezona Mbanqi
- Member 5: Keamogetse Selebano
- Member 6: Hlonipho Nersley Bila
- Member 6: Ndzulamo Michelle Yingwani

---

## 🙏 Special Thanks

### Mr. David Taole

We would like to express our sincere gratitude to **Mr. David Taole** for his exceptional teaching throughout this module.

Mr. Taole has a unique ability to transform complex programming concepts into engaging, understandable lessons. His passion for teaching and dedication to student success has made Advanced Programming one of the most enjoyable courses in our academic journey.

**Thank you for making learning fun and inspiring us to become better programmers!** 🎓

---

## 🎥 Learning Resources

The following YouTube channels and resources helped us complete this project:

### Data Structures & Algorithms
| Channel | Topic |
|---------|-------|
| **The Cherno** | C++ programming, data structures |
| **WilliamFiset** | Graph algorithms (BFS, DFS) |
| **mycodeschool** | Queue, Stack, Graph implementations |
| **CodeBeauty** | C++ object-oriented programming |

### Compiler Design
| Channel | Topic |
|---------|-------|
| **Neso Academy** | Lexical analysis, tokenization |
| **Gate Smashers** | Syntax analysis, parsing |
| **Education 4u** | Semantic analysis |

### Parallel Programming
| Channel | Topic |
|---------|-------|
| **The Cherno** | Multithreading in C++ |
| **CodeVault** | Mutex and thread synchronization |
| **javidx9** | std::thread tutorial |

### Development Tools
| Channel | Topic |
|---------|-------|
| **Microsoft Visual Studio** | IDE setup and debugging |
| **Programming with Mosh** | Visual Studio 2022 tutorials |

---

## 💻 System Requirements

### Minimum Requirements
| Component | Requirement |
|-----------|-------------|
| **Operating System** | Windows 10/11 |
| **IDE** | Visual Studio 2019 or 2022 |
| **C++ Standard** | C++17 or later |
| **Architecture** | x64 or x86 |
| **RAM** | 4GB minimum |
| **Disk Space** | 100MB free |

### Recommended Settings
```
C++ Language Standard: C++17 (/std:c++17)
Configuration: Debug x64
Character Set: Unicode
Platform Toolset: Visual Studio 2022 (v143)
```

---

## 📁 File Structure

```
GroupJ_CC2/
│
├── GroupJ_CC2.sln                      # Visual Studio solution file
│
├── GroupJ_CC2/                         # Main project directory
│   │
│   ├── main.cpp                        # Program entry point
│   ├── ConsoleColors.cpp               # Console color functions
│   ├── ConsoleColors.h                 # Color function declarations
│   │
│   ├── HarvestQueue.cpp                # FIFO Queue implementation
│   ├── HarvestQueue.h                  # Queue class declaration
│   │
│   ├── SalesStack.cpp                  # LIFO Stack implementation
│   ├── SalesStack.h                    # Stack class declaration
│   │
│   ├── FarmGraph.cpp                   # Graph with BFS/DFS
│   ├── FarmGraph.h                     # Graph class declaration
│   │
│   ├── FarmManager.cpp                 # Farm array management
│   ├── FarmManager.h                   # Farm array class declaration
│   │
│   ├── Compiler.cpp                    # Three-phase compiler
│   ├── Compiler.h                      # Compiler class declaration
│   │
│   └── Documentation/                  # Project documentation
│       ├── README.md                   # This file
│       └── screenshots/                # Output screenshots
│
└── .gitignore                          # Git ignore file
```

---

## 🚀 Installation & Setup

### Visual Studio 2022 Setup

1. **Open the solution**
   ```
   File → Open → Project/Solution
   Select: GroupJ_CC2.sln
   ```

2. **Configure build settings**
   ```
   Build → Configuration Manager
   Active solution configuration: Debug
   Active solution platform: x64
   ```

3. **Build the project**
   ```
   Build → Clean Solution
   Build → Rebuild Solution
   ```

4. **Run the program**
   ```
   Debug → Start Without Debugging (Ctrl + F5)
   ```

### Command Line Compilation

Open **Developer Command Prompt for VS 2022** and run:

```bash
cd C:\Users\Student\source\repos\GroupJ_CC2

cl /EHsc /std:c++17 /Fe:GroupJ_CC2.exe ^
    main.cpp ^
    HarvestQueue.cpp ^
    SalesStack.cpp ^
    FarmGraph.cpp ^
    FarmManager.cpp ^
    Compiler.cpp ^
    ConsoleColors.cpp

GroupJ_CC2.exe
```

---

## 🎮 Program Features

### 1. Harvest Queue (FIFO)
- Crops waiting to be harvested are stored in a queue
- First-in, first-out harvesting order
- Thread-safe operations with mutex protection

### 2. Sales Stack (LIFO)
- Recently sold crops are tracked in a stack
- Last-in, first-out for undoing sales
- Displays most recent transactions first

### 3. Irrigation Graph
- Farm plots connected through irrigation pipes
- BFS (Breadth-First Search) traversal
- DFS (Depth-First Search) traversal
- Shows water flow through the network

### 4. Compiler Simulation
- **Lexical Analysis**: Breaks commands into tokens
- **Syntax Analysis**: Validates command structure
- **Semantic Analysis**: Ensures logical correctness

### 5. Parallel Processing
- Two threads run simultaneously
- One thread adds crops to queue
- Another thread traverses the graph
- Mutex prevents data conflicts

### 6. Farm Records
- Stores up to 5 farms in a fixed array
- Each record contains: ID, Location, Crop, Revenue, Expenses
- Search farms by ID
- Calculates profit automatically

### 7. Color-Coded Output
- 🟢 Green: Successful operations
- 🔴 Red: Error messages
- 🟡 Yellow: Section headers
- 🔵 Cyan: Data displays
- ⚪ White: Farm record details

---

## 📝 Command Reference

The compiler accepts these commands during simulation:

| Command | Format | Description |
|---------|--------|-------------|
| **ADD_CROP** | `ADD_CROP <cropname>` | Plant a new crop in the field |
| **HARVEST** | `HARVEST <cropname>` | Harvest a planted crop |
| **SELL** | `SELL <cropname>` | Sell a harvested crop |

### Examples

```
ADD_CROP Maize
ADD_CROP Wheat
HARVEST Maize
SELL Maize
```

---

## 📸 Screenshots

### Main Program Interface
![Main Program](screenshots/main_output.png)
*Program startup showing the main interface*

### Queue Operations
![Queue Operations](<img width="601" height="530" alt="harvest queue" src="https://github.com/user-attachments/assets/fb9b0f1c-f563-4cca-8f7e-f639d60cc5e8" />
)
*Enqueue and dequeue operations on harvest queue*

### Stack Operations  
![Stack Operations](screenshots/stack_output.png)
*Push and pop operations on sales stack*

### Graph Traversal
![Graph BFS/DFS](screenshots/graph_output.png)
*BFS and DFS traversal of irrigation network*

### Compiler Phases
![Compiler Output](screenshots/compiler_output.png)
*Lexical, syntax, and semantic analysis*

### Farm Array Management
![Farm Records](screenshots/farmarray_output.png)
*Insert, display, and search farm records*

### Summary Report
![Final Report](screenshots/report_output.png)
*Complete system status summary*

> **Note:** To capture screenshots, run the program and use `Windows + Shift + S` or `Alt + PrtScn`. Save images in the `Documentation/screenshots/` folder.

---

## 🛠️ Troubleshooting

### Compilation Errors

| Problem | Solution |
|---------|----------|
| `'mutex' is not a member of 'std'` | Add `#include <mutex>` to header files |
| `'byte': ambiguous symbol` | Add `#define WIN32_LEAN_AND_MEAN` and `#define NOMINMAX` to headers |
| `setColor already defined` | Keep setColor definition only in ConsoleColors.cpp |
| `C3646: unknown override specifier` | Check struct syntax and add missing semicolons |
| `LNK2019: unresolved external symbol` | Ensure all .cpp files are added to the project |

### Runtime Issues

| Problem | Solution |
|---------|----------|
| No colors in output | Run in Windows Terminal instead of embedded VS terminal |
| Program crashes on start | Check that all required files are included |
| Thread hangs | Ensure mutex locks are properly released |
| Wrong output order | Check that threads are joined properly |

### Visual Studio Specific

If you encounter persistent issues:

1. **Reset Visual Studio settings**
   ```
   Tools → Import and Export Settings → Reset all settings
   ```

2. **Repair Visual Studio installation**
   ```
   Visual Studio Installer → More → Repair
   ```

3. **Clear temporary files**
   ```
   Delete Debug/ and Release/ folders
   Delete .vs folder (hidden)
   Rebuild solution
   ```

---

## 📚 Sample Data Used

The program uses the following sample data for demonstration:

### Queue (Waiting for Harvest)
- Maize
- Wheat
- Sorghum

### Stack (Recent Sales)
- Maize
- Wheat

### Graph (Irrigation Network)
```
Plot 1 --- Plot 2 --- Plot 3 --- Plot 4
        Edge        Edge        Edge
```

### Farm Array (5 Farms)
| ID | Location | Crop | Revenue | Expenses |
|----|----------|------|---------|----------|
| 101 | North Field | Maize | $50,000 | $32,000 |
| 102 | South Valley | Wheat | $45,000 | $28,000 |
| 103 | East Plains | Sorghum | $38,000 | $25,000 |
| 104 | West Hills | Barley | $42,000 | $27,000 |
| 105 | Central Farm | Oats | $35,000 | $22,000 |

---

## 📖 Code Documentation

### Key Classes

| Class | Purpose | Key Methods |
|-------|---------|-------------|
| `HarvestQueue` | FIFO crop management | `enqueue()`, `dequeue()`, `display()` |
| `SalesStack` | LIFO sales tracking | `push()`, `pop()`, `display()` |
| `FarmGraph` | Irrigation network | `addPlot()`, `addEdge()`, `BFS()`, `DFS()` |
| `FarmManager` | Farm record storage | `insertFarm()`, `searchByID()`, `displayAll()` |
| `Compiler` | Command processing | `processCommand()`, `displayStatus()` |
| `ConsoleColors` | Output formatting | `setColor()` |

### Thread Safety

All shared resources are protected using `std::mutex` and `std::lock_guard`:

```cpp
std::lock_guard<std::mutex> lock(m_mutex);
// Critical section code here
```

---

## 🙌 Acknowledgments

### Course Instructor
**Mr. David Taole** - For outstanding teaching and making this module both challenging and enjoyable.

### YouTube Educators
- **The Cherno** - Excellent C++ tutorials
- **WilliamFiset** - Clear graph algorithm explanations
- **mycodeschool** - Foundational data structures
- **Neso Academy** - Comprehensive compiler design
- **CodeBeauty** - Practical C++ examples

### University Resources
- University of Johannesburg
- APM11A1 Course Materials

---

## 📄 Declaration

We hereby declare that this submission is our own original work. All external sources have been properly referenced. No plagiarism has occurred in this assignment.

**Signed:** Group J

**Date:** June 2026

---

## 📧 Contact

For questions regarding this submission:
- **Course:** APM11A1 - Advanced Programming
- **Instructor:** Mr. David Taole
- **Institution:** University of Johannesburg

---

## 🔄 Version History

| Version | Date | Changes |
|---------|------|---------|
| 1.0 | June 2026 | Initial release |
| 2.0 | June 2026 | Added compiler phases, threads, and farm array |

---

## 📜 License

This project was created for academic assessment at the University of Johannesburg. Unauthorized copying or distribution violates the university's plagiarism policy.

---

**© 2026 Group J - University of Johannesburg**

*Created with dedication for APM11A1 Advanced Programming*
```

---

## **QUICKSTART.txt (Simplified Version)**

```text
╔═══════════════════════════════════════════════════════════════╗
║                                                               ║
║              FARM MANAGEMENT SYSTEM - GROUP J                 ║
║                     QUICK START GUIDE                         ║
║                                                               ║
╚═══════════════════════════════════════════════════════════════╝

📁 PROJECT FILES
═══════════════════════════════════════════════════════════════

GroupJ_CC2/
├── GroupJ_CC2.sln          ← Double-click to open in VS2022
├── main.cpp                ← Program starts here
├── HarvestQueue.h/cpp      ← Queue (FIFO)
├── SalesStack.h/cpp        ← Stack (LIFO)  
├── FarmGraph.h/cpp         ← Graph (BFS/DFS)
├── FarmManager.h/cpp       ← Farm array (5 farms)
├── Compiler.h/cpp          ← 3-phase compiler
├── ConsoleColors.h/cpp     ← Colors for output
└── Documentation/
    ├── README.md           ← Full documentation
    └── screenshots/        ← Place screenshots here

🚀 RUN THE PROGRAM
═══════════════════════════════════════════════════════════════

1. Open Visual Studio 2022
2. File → Open → Project/Solution → GroupJ_CC2.sln
3. Build → Rebuild Solution
4. Debug → Start Without Debugging (Ctrl+F5)

🎨 COLOR GUIDE
═══════════════════════════════════════════════════════════════

🟢 GREEN  = Success / Working ✓
🔴 RED    = Errors / Failures ✗
🟡 YELLOW = Section Headers
🔵 CYAN   = Data Display
⚪ WHITE  = Farm Records

📸 TAKE SCREENSHOTS
═══════════════════════════════════════════════════════════════

While program is running, capture:

• Main program startup
• Queue operations
• Stack operations  
• Graph BFS/DFS
• Compiler phases
• Thread execution
• Farm array display
• Final report

Save as PNG in Documentation/screenshots/

🎓 YOUTUBE CHANNELS WE USED
═══════════════════════════════════════════════════════════════

• The Cherno - C++ programming
• WilliamFiset - Graph algorithms
• mycodeschool - Data structures
• Neso Academy - Compiler design
• CodeVault - Multithreading
• Gate Smashers - Syntax analysis

🙏 SPECIAL THANKS
═══════════════════════════════════════════════════════════════

MR. DAVID TAOLE
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

Thank you for making Advanced Programming an amazing journey!

Your teaching style makes complex concepts easy to understand.

Best programming lecturer! 👏

🔧 COMMON ISSUES
═══════════════════════════════════════════════════════════════

ERROR: 'byte' ambiguous symbol
FIX: Add these to header files:
     #define WIN32_LEAN_AND_MEAN
     #define NOMINMAX

ERROR: setColor already defined  
FIX: Keep setColor only in ConsoleColors.cpp

NO COLORS in output
FIX: Run in Windows Console (not embedded terminal)

═══════════════════════════════════════════════════════════════
For full documentation, see README.md
═══════════════════════════════════════════════════════════════
```

