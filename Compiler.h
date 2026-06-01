#pragma once
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX

#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

// Simple enum
enum CommandType {
    CMD_ADD_CROP,
    CMD_HARVEST,
    CMD_SELL,
    CMD_UNKNOWN,
    CMD_EMPTY
};

// Simple struct - no fancy stuff
struct ParsedCommand {
    CommandType type;
    string cropName;
    string originalText;
    bool isValid;
};

class Compiler
{
private:
    set<string> plantedCrops;
    set<string> harvestedCrops;

public:
    Compiler();
    ~Compiler();

    bool processCommand(const string& command);
    void displayStatus() const;
    void reset();
};