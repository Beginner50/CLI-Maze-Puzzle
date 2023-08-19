#include "maze.h"
#include "userInput.cpp"

int main()
{
    Maze maze{};
    std::cout << maze << '\n';
    getChar();

    return 0;
}