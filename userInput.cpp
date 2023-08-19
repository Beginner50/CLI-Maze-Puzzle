#include <iostream>
#include <limits>
#include "spatialClasses.h"

inline bool validChar(char ch)
{
    switch (ch)
    {
    case 'w':
    case 'a':
    case 's':
    case 'd':
    case 'q': std::cout << "Valid Input: " << ch << '\n'; return true;
    default: return false;
    }
}

inline void ignoreInput() { std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); }

inline char getChar()
{
    char ch{};
    while (!validChar(ch))
    {
        std::cout << '>';
        std::cin >> ch;
        ignoreInput();
    }

    return ch;
}

inline Direction charToDirection(char ch)
{
    switch (ch)
    {
    case 'a': return left;
    case 'd': return right;
    case 'w': return up;
    case 's': return down;
    default: break;
    }

    assert(0 && "Char cannot map to know directions. Char is not valid");
    return left;
}