#pragma once
#include <cassert>

enum Direction
{
    left,
    right,
    up,
    down,
    max_dir
};

struct Pos
{
    int x{};
    int y{};

    std::size_t toIndex(int boardWidth)
    {
        return static_cast<std::size_t>(x * boardWidth + y);
    }

    friend bool operator==(Pos p1, Pos p2) { return p1.x == p2.x && p1.y == p2.y; }
    friend bool operator!=(Pos p1, Pos p2) { return !(p1 == p2); }
    Pos getAdjacentPos(Direction dir)
    {
        switch (dir)
        {
        case Direction::left: return { x, y - 1 };
        case Direction::right: return { x, y + 1 };
        case Direction::up: return { x - 1, y };
        case Direction::down: return { x + 1,y };
        default: break;
        }

        assert(0 && "Invalid Direction!");
        return *this;
    }
};