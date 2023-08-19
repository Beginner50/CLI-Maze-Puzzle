#include "maze.h"
#include "userInput.cpp"

int main()
{
    constexpr std::string_view map{ "@@@@@@@@@@@@@@@@@@@@"
                                    "@                  @"
                                    "@                P @"
                                    "@                  @"
                                    "@                  @"
                                    "@                  @"
                                    "@                  @"
                                    "@                  @"
                                    "@                  @"
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
    }

    return 0;
}