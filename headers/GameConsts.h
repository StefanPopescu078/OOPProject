//
// Created by Popescu Stefan on Apr 3, 2023.
//

#ifndef OOP_GAMECONSTS_H
#define OOP_GAMECONSTS_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

namespace GameConsts{
    const int boardSideSize = 14;
    const int windowWidth = 14 * 64;
    const int windowHeight = 14 * 64;
    const int cellEdge = 64;
    const int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}; /// vectorii de deplasare
    const int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
}

enum sideType{ // trebuie folosite conversiile implicite
    Red = (1 << 0),
    Blue = (1 << 1),
    NONE = 0
};

enum class pieceMask{
    Flag = (1 << 0),
    Bomb = (1 << 1),
    Spy = (1 << 2),
    Scout = (1 << 3),
    Miner = (1 << 4),
    Sergeant = (1 << 5),
    Lieutenant = (1 << 6),
    Captain = (1 << 7),
    Major = (1 << 8),
    Colonel = (1 << 9),
    General = (1 << 10),
    Marshal = (1 << 30),
    Empty = 0
};

enum class TurnTypes{
    redStart,
    blueStart,
    red,
    blue
};

enum Terrain : int { // tipuri de teren
    MOUNTAIN = 0,
    LAKE = (1 << 1),
    FOREST = (1 << 2),
    HILL = (1 << 3),
    PLAINS = (1 << 4),
    CRATER = (1 << 5)
};


#endif