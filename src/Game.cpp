//
// Created by Popescu Stefan on Apr 2, 2023.
//

#include "../headers/Game.h"
#include "../headers/Piece.h"

#include <chrono>
#include <iostream>
#include <thread>

Game::Game() : table() {
    currentTurnType = TurnTypes::redStart;
}

void Game::runGame() {

//    alert("test");

    try {
        table.loadTexturePack();
    }
    catch (const load_error & e) {
        alert(e.what());
        throw;
    }

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
                if(e.key.code == sf::Keyboard::Space){
                    endTurn();
                    continue;
                }
                else if(e.key.code == sf::Keyboard::U){
                    if(!pastStates.empty()) {
                        table = pastStates.top().first;
                        currentTurnType = pastStates.top().second;
                        pastStates.pop();
                        continue;
                    }
                }
                break;
            case sf::Event::MouseButtonPressed:
                if(e.mouseButton.button == sf::Mouse::Left)
                    if((e.mouseButton.x >= 0 && e.mouseButton.x < GameConsts::windowHeight) && (e.mouseButton.y >= 0 && e.mouseButton.y < GameConsts::windowWidth) ){
                        int pX = e.mouseButton.x / GameConsts::cellEdge, pY = e.mouseButton.y / GameConsts::cellEdge;
                        Board::setDrag(std::make_pair(pX, pY));
                        dragPiece(pX, pY);
                        Board::resetDrag();
                    }

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
    delete this;
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

Game& Game::getGame() {
    if(ptrSelf == nullptr)
        ptrSelf = new Game;
    return *ptrSelf;
}

Game::~Game() = default;

Game* Game::ptrSelf = nullptr;

void Game::alert(const std::string & msg) {
    sf::RenderWindow window(sf::VideoMode(200, 50), "alert", sf::Style::Titlebar | sf::Style::Close);

    sf::Font font;
    if (!font.loadFromFile("assets/arial.ttf")){
        throw load_error("arial.ttf");
    }

    sf::Text messageText(msg, font, 20);
    messageText.setFillColor(sf::Color::Red);
    messageText.setPosition(8.f, 8.f);

    while (window.isOpen()){
        sf::Event event{};
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        window.draw(messageText);
        window.display();
    }
}

void Game::dragPiece(int pX, int pY) {
    auto accesiblePos = this -> table.getPiece(pX, pY) -> accessible(pX, pY, table);

}

