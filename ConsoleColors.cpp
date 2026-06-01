#include "ConsoleColors.h"

#ifdef _WIN32
void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
#else
void setColor(int color) {
    // Non-Windows: do nothing
}
#endif