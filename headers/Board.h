//
// Created by Popescu Stefan on Apr 2, 2023.
//

#ifndef OOP_BOARD_H
#define OOP_BOARD_H


namespace GameConsts{};
class Piece;

#include <array>
#include "Game.h"

enum class Terrain { // tipuri de teren
    MOUNTAIN,
    LAKE,
    FOREST,
    HILL,
    PLAINS,
    CRATER
};

class Board {
private:
    std::array<std::array<Piece *, GameConsts::boardSideSize>, GameConsts::boardSideSize> pieces; // matricea pozitiilor
    std::array<std::array<Terrain, GameConsts::boardSideSize>, GameConsts::boardSideSize> cellTypes; // matricea tipurilor de teren
public:
    Board();

    virtual ~Board();
    Terrain getTerrain(const int & x, const int & y) const {
        assert(x >= 0 && y >= 0 && x < GameConsts::boardSideSize && y < GameConsts::boardSideSize); // debugging
        return cellTypes[x][y];
    }
    const Piece * getPiece(const int & x, const int & y) const {
        assert(x >= 0 && y >= 0 && x < GameConsts::boardSideSize && y < GameConsts::boardSideSize); // debugging
        return pieces[x][y];
    }
    friend std::ostream &operator<<(std::ostream &os, const Board &board);
};


#endif //OOP_BOARD_H
