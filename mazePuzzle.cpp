#include "maze.h"
#include "userInput.cpp"

int main()
{
    constexpr std::string_view map{ "@@@@@@@@@@@@@@@@@@@@"
                                    "@                  @"
                                    "@                  @"
                                    "@                  @"
                                    "@                  @"
                                    "@        @ @       @"
                                    "@     @@@@         @"
                                    "@     @P   @       @"
                                    "@     @ @@@@       @"
                                    "@@@@@@@!@@@@@@@@@@@@"
    };

    Maze maze{ map };

    while (true)
    {
        std::cout << maze << "\n\n";
        char ch{ getChar() };

        if (ch == 'q')
            break;

        maze.movePlayer(charToDirection(ch));

        if (maze.checkWin() == true)
            break;
    }

    std::cout << maze;
    std::cout << "\n\nMaze Puzzle By Prashant Jatoo.\n\n";

    return 0;
}