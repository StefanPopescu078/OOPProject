//
// Created by Popescu Stefan on Apr 2, 2023.
//

#ifndef OOP_GAME_H
#define OOP_GAME_H

class Board;

#include <ostream>
#include "Board.h"
#include <memory>
#include <array>
#include <SFML/Graphics.hpp>
#include "GameConsts.h"

enum class TurnTypes{
    redStart,
    blueStart,
    red,
    blue
};

class Game {
private:
    std::unique_ptr<Board> table;
    sf::RenderWindow gameWindow;
    TurnTypes currentTurnType;
    void renderGame();
public:
    Game();

    virtual ~Game();

    void runGame();

    friend std::ostream &operator<<(std::ostream &os, const Game &game);
};


#endif //OOP_GAME_H
