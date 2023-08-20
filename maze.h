#pragma once
#include <array>
#include "spatialClasses.h"
#include "tile.h"

constexpr int boardHeight{ 10 };
constexpr int boardWidth{ 20 };

class Maze
{
public:
    Maze(std::string_view map) { populateTiles(map); }

    friend std::ostream& operator<<(std::ostream& stream, const Maze& maze);

    void populateTiles(std::string_view map);

    Pos getPlayerPos();
    Tile& getTile(Pos pos);

    bool swapTiles(Pos playerPos, Pos adjacentPos);
    bool replaceTile(Pos pos, Tile tile);

    bool movePlayer(Direction dir);
    bool checkWin();

private:
    std::array<Tile, boardHeight* boardWidth> m_tiles{};
};