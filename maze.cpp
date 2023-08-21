#include "maze.h"

Pos Maze::getPlayerPos()
{
    Pos PlayerPos{ m_board.getTilePos(Tile::player) };
    if (PlayerPos == Pos{ -1, -1 })
        assert(0 && "Position of Player not found!");
    return PlayerPos;
}

bool Maze::movePlayer(Direction dir)
{
    Pos playerPos{ getPlayerPos() };
    Pos adjacentPos{ playerPos.getAdjacentPos(dir) };

    if (playerPos == adjacentPos)
        return false;

    Tile adjacentTile{ m_board.getTile(adjacentPos) };
    if (adjacentTile.getType() == Tile::empty)
        return m_board.swapTiles(playerPos, adjacentPos);
    else if (adjacentTile.getType() == Tile::finish)
    {
        m_board.replaceTile(adjacentPos, Tile::empty);
        return m_board.swapTiles(playerPos, adjacentPos);
    }

    return false;
}

bool Maze::checkWin() { return (m_board.getTilePos(Tile::finish) != Pos{ -1, -1 }) ? false : true; }
