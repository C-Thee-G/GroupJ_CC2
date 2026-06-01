#include "Compiler.h"
#include "ConsoleColors.h"
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

Compiler::Compiler()
{
}

Compiler::~Compiler()
{
}

bool Compiler::processCommand(const string& command)
{
    setColor(14);
    cout << "\n[COMPILER] Processing: \"" << command << "\"" << endl;
    setColor(7);

    // Trim whitespace
    string trimmed = command;
    size_t start = trimmed.find_first_not_of(" \t");
    size_t end = trimmed.find_last_not_of(" \t");
    if (start == string::npos) {
        setColor(12);
        cerr << "[SYNTAX ERROR] Empty command" << endl;
        setColor(7);
        return false;
    }
    trimmed = trimmed.substr(start, end - start + 1);

    // Parse the command
    stringstream ss(trimmed);
    string cmdWord;
    string cropName;

    ss >> cmdWord;

    // Convert to uppercase for comparison
    string cmdUpper = cmdWord;
    for (size_t i = 0; i < cmdUpper.length(); i++) {
        cmdUpper[i] = toupper(cmdUpper[i]);
    }

    // Lexical analysis - just output the words
    cout << "[LEXICAL] Tokens: " << cmdWord;

    if (ss >> cropName) {
        cout << " " << cropName;

        // Check for extra tokens
        string extra;
        if (ss >> extra) {
            setColor(12);
            cerr << "\n[LEXICAL ERROR] Too many tokens!" << endl;
            setColor(7);
            return false;
        }
    }
    cout << endl;

    // Syntax analysis
    bool validCommand = false;
    CommandType cmdType = CMD_UNKNOWN;

    if (cmdUpper == "ADD_CROP") {
        validCommand = true;
        cmdType = CMD_ADD_CROP;
    }
    else if (cmdUpper == "HARVEST") {
        validCommand = true;
        cmdType = CMD_HARVEST;
    }
    else if (cmdUpper == "SELL") {
        validCommand = true;
        cmdType = CMD_SELL;
    }
    else {
        validCommand = false;
    }

    if (!validCommand) {
        setColor(12);
        cerr << "[SYNTAX ERROR] Unknown command: " << cmdWord << endl;
        cerr << "Valid commands: ADD_CROP, HARVEST, SELL" << endl;
        setColor(7);
        return false;
    }

    if (cropName.empty()) {
        setColor(12);
        cerr << "[SYNTAX ERROR] Missing crop name" << endl;
        setColor(7);
        return false;
    }

    cout << "[SYNTAX] Command structure valid" << endl;

    // Semantic analysis
    if (cmdType == CMD_ADD_CROP) {
        if (plantedCrops.find(cropName) != plantedCrops.end()) {
            setColor(12);
            cerr << "[SEMANTIC ERROR] Crop '" << cropName << "' is already planted!" << endl;
            setColor(7);
            return false;
        }
        plantedCrops.insert(cropName);
        setColor(10);
        cout << "[SEMANTIC] Crop '" << cropName << "' has been planted" << endl;
        setColor(7);
        return true;
    }
    else if (cmdType == CMD_HARVEST) {
        if (plantedCrops.find(cropName) == plantedCrops.end()) {
            setColor(12);
            cerr << "[SEMANTIC ERROR] Crop '" << cropName << "' hasn't been planted yet!" << endl;
            setColor(7);
            return false;
        }
        if (harvestedCrops.find(cropName) != harvestedCrops.end()) {
            setColor(12);
            cerr << "[SEMANTIC ERROR] Crop '" << cropName << "' was already harvested!" << endl;
            setColor(7);
            return false;
        }
        harvestedCrops.insert(cropName);
        setColor(10);
        cout << "[SEMANTIC] Crop '" << cropName << "' has been harvested" << endl;
        setColor(7);
        return true;
    }
    else if (cmdType == CMD_SELL) {
        if (harvestedCrops.find(cropName) == harvestedCrops.end()) {
            setColor(12);
            cerr << "[SEMANTIC ERROR] Crop '" << cropName << "' hasn't been harvested yet!" << endl;
            setColor(7);
            return false;
        }
        setColor(10);
        cout << "[SEMANTIC] Crop '" << cropName << "' has been sold" << endl;
        setColor(7);
        return true;
    }

    return false;
}

void Compiler::displayStatus() const
{
    setColor(11);
    cout << "___________________________________" << endl;
    cout << "Compiler Status:" << endl;
    cout << "___________________________________" << endl;
    setColor(7);

    cout << "  Planted crops: ";
    if (plantedCrops.empty()) {
        cout << "(none)";
    }
    else {
        for (set<string>::iterator it = plantedCrops.begin(); it != plantedCrops.end(); ++it) {
            cout << *it << " ";
        }
    }
    cout << endl;

    cout << "  Harvested crops: ";
    if (harvestedCrops.empty()) {
        cout << "(none)";
    }
    else {
        for (set<string>::iterator it = harvestedCrops.begin(); it != harvestedCrops.end(); ++it) {
            cout << *it << " ";
        }
    }
    cout << endl;

    setColor(11);
    cout << "___________________________________" << endl;
    setColor(7);
}

void Compiler::reset()
{
    plantedCrops.clear();
    harvestedCrops.clear();
}