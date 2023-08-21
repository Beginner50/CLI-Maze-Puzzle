#include "board.h"

void Board::populateTiles(std::string_view map)
{
    for (std::size_t i{}; i < map.size(); ++i)
        m_tiles[i] = map[i];
}

std::ostream& operator<<(std::ostream& stream, const Board& board)
{
    system("clear");
    for (std::size_t row{}; row < board.boardHeight; ++row)
    {
        for (std::size_t col{}; col < board.boardWidth; ++col)
        {
            stream << board.m_tiles[static_cast<std::size_t>(row * board.boardWidth + col)];
        }
        stream << '\n';
    }
    return stream;
}

Tile& Board::getTile(Pos pos) { return m_tiles[pos.toIndex1D(boardWidth)]; }

Pos Board::getTilePos(Tile::Type SearchCon)
{
    for (std::size_t row{}; row < boardHeight; ++row)
    {
        for (std::size_t col{}; col < boardWidth; ++col)
        {
            if (m_tiles[row * boardWidth + col].getType() == SearchCon)
                return { static_cast<int>(row), static_cast<int>(col) };
        }
    }

    return { -1, -1 };
}

bool Board::swapTiles(Pos playerPos, Pos adjacentPos)
{
    std::swap(getTile(playerPos), getTile(adjacentPos));
    return true;
}

bool Board::replaceTile(Pos pos, const Tile& tile) {
    m_tiles[pos.toIndex1D(boardWidth)] = tile;
    return true;
}