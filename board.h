#pragma once
#include <vector>
#include "spatialClasses.h"
#include "tile.h"

class Board
{
public:
    std::size_t boardWidth{ 0 };
    std::size_t boardHeight{ 0 };

    Board(std::size_t width, std::size_t height)
        : boardWidth{ width }, boardHeight{ height }
    {
        m_tiles.resize(boardHeight * boardWidth);
    }

    friend std::ostream& operator<<(std::ostream& stream, const Board& board);

    void populateTiles(std::string_view map);

    Tile& getTile(Pos pos);
    Pos getTilePos(Tile::Type SearchCon);

    bool swapTiles(Pos playerPos, Pos adjacentPos);
    bool replaceTile(Pos pos, const Tile& tile);


private:
    std::vector<Tile> m_tiles{};
};