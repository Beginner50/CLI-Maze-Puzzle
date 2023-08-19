#include "maze.h"

void Maze::populateTiles(std::string_view map)
{
    for (std::size_t i{}; i < map.size(); ++i)
        m_tiles[i] = map[i];
}

std::ostream& operator<<(std::ostream& stream, const Maze& maze)
{
    system("clear");
    for (int row{}; row < boardHeight; ++row)
    {
        for (int col{}; col < boardWidth; ++col)
        {
            stream << maze.m_tiles[static_cast<std::size_t>(row * boardWidth + col)];
        }
        stream << '\n';
    }
    return stream;
}

Tile Maze::getTile(Pos pos) { return m_tiles[pos.toIndex(boardWidth)]; }

Pos Maze::getPlayerPos()
{
    for (int row{}; row < boardHeight; ++row)
    {
        for (int col{}; col < boardWidth; ++col)
        {
            if (m_tiles[static_cast<std::size_t>(row * boardWidth + col)].isPlayerTile())
                return { row, col };
        }
    }

    assert(0 && "Player Tile not found!");
    return { -1, -1 };
}


bool Maze::swapTiles(Pos playerPos, Pos adjacentPos)
{
    Tile temp{ getTile(adjacentPos) };
    m_tiles[adjacentPos.toIndex(boardWidth)] = getTile(playerPos);
    m_tiles[playerPos.toIndex(boardWidth)] = temp;
    return true;
}

bool Maze::movePlayer(Direction dir)
{
    Pos playerPos{ getPlayerPos() };
    Pos adjacentPos{ playerPos.getAdjacentPos(dir) };

    if (playerPos != adjacentPos && getTile(adjacentPos).isTraversable())
        return swapTiles(playerPos, adjacentPos);
    return false;
}
