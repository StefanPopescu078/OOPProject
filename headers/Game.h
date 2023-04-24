//
// Created by Popescu Stefan on Apr 2, 2023.
//

#ifndef OOP_GAME_H
#define OOP_GAME_H


#include "GameConsts.h"
#include <ostream>
#include "Board.h"
#include <memory>
#include <array>
#include <stack>



class Game {
private:
    Board table;
    sf::RenderWindow gameWindow;
    TurnTypes currentTurnType;
    std::stack<std::pair<Board, TurnTypes> > pastStates;
public:
    Game();

    ~Game();
    void endTurn();
    void runGame();

    friend std::ostream &operator<<(std::ostream &os, const Game &game);
};


#endif //OOP_GAME_H
