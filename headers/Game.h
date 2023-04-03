//
// Created by Popescu Stefan on Apr 2, 2023.
//

#ifndef OOP_GAME_H
#define OOP_GAME_H

#include <ostream>
#include <assert.h>
#include <array>
#include <SFML/Graphics.hpp>

namespace GameConsts{
    const int boardSideSize = 14;
}

enum class TurnTypes{
    redStart,
    blueStart,
    red,
    blue
};

class Game {
private:
    sf::RenderWindow gameWindow;
    TurnTypes currentTurnType;
    void renderGame();
public:
    Game();
    void runGame();

};


#endif //OOP_GAME_H
