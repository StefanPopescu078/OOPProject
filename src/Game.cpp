//
// Created by Popescu Stefan on Apr 2, 2023.
//

#include "../headers/Game.h"

#include <chrono>
#include <iostream>
#include <thread>


Game::Game() {
    table = std::unique_ptr<Board>(new Board);
    currentTurnType = TurnTypes::redStart;
}

void Game::runGame() {
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
            case sf::Event::Resized:

                break;
            case sf::Event::KeyPressed:
                std::cout << "Received key " << (e.key.code == sf::Keyboard::X ? "X" : "(other)") << "\n";
                break;
            default:
                break;
            }
        }
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(10ms);

        gameWindow.clear();


        gameWindow.display();
    }
}

void Game::renderGame() {

}

std::ostream &operator<<(std::ostream &out, const Game &game) {
    out << "table: " << game.table << "\n";
    return out;
}

Game::~Game() {

}


