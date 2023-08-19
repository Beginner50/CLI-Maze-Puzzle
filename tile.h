#pragma once
#include <iostream>
#include "spatialClasses.h"

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

    Tile(char tileType = ' ')
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

    bool isPlayerTile() { return m_type == player; }
    bool isTraversable();
    Type getType() { return m_type; }

private:
    Type m_type{};
};

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

bool Tile::isTraversable()
{
    switch (m_type)
    {
    case empty:
    case finish: return true;
    default: return false;
    }
}