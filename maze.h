#pragma once
#include "board.h"

class Maze
{
public:
    Maze(std::size_t boardWidth, std::size_t boardHeight, std::string_view map)
        :m_board{ boardWidth, boardHeight }
    {
        m_board.populateTiles(map);
    }

    friend std::ostream& operator<<(std::ostream& stream, const Maze& maze) { return stream << maze.m_board; }

    Pos getPlayerPos();
    bool movePlayer(Direction dir);
    bool checkWin();

private:
    Board m_board;
};