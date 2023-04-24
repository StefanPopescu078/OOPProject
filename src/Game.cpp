//
// Created by Popescu Stefan on Apr 2, 2023.
//

#include "../headers/Game.h"

#include <chrono>
#include <iostream>
#include <thread>

Game::Game() : table() {
    currentTurnType = TurnTypes::redStart;
}

void Game::runGame() {

    table.loadTexturePack();

    gameWindow.create(sf::VideoMode({GameConsts::windowWidth, GameConsts::windowHeight}), "Stratego", sf::Style::Titlebar | sf::Style::Close);

    gameWindow.setVerticalSyncEnabled(true);
    gameWindow.setFramerateLimit(60);

    while(gameWindow.isOpen()) {
        sf::Event e;
        while(gameWindow.pollEvent(e)) {
            switch(e.type) {
            case sf::Event::Closed:
                gameWindow.close();
                break;
            case sf::Event::KeyPressed:
                switch (e.key.code) {
                    case sf::Keyboard::Space:
                        endTurn();
                        continue;
                    case sf::Keyboard::U:
                        if(!pastStates.empty()) {
                            table = pastStates.top().first;
                            currentTurnType = pastStates.top().second;
                            pastStates.pop();
                            continue;
                        }
                }
                break;
            default:
                break;
            }
        }
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(100ms);

        gameWindow.clear(sf::Color::Black);


        table.render(gameWindow, (currentTurnType == TurnTypes::redStart || currentTurnType == TurnTypes::red ? sideType::Red : sideType::Blue) );

        gameWindow.display();
    }
}

std::ostream &operator<<(std::ostream &out, const Game &game) {
    out << "table: " << game.table << "\n";
    return out;
}

void Game::endTurn() {
    pastStates.emplace(table, currentTurnType);
    switch (currentTurnType) {
        case TurnTypes::redStart:
            currentTurnType = TurnTypes::blueStart;
            break;
        case TurnTypes::blueStart:
            currentTurnType = TurnTypes::red;
            break;
        case TurnTypes::red:
            currentTurnType = TurnTypes::blue;
            break;
        case TurnTypes::blue:
            currentTurnType = TurnTypes::red;
            break;
    }
}

Game::~Game() = default;


