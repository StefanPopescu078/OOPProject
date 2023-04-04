//
// Created by Popescu Stefan on Apr 2, 2023.
//

#include "../headers/Piece.h"

/************************  Flag  **********************************/

std::vector<Terrain> Flag::getPassableTerrain() const {
    return {Terrain::PLAINS};
}

std::string Flag::troopType() const {
    return std::string("Flag");
}

Flag::Flag(const sideType &type) : Piece(type) {}

std::vector<std::pair<int, int>> Flag::canSee(int x, int y, const Board &currentBoard) const {
    return {};
}

std::vector<std::pair<int, int>> Flag::accessible(int x, int y) const {
    return {};
}

/************************  Bomb  **********************************/

std::vector<Terrain> Bomb::getPassableTerrain() const {
    return {Terrain::PLAINS};
}

std::string Bomb::troopType() const {
    return std::string("Bomb");
}

Bomb::Bomb(const sideType &type) : Piece(type) {}

std::vector<std::pair<int, int>> Bomb::canSee(int x, int y, const Board &currentBoard) const {
    return {};
}

std::vector<std::pair<int, int>> Bomb::accessible(int x, int y) const {
    return {};
}

/************************  Spy  **********************************/

std::vector<Terrain> Spy::getPassableTerrain() const {
    return {Terrain::PLAINS, Terrain::FOREST, Terrain::HILL, Terrain::CRATER};
}

std::string Spy::troopType() const {
    return std::string("Spy");
}

Spy::Spy(const sideType &type) : Piece(type) {}

std::vector<std::pair<int, int>> Spy::canSee(int x, int y, const Board &currentBoard) const {
    return {};
}

std::vector<std::pair<int, int>> Spy::accessible(int x, int y) const {
    return {};
}

/************************  Scout  **********************************/

std::vector<Terrain> Scout::getPassableTerrain() const {
    return {Terrain::PLAINS, Terrain::LAKE, Terrain::HILL, Terrain::CRATER};
}

std::string Scout::troopType() const {
    return std::string("Scout");
}

Scout::Scout(const sideType &type) : Piece(type) {}

std::vector<std::pair<int, int>> Scout::canSee(int x, int y, const Board &currentBoard) const {
    return {};
}

std::vector<std::pair<int, int>> Scout::accessible(int x, int y) const {
    return {};
}

/************************  Miner  **********************************/

std::vector<Terrain> Miner::getPassableTerrain() const {
    return {Terrain::PLAINS, Terrain::LAKE, Terrain::HILL, Terrain::CRATER};
}

Miner::Miner(const sideType &type) : Piece(type) {

}

std::vector<std::pair<int, int>> Miner::accessible(int x, int y) const {
    return {};
}

std::vector<std::pair<int, int>> Miner::canSee(int x, int y, const Board &currentBoard) const {
    return {};
}

std::string Miner::troopType() const {
    return std::string("Miner");
}

/************************  Sergeant  **********************************/

std::vector<Terrain> Sergeant::getPassableTerrain() const {
    return {Terrain::PLAINS, Terrain::HILL, Terrain::CRATER};
}

std::string Sergeant::troopType() const {
    return std::string("Sergeant");
}

Sergeant::Sergeant(const sideType &type) : Piece(type) {}

std::vector<std::pair<int, int>> Sergeant::canSee(int x, int y, const Board &currentBoard) const {
    return {};
}

std::vector<std::pair<int, int>> Sergeant::accessible(int x, int y) const {
    return {};
}

/************************  Lieutenant  **********************************/

std::vector<Terrain> Lieutenant::getPassableTerrain() const {
    return {Terrain::PLAINS, Terrain::HILL, Terrain::CRATER};
}

std::string Lieutenant::troopType() const {
    return std::string("Lieutenant");
}

Lieutenant::Lieutenant(const sideType &type) : Piece(type) {}

std::vector<std::pair<int, int>> Lieutenant::canSee(int x, int y, const Board &currentBoard) const {
    return {};
}

std::vector<std::pair<int, int>> Lieutenant::accessible(int x, int y) const {
    return {};
}

/************************  Captain  **********************************/

std::vector<Terrain> Captain::getPassableTerrain() const {
    return {Terrain::PLAINS, Terrain::HILL};
}

std::string Captain::troopType() const {
    return std::string("Captain");
}

Captain::Captain(const sideType &type) : Piece(type) {}

std::vector<std::pair<int, int>> Captain::canSee(int x, int y, const Board &currentBoard) const {
    return {};
}

std::vector<std::pair<int, int>> Captain::accessible(int x, int y) const {
    return {};
}

/************************  Major  **********************************/

std::vector<Terrain> Major::getPassableTerrain() const {
    return {Terrain::PLAINS, Terrain::HILL};
}

std::string Major::troopType() const {
    return std::string("Major");
}

Major::Major(const sideType &type) : Piece(type) {}

std::vector<std::pair<int, int>> Major::canSee(int x, int y, const Board &currentBoard) const {
    return {};
}

std::vector<std::pair<int, int>> Major::accessible(int x, int y) const {
    return {};
}

/************************  Colonel  **********************************/

std::vector<Terrain> Colonel::getPassableTerrain() const {
    return {Terrain::PLAINS, Terrain::HILL};
}

std::string Colonel::troopType() const {
    return std::string("Colonel");
}

Colonel::Colonel(const sideType &type) : Piece(type) {}

std::vector<std::pair<int, int>> Colonel::canSee(int x, int y, const Board &currentBoard) const {
    return {};
}

std::vector<std::pair<int, int>> Colonel::accessible(int x, int y) const {
    return {};
}

/************************  General  **********************************/

std::vector<Terrain> General::getPassableTerrain() const {
    return {Terrain::PLAINS};
}

std::string General::troopType() const {
    return std::string("General");
}

General::General(const sideType &type) : Piece(type) {}

std::vector<std::pair<int, int>> General::canSee(int x, int y, const Board &currentBoard) const {
    return {};
}

std::vector<std::pair<int, int>> General::accessible(int x, int y) const {
    return {};
}

/************************  Marshal  **********************************/

std::vector<Terrain> Marshal::getPassableTerrain() const {
    return {Terrain::PLAINS};
}

std::string Marshal::troopType() const {
    return std::string("Marshal");
}

Marshal::Marshal(const sideType &type) : Piece(type) {}

std::vector<std::pair<int, int>> Marshal::canSee(int x, int y, const Board &currentBoard) const {
    return {};
}

std::vector<std::pair<int, int>> Marshal::accessible(int x, int y) const {
    return {};
}

/************************  Empty  **********************************/

std::vector<Terrain> Empty::getPassableTerrain() const {
    return {};
}

std::string Empty::troopType() const {
    return std::string("Empty");
}

Empty::Empty(const sideType &type) : Piece(type) {}

std::vector<std::pair<int, int>> Empty::accessible(int x, int y) const {
    return {};
}

std::vector<std::pair<int, int>> Empty::canSee(int x, int y, const Board &currentBoard) const {
    return {};
}

/************************* Piece ***********************************/

Piece::~Piece() {

}

Piece::Piece(Piece &p1) : side(p1.side) { }

Piece::Piece(const sideType & type = sideType::None) : side(type){ }

std::ostream &operator<<(std::ostream &out, const Piece &pc) {
    out << pc.getSide() << " " << pc.troopType();
    return out;
}

std::string Piece::getSide() const{
    switch (side) {
        case sideType::Red:
            return "red";
            break;
        case sideType::Blue:
            return "blue";
            break;
        case sideType::None:
            return "none";
            break;
    }
}

std::string Piece::setSide(const sideType & sd) {
    side = sd;
}
