//
// Created by Popescu Stefan on Apr 2, 2023.
//

#ifndef OOP_BOARD_H
#define OOP_BOARD_H

class Piece;

#include <array>
#include <map>
#include <memory>
#include <cassert>
#include "GameConsts.h"


class Board {
private:
    std::array<std::array<std::shared_ptr<Piece>, GameConsts::boardSideSize>, GameConsts::boardSideSize> pieces; // matricea pozitiilor
    std::array<std::array<Terrain, GameConsts::boardSideSize>, GameConsts::boardSideSize> cellTypes; // matricea tipurilor de teren
    sf::Texture background, redQ, blueQ;

public:
    Board();
    Board(const Board & b1);
    ~Board();
    Board & operator= (const Board& b2);
    Terrain getTerrain(int x, int y) const;
    std::shared_ptr<Piece> getPiece(int x, int y) const;
    void render(sf::RenderWindow & window, sideType currPlayer);
    friend std::ostream &operator<<(std::ostream &out, const Board &board);
    void loadTexturePack(const std::string & filePref = "0");
};


#endif //OOP_BOARD_H
