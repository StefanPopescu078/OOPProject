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
                if(e.mouseButton.button == sf::Mouse::Left){
                    if((e.mouseButton.x >= 0 && e.mouseButton.x < GameConsts::windowHeight) && (e.mouseButton.y >= 0 && e.mouseButton.y < GameConsts::windowWidth) ){
                        int pY = e.mouseButton.x / GameConsts::cellEdge, pX = e.mouseButton.y / GameConsts::cellEdge;
                        std::cerr << e.mouseButton.x << " " << e.mouseButton.y << "\n";
                        Board::setDrag(std::make_pair(pX, pY));
                        dragPiece(pX, pY);
                        Board::resetDrag();
                    }
                }


            default:
                break;
            }
        }
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(50ms);

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

/// true daca dragging-ul a avut succes
bool Game::dragPiece(int pX, int pY) {
    std::cerr << pX << " " << pY << "\n";
    auto accessiblePos = this -> table.getPiece(pX, pY) -> accessible(pX, pY, table);
    Board::setAcc(accessiblePos);
    int lastX = -1, lastY = -1;
    while(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
//        std::cerr << "HELEKAROPEI\n";
        sf::Vector2i cursor = sf::Mouse::getPosition(gameWindow); // pixel-ul la care e pozitionat mouse-ul



        cursor.x = std::min(std::max(cursor.x, 0), GameConsts::windowHeight - 1) ;
        cursor.y = std::min(std::max(cursor.y, 0), GameConsts::windowWidth - 1);

        lastY = cursor.x / GameConsts::cellEdge;
        lastX = cursor.y / GameConsts::cellEdge;

        table.render(gameWindow, (currentTurnType == TurnTypes::redStart || currentTurnType == TurnTypes::red ? sideType::Red : sideType::Blue));
        table.getPiece(pX, pY) -> drawItself(gameWindow, cursor.x - GameConsts::cellEdge / 2, cursor.y - GameConsts::cellEdge / 2);
        gameWindow.display();
    }
    Board::setAcc(std::vector<std::pair<int, int>>());
    // la momentul actual e garantat ca pointer-ul mouse-ului arata spre o pozitie valida
    if(std::find(accessiblePos.begin(), accessiblePos.end(), std::make_pair(lastX, lastY)) != accessiblePos.end()){

        return true;
    }
    else{
        return false;
    }
}

