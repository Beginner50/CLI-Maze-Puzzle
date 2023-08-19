#include <iostream>
#include <limits>

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