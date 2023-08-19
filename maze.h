#pragma once
#include <iostream>
#include <cassert>

constexpr int boardLength{ 10 };

struct Pos
{
    int m_x{};
    int m_y{};
};

class Tile
{
public:
    enum Type
    {
        empty,
        wall,
        player,
        finish,
        max_types
    };

    Tile(char tileType)
    {
        switch (tileType)
        {
        case '@': m_type = wall; break;
        case ' ': m_type = empty; break;
        case 'P': m_type = player; break;
        case '!':  m_type = finish; break;
        default: break;
        }
        assert((tileType == '@' || ' ' || 'P' || '!') && "Invalid Maze Entity");
    }

    friend std::ostream& operator<<(std::ostream& stream, const Tile tile);
    bool isEmptyTile() { return m_type == empty; }

private:
    Type m_type{};
};

class Maze
{
public:
    Maze() = default;

    friend std::ostream& operator<<(std::ostream& stream, const Maze& maze);
    Tile getTile(Pos pos);
    Pos getPlayerTile();
    Tile& operator[] (const Pos pos);
    Tile operator[](const Pos pos) const;

private:
    Tile m_tiles[boardLength][boardLength]{
        {'@', '@', '@', '@', '@', '@', '@', '@', '@', '@'},
        {'@', ' ', ' ', ' ', ' ', ' ', 'P', ' ', ' ', '@'},
        {'@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@'},
        {'@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@'},
        {'@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@'},
        {'@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@'},
        {'@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@'},
        {'@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@'},
        {'@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@'},
        {'@', '@', '!', '@', '@', '@', '@', '@', '@', '@'}
    };
};