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
    static std::vector<std::pair<int, int> > toBeHighlighted;
    static std::pair<int, int> isDragged;
    sf::Texture background, redQ, blueQ, accs;
    std::shared_ptr<Piece> ptrEmpty; // tinut pentru a suprascrie in caz de bomba
    // inlocuit cu un getter intr-un object pool ulterior
    // booleana imi spune daca am explozie
public:
    Board();
    Board(const Board & b1);
    ~Board();
    Board & operator= (const Board& b2);
    Board & operator= (Board&& b2);
    static void setAcc(std::vector<std::pair<int, int> >);
    static void setDrag(std::pair<int, int>);
    static void resetDrag();
    Terrain getTerrain(int x, int y) const;
    std::shared_ptr<Piece> getPiece(int x, int y) const;
    void explode(int x, int y);
    void render(sf::RenderWindow & window, sideType currPlayer);
    friend std::ostream &operator<<(std::ostream &out, const Board &board);
    void loadTexturePack(const std::string & filePref = "0");
    void getOutcomeAttack(const std::pair<int, int>&, const std::pair<int, int>&); // modifica starea board-ului
    bool getOutcomeSwap(const std::pair<int, int>&, const std::pair<int, int>&);
};


#endif //OOP_BOARD_H
