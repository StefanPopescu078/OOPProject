//
// Created by Popescu Stefan on Apr 2, 2023.
//

#include <iostream>
#include "../headers/Board.h"
#include "../headers/Piece.h"


Board::Board() {
    for (int i = 0; i < GameConsts::boardSideSize; i++)
        for(int j = 0; j < GameConsts::boardSideSize; j++)
            cellTypes[i][j] = Terrain::PLAINS;


    cellTypes[0][0] = Terrain::MOUNTAIN;
    cellTypes[0][GameConsts::boardSideSize - 1] = Terrain::MOUNTAIN;
    cellTypes[GameConsts::boardSideSize - 1][0] = Terrain::MOUNTAIN;
    cellTypes[GameConsts::boardSideSize - 1][GameConsts::boardSideSize - 1] = Terrain::MOUNTAIN;


    cellTypes[3][3] = Terrain::FOREST;
    cellTypes[4][3] = Terrain::FOREST;
    cellTypes[2][GameConsts::boardSideSize - 1 - 4] = Terrain::LAKE;
    cellTypes[3][GameConsts::boardSideSize - 1 - 5] = Terrain::LAKE;
    cellTypes[3][GameConsts::boardSideSize - 1 - 6] = Terrain::LAKE;
    cellTypes[5][GameConsts::boardSideSize - 1 - 2] = Terrain::HILL;

    // terenul este simetric fata de mijlocul tablei

    cellTypes[GameConsts::boardSideSize - 1 - 3][GameConsts::boardSideSize - 1 - 3] = Terrain::FOREST;
    cellTypes[GameConsts::boardSideSize - 1 - 4][GameConsts::boardSideSize - 1 - 3] = Terrain::FOREST;
    cellTypes[GameConsts::boardSideSize - 1 - 2][4] = Terrain::LAKE;
    cellTypes[GameConsts::boardSideSize - 1 - 3][5] = Terrain::LAKE;
    cellTypes[GameConsts::boardSideSize - 1 - 3][6] = Terrain::LAKE;
    cellTypes[GameConsts::boardSideSize - 1 - 5][2] = Terrain::HILL;


    // temporara pentru testare
    pieces[0][0] = std::make_shared<Empty>(sideType::NONE);
    for(int i = 0; i < GameConsts::boardSideSize; i++)
        for(int j = 0; j < GameConsts::boardSideSize; j++)
            if(i != 0 || j != 0)
                pieces[i][j] = pieces[0][0];

    pieces[0][1] = std::make_shared<Flag>(sideType::Red);

    pieces[0][2] = pieces[0][3] = pieces[0][4] =
            pieces[0][5] = pieces[0][6] = pieces[0][7] = std::make_shared<Bomb>(sideType::Red);

    pieces[0][8] = std::make_shared<Spy>(sideType::Red);

    pieces[0][9] = pieces[0][10] = pieces[0][11] = pieces[0][12] =
        pieces[1][9] = pieces[1][10] = pieces[1][11] = pieces[1][12] = std::make_shared<Scout>(sideType::Red);

    pieces[1][13] = pieces[2][13] = pieces[3][13] = pieces[2][12] = pieces[2][11] = std::make_shared<Miner>(sideType::Red);

    pieces[1][0] = pieces[1][1] = pieces[1][2] = pieces[1][3] = std::make_shared<Sergeant>(sideType::Red);

    pieces[1][4] = pieces[1][5] = pieces[1][6] = pieces[1][7] = std::make_shared<Lieutenant>(sideType::Red);

    pieces[1][8] = pieces[2][8] = pieces[2][7] = pieces[2][9] = std::make_shared<Captain>(sideType::Red);

    pieces[2][6] = pieces[2][5] = pieces[2][4] = std::make_shared<Major>(sideType::Red);
    pieces[2][3] = pieces[2][2] = std::make_shared<Colonel>(sideType::Red);
    pieces[2][1] = std::make_shared<General>(sideType::Red);
    pieces[2][0] = std::make_shared<Marshal>(sideType::Red);



    pieces[13 - 0][13 - 1] = std::make_shared<Flag>(sideType::Blue);

    pieces[13 - 0][13 - 2] = pieces[13 - 0][13 - 3] = pieces[13 - 0][13 - 4] =
    pieces[13 - 0][13 - 5] = pieces[13 - 0][13 - 6] = pieces[13 - 0][13 - 7] = std::make_shared<Bomb>(sideType::Blue);

    pieces[13 - 0][13 - 8] = std::make_shared<Spy>(sideType::Blue);

    pieces[13 - 0][13 - 9] = pieces[13 - 0][13 - 10] = pieces[13 - 0][13 - 11] = pieces[13 - 0][13 - 12] =
    pieces[13 - 1][13 - 9] = pieces[13 - 1][13 - 10] = pieces[13 - 1][13 - 11] = pieces[13 - 1][13 - 12] = std::make_shared<Scout>(sideType::Blue);

    pieces[13 - 1][0] = pieces[13 - 2][0] = pieces[13 - 3][0] = pieces[13 - 2][13 - 12] = pieces[13 - 2][13 - 11] = std::make_shared<Miner>(sideType::Blue);

    pieces[13 - 1][13 - 0] = pieces[13 - 1][13 - 1] = pieces[13 - 1][13 - 2] = pieces[13 - 1][13 - 3] = std::make_shared<Sergeant>(sideType::Blue);

    pieces[13 - 1][13 - 4] = pieces[13 - 1][13 - 5] = pieces[13 - 1][13 - 6] = pieces[13 - 1][13 - 7] = std::make_shared<Lieutenant>(sideType::Blue);

    pieces[13 - 1][13 - 8] = pieces[13 - 2][13 - 8] = pieces[13 - 2][13 - 7] = pieces[13 - 2][13 - 9] = std::make_shared<Captain>(sideType::Blue);

    pieces[13 - 2][13 - 6] = pieces[13 - 2][13 - 5] = pieces[13 - 2][13 - 4] = std::make_shared<Major>(sideType::Blue);
    pieces[13 - 2][13 - 3] = pieces[13 - 2][13 - 2] = std::make_shared<Colonel>(sideType::Blue);
    pieces[13 - 2][13 - 1] = std::make_shared<General>(sideType::Blue);
    pieces[13 - 2][13 - 0] = std::make_shared<Marshal>(sideType::Blue);

    pieces[0][0] ->accessible(0, 0, *this);
    pieces[0][0] ->selfPieceMask();
}

Board::~Board() = default;

std::ostream &operator<<(std::ostream &out, const Board &board) {
    for(int i = 0; i < GameConsts::boardSideSize; i++)
        for (int j = 0; j < GameConsts::boardSideSize; j++) {
            out << "[ " << i << " " << j << " ] : piece - " << (*board.pieces[i][j]) << " ; terrain - " << static_cast<int>(board.getTerrain(i, j)) << "\n";
        }
    return out;
}

Terrain Board::getTerrain(int x, int y) const {
    if(!(x >= 0 && y >= 0 && x < GameConsts::boardSideSize && y < GameConsts::boardSideSize)) // debugging
        throw "Invalid coordinates in Board::getTerrain";
    return cellTypes[x][y];
}

std::shared_ptr<Piece> Board::getPiece(int x, int y) const {
    if(!(x >= 0 && y >= 0 && x < GameConsts::boardSideSize && y < GameConsts::boardSideSize)) // debugging
        throw "Invalid coordinates in Board::getPiece";
    return pieces[x][y];
}

Board::Board(const Board &b1) : cellTypes(b1.cellTypes), background(b1.background), redQ(b1.redQ), blueQ(b1.blueQ) {
    std::map<Piece*, std::shared_ptr<Piece>> usedPointers; // un table tine cate o piesa de fiecare tip, o copie a unui table trebuie sa vina cu colectia ei de tipuri de piese

    for(int i = 0; i < GameConsts::boardSideSize; i++) // fiecare pozitie din tabela e un pointer catre un obiect, (fiecare piesa ar trebui sa fie singleton per tabela?)
        for(int j = 0; j < GameConsts::boardSideSize; j++){ // se va modifica ulterior cu clone
            if(usedPointers.find(b1.pieces[i][j].get()) == usedPointers.end()){
                usedPointers[b1.pieces[i][j].get()] = pieces[i][j] = b1.pieces[i][j] -> clone(); //se apeleaza copy constructor-ul pentru piesa
            }
            else{
                pieces[i][j] = usedPointers[b1.pieces[i][j].get()];
            }
        }
}

Board &Board::operator=(const Board &b1) { // nu ajuta cu nimic in plus daca obiectul exista deja
    cellTypes = b1.cellTypes; // se face copierea propriu-zisa a tipurilor de celule
    std::map<Piece*, std::shared_ptr<Piece>> usedPointers; // un table tine cate o piesa de fiecare tip, o copie a unui table trebuie sa vina cu colectia ei de tipuri de piese
    background = b1.background, redQ = b1.redQ, blueQ = b1.blueQ;

    for(int i = 0; i < GameConsts::boardSideSize; i++) // fiecare pozitie din tabela e un pointer catre un obiect, (fiecare piesa ar trebui sa fie singleton per tabela?)
        for(int j = 0; j < GameConsts::boardSideSize; j++){ // se va modifica ulterior cu clone
            if(usedPointers.find(b1.pieces[i][j].get()) == usedPointers.end()){
                usedPointers[b1.pieces[i][j].get()] = pieces[i][j] = b1.pieces[i][j] -> clone(); //se apeleaza copy constructor-ul pentru piesa
            }
            else{
                pieces[i][j] = usedPointers[b1.pieces[i][j].get()];
            }
        }
    return *this;
}

void Board::render(sf::RenderWindow & window, sideType currPlayer) { // incepe rosu
    sf::Sprite temp;

    temp.setTexture(background);
    temp.setPosition(0, 0);
    temp.setScale(1, 1);
    window.draw(temp);
//    for(int i = 0; i < GameConsts::boardSideSize; i++)
//        for(int j = 0; j < GameConsts::boardSideSize; j++){
//            // afisat terenul
//        }

    std::array<std::array<bool, GameConsts::boardSideSize>, GameConsts::boardSideSize> visibleMatrix{};

    for(auto &x:visibleMatrix)
        std::fill(x.begin(), x.end(), false);

    for(int i = 0; i < GameConsts::boardSideSize; i++)
        for(int j = 0; j < GameConsts::boardSideSize; j++)
            if(pieces[i][j] -> selfSideMask() == currPlayer){
                auto temporary = pieces[i][j]->canSee(i, j, *this);
                for(auto &x:temporary)
                    visibleMatrix[x.first][x.second] = true;
            }

    if(currPlayer == sideType::Red){
        for(int i = 0; i < GameConsts::boardSideSize; i++)
            for(int j = 0; j < GameConsts::boardSideSize; j++)
                if(visibleMatrix[i][j] || pieces[i][j] -> selfSideMask() == sideType::NONE){
                    pieces[i][j] -> drawItself(window, j * GameConsts::cellEdge, i * GameConsts::cellEdge);
                }
                else{
                    // se va adauga o noua clasa de piesa mai tarziu
                    sf::Sprite temporary(blueQ);
                    temporary.setPosition(j * GameConsts::cellEdge, i * GameConsts::cellEdge);
                    window.draw(temporary);
                }
    }
    else{
        for(int i = 0; i < GameConsts::boardSideSize; i++)
            for(int j = 0; j < GameConsts::boardSideSize; j++)
                if(visibleMatrix[i][j] || pieces[i][j] -> selfSideMask() == sideType::NONE){
                    pieces[i][j] -> drawItself(window, (GameConsts::boardSideSize - 1 - j) * GameConsts::cellEdge, (GameConsts::boardSideSize - 1 - i) * GameConsts::cellEdge);
                }
                else{
                    // se va adauga o noua clasa de piesa mai tarziu
                    sf::Sprite temporary(redQ);
                    temporary.setPosition((GameConsts::boardSideSize - 1 - j) * GameConsts::cellEdge, (GameConsts::boardSideSize - 1 - i) * GameConsts::cellEdge);
                    window.draw(temporary);
                }
    }
}

void Board::loadTexturePack(const std::string &filePref) {
    if(!background.loadFromFile("assets/" + filePref + "_background.png"))
        throw "No _background";
    if(!redQ.loadFromFile("assets/" + filePref + "_redQ.png"))
        throw "No _redQ";
    if(!blueQ.loadFromFile("assets/" + filePref + "_blueQ.png"))
        throw "No _blueQ";

    for(int i = 0; i < GameConsts::boardSideSize; i++)
        for(int j = 0; j < GameConsts::boardSideSize; j++)
            pieces[i][j] -> loadTexture(filePref);
}
