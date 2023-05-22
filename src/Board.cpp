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
    ptrEmpty = std::make_shared<Empty>(sideType::NONE);
//    pieces[0][0] = std::make_shared<Empty>(sideType::NONE);
    for(int i = 0; i < GameConsts::boardSideSize; i++)
        for(int j = 0; j < GameConsts::boardSideSize; j++)
            pieces[i][j] = ptrEmpty;
//            if(i != 0 || j != 0)
//                pieces[i][j] = pieces[0][0];


    pieces[0][1] = std::make_shared<Flag>(sideType::Red);

    pieces[0][2] = pieces[0][3] = pieces[0][4] =
            pieces[0][5] = pieces[0][6] = pieces[0][7] = std::make_shared<Bomb>(sideType::Red);

    pieces[0][8] = std::make_shared<Spy>(sideType::Red);

    pieces[0][9] = pieces[0][10] = pieces[0][11] = pieces[0][12] =
        pieces[1][9] = pieces[1][10] = pieces[1][11] = pieces[1][12] = std::make_shared<Scout>(sideType::Red);

    pieces[1][13] = pieces[2][13] = pieces[3][13] = pieces[2][12] = pieces[2][11] = std::make_shared<Miner>(sideType::Red);

    pieces[1][0] = pieces[1][1] = pieces[1][2] = pieces[1][3] = MilitaryFactory::getSergeant(sideType::Red);

    pieces[1][4] = pieces[1][5] = pieces[1][6] = pieces[1][7] = MilitaryFactory::getLieutenant(sideType::Red);

    pieces[1][8] = pieces[2][8] = pieces[2][7] = pieces[2][9] = MilitaryFactory::getCaptain(sideType::Red);

    pieces[2][6] = pieces[2][5] = pieces[2][4] = MilitaryFactory::getMajor(sideType::Red);
    pieces[2][3] = MilitaryFactory::getColonel(sideType::Red);
    pieces[2][2] = std::make_shared<MobileGeneral>(sideType::Red);
    pieces[2][1] = MilitaryFactory::getGeneral(sideType::Red);
    pieces[2][0] = std::make_shared<Marshal>(sideType::Red);



    pieces[13 - 0][13 - 1] = std::make_shared<Flag>(sideType::Blue);

    pieces[13 - 0][13 - 2] = pieces[13 - 0][13 - 3] = pieces[13 - 0][13 - 4] =
    pieces[13 - 0][13 - 5] = pieces[13 - 0][13 - 6] = pieces[13 - 0][13 - 7] = std::make_shared<Bomb>(sideType::Blue);

    pieces[13 - 0][13 - 8] = std::make_shared<Spy>(sideType::Blue);

    pieces[13 - 0][13 - 9] = pieces[13 - 0][13 - 10] = pieces[13 - 0][13 - 11] = pieces[13 - 0][13 - 12] =
    pieces[13 - 1][13 - 9] = pieces[13 - 1][13 - 10] = pieces[13 - 1][13 - 11] = pieces[13 - 1][13 - 12] = std::make_shared<Scout>(sideType::Blue);

    pieces[13 - 1][0] = pieces[13 - 2][0] = pieces[13 - 3][0] = pieces[13 - 2][13 - 12] = pieces[13 - 2][13 - 11] = std::make_shared<Miner>(sideType::Blue);

    pieces[13 - 1][13 - 0] = pieces[13 - 1][13 - 1] = pieces[13 - 1][13 - 2] = pieces[13 - 1][13 - 3] = MilitaryFactory::getSergeant(sideType::Blue);

    pieces[13 - 1][13 - 4] = pieces[13 - 1][13 - 5] = pieces[13 - 1][13 - 6] = pieces[13 - 1][13 - 7] = MilitaryFactory::getLieutenant(sideType::Blue);

    pieces[13 - 1][13 - 8] = pieces[13 - 2][13 - 8] = pieces[13 - 2][13 - 7] = pieces[13 - 2][13 - 9] = MilitaryFactory::getCaptain(sideType::Blue);

    pieces[13 - 2][13 - 6] = pieces[13 - 2][13 - 5] = pieces[13 - 2][13 - 4] = MilitaryFactory::getMajor(sideType::Blue);
    pieces[13 - 2][13 - 3] = MilitaryFactory::getColonel(sideType::Blue);
    pieces[13 - 2][13 - 2] = std::make_shared<MobileGeneral>(sideType::Blue);
    pieces[13 - 2][13 - 1] = MilitaryFactory::getGeneral(sideType::Blue);
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
        throw rules_error("Invalid coordinates in Board::getTerrain");
    return cellTypes[x][y];
}

std::shared_ptr<Piece> Board::getPiece(int x, int y) const {
    if(!(x >= 0 && y >= 0 && x < GameConsts::boardSideSize && y < GameConsts::boardSideSize)) // debugging
        throw rules_error("Invalid coordinates in Board::getPiece");
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
    for(int i = 0; i < GameConsts::boardSideSize; i++)
        for(int j = 0; j < GameConsts::boardSideSize; j++) {
            switch (cellTypes[i][j]) {
                case Terrain::FOREST:
                    break;
                case Terrain::MOUNTAIN:
                    break;
                case Terrain::LAKE:
                    break;
                case Terrain::HILL:
                    break;
                case Terrain::CRATER:
                    break;
                case Terrain::PLAINS:
                    break;
            }
        }
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

    for(int i = 0; i < GameConsts::boardSideSize; i++)
        for(int j = 0; j < GameConsts::boardSideSize; j++)
            if(i != isDragged.first || j != isDragged.second) {
                if (visibleMatrix[i][j] || pieces[i][j]->selfSideMask() == sideType::NONE) {
                    pieces[i][j]->drawItself(window, j * GameConsts::cellEdge, i * GameConsts::cellEdge);
                } else {
                    sf::Sprite temporary(currPlayer == sideType::Red ? blueQ : redQ);
                    temporary.setPosition(j * GameConsts::cellEdge, i * GameConsts::cellEdge);
                    window.draw(temporary);
                }
            }
    for(auto &x:toBeHighlighted){
        sf::Sprite temporary(accs);
        temporary.setPosition(x.second * GameConsts::cellEdge, x.first * GameConsts::cellEdge);
        window.draw(temporary);
    }
}

void Board::loadTexturePack(const std::string &filePref) {
    if(!background.loadFromFile("assets/" + filePref + "_background.png"))
        throw load_error("_background");
    if(!redQ.loadFromFile("assets/" + filePref + "_redQ.png"))
        throw load_error("_redQ");
    if(!blueQ.loadFromFile("assets/" + filePref + "_blueQ.png"))
        throw load_error("_blueQ");
    if(!accs.loadFromFile("assets/" + filePref + "_accs.png"))
        throw load_error("_accs");

    for(int i = 0; i < GameConsts::boardSideSize; i++)
        for(int j = 0; j < GameConsts::boardSideSize; j++)
            pieces[i][j] -> loadTexture(filePref);
}

Board &Board::operator=(Board &&b2) {
    pieces = std::move(b2.pieces);
    cellTypes = b2.cellTypes;
    background = b2.background;
    redQ = b2.redQ;
    blueQ = b2.blueQ;
    ptrEmpty = b2.ptrEmpty;
    return *this;
}

void Board::getOutcomeAttack(const std::pair<int, int> & pAttacked, const std::pair<int, int> & pAttacker) {
    const std::shared_ptr<Piece> & attacked = getPiece(pAttacked.first, pAttacked.second), attacker = getPiece(pAttacker.first, pAttacker.second);
    if(attacked ->selfPieceMask() == pieceMask::Bomb){
        if(attacker ->selfPieceMask() == pieceMask::Miner){ // dezamorseaza
            std::cerr << "jaoisdjFOIAJSDOIFJAOSDJFOIAJSDDFOIJASOIDFJIOASJEFoiasjdo\n";
            std::tie(pieces[pAttacked.first][pAttacked.second], pieces[pAttacker.first][pAttacker.second] ) =
                    std::make_tuple(pieces[pAttacker.first][pAttacker.second], ptrEmpty);
        }
        else{ // explozie
            std::tie(pieces[pAttacked.first][pAttacked.second], pieces[pAttacker.first][pAttacker.second] ) =
                    std::make_tuple(ptrEmpty, ptrEmpty);
            explode(pAttacked.first, pAttacked.second);
        }
    }
    else if(attacker ->selfPieceMask() == pieceMask::Spy){
        if(attacked ->selfPieceMask() == pieceMask::Marshal){
            std::tie(pieces[pAttacked.first][pAttacked.second], pieces[pAttacker.first][pAttacker.second] ) =
                    std::make_tuple(pieces[pAttacker.first][pAttacker.second], ptrEmpty);
        }
    }
    else if(attacker ->selfPieceMask() == pieceMask::Scout && attacked ->selfPieceMask() == pieceMask::Miner){
        std::tie(pieces[pAttacked.first][pAttacked.second], pieces[pAttacker.first][pAttacker.second] ) =
                std::make_tuple(pieces[pAttacker.first][pAttacker.second], ptrEmpty);
    }

    else if(attacker ->selfPieceMask() >= attacked ->selfPieceMask()){
        std::tie(pieces[pAttacked.first][pAttacked.second], pieces[pAttacker.first][pAttacker.second] ) =
                std::make_tuple(pieces[pAttacker.first][pAttacker.second], ptrEmpty);
    }
    else{
        std::tie(pieces[pAttacked.first][pAttacked.second], pieces[pAttacker.first][pAttacker.second] ) =
                std::make_tuple(pieces[pAttacked.first][pAttacked.second], ptrEmpty);
    }
}

std::pair<int, int> Board::isDragged = std::make_pair(-1, -1);

void Board::setDrag(std::pair<int, int> p1) {
    isDragged = std::move(p1);
}

void Board::resetDrag() {
    isDragged = std::make_pair(-1, -1);
}

std::vector<std::pair<int, int> > Board::toBeHighlighted = {};

void Board::setAcc(std::vector<std::pair<int, int>> temp) {
    toBeHighlighted = std::move(temp);
}

void Board::explode(int x, int y) {
    if(x < 0 || x >= GameConsts::boardSideSize || y < 0 || y >= GameConsts::boardSideSize)
        throw rules_error("Explosion out of map");
    cellTypes[x][y] = Terrain::CRATER;
}

bool Board::getOutcomeSwap(const std::pair<int, int> & p1, const std::pair<int, int> & p2) {
    if( (getPiece(p1.first, p1.second) -> getPassableTerrain() & cellTypes[p2.first][p2.second] ) &
            (getPiece(p2.first, p2.second) -> getPassableTerrain() & cellTypes[p1.first][p1.second] ) ){
        std::swap(pieces[p1.first][p1.second], pieces[p2.first][p2.second]);
        return true;
    }
    return false;
}
