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
#include "CustomExceptions.h"


class Game {
private:
    Board table;
    sf::RenderWindow gameWindow;
    TurnTypes currentTurnType;
    std::stack<std::pair<Board, TurnTypes> > pastStates;
    static Game* ptrSelf;
    Game();
public:
    void alert(const std::string&);
    static Game& getGame();
    Game(const Game&) = delete;
    ~Game();
    void endTurn();
    void dragPiece(int, int);
    // at the end of run, the game object is invalidated
    void runGame(); // la sfarsitul lui run, obiectul de joc este invalidat

    friend std::ostream &operator<<(std::ostream &os, const Game &game);
};


#endif //OOP_GAME_H
