#include "maze.h"

Tile& Maze::operator[](const Pos pos)
{
    return m_tiles[pos.m_x][pos.m_y];
}

Tile Maze::operator[](const Pos pos) const
{
    return m_tiles[pos.m_x][pos.m_y];
}

std::ostream& operator<<(std::ostream& stream, const Tile tile)
{
    switch (tile.m_type)
    {
    case Tile::empty: return stream << ' ';
    case Tile::wall: return stream << '@';
    case Tile::player: return stream << 'P';
    case Tile::finish: return stream << '!';
    default: break;
    }

    assert(0 && "Invalid Tile");
    return stream;
}

std::ostream& operator<<(std::ostream& stream, const Maze& maze)
{
    for (int row{}; row < boardLength; ++row)
    {
        for (int col{}; col < boardLength; ++col)
        {
            stream << maze[Pos{ row, col }];
        }
        stream << '\n';
    }
    return stream;
}