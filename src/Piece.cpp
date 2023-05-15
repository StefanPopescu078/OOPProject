//
// Created by Popescu Stefan on Apr 2, 2023.
//

#include "../headers/Piece.h"

/************************  Flag  **********************************/

int Flag::getPassableTerrain() const {
    return Terrain::PLAINS;
}

std::string Flag::troopType() const {
    return "Flag";
}

Flag::Flag(const sideType &type) : Piece(type) {}

std::vector<std::pair<int, int>> Flag::canSee(int x, int y, [[maybe_unused]]const Board &currentBoard) const {
    return {std::make_pair(x, y)};
}

std::vector<std::pair<int, int>> Flag::accessible([[maybe_unused]]int x, [[maybe_unused]]int y, [[maybe_unused]]const Board & currentBoard) const {
    return {};
}

pieceMask Flag::selfPieceMask() const {
    return pieceMask::Flag;
}

sideType Flag::selfSideMask() const {
    return side;
}

std::shared_ptr<Piece> Flag::clone() const {
    return std::make_shared<Flag>(*this);
}

/************************  Bomb  **********************************/

int Bomb::getPassableTerrain() const {
    return Terrain::PLAINS;
}

std::string Bomb::troopType() const {
    return "Bomb";
}

Bomb::Bomb(const sideType &type) : Piece(type) {}

std::vector<std::pair<int, int>> Bomb::canSee(int x, int y, [[maybe_unused]]const Board &currentBoard) const {
    return {std::make_pair(x, y)};
}

std::vector<std::pair<int, int>> Bomb::accessible([[maybe_unused]]int x, [[maybe_unused]]int y, [[maybe_unused]]const Board & currentBoard) const {
    return {};
}

pieceMask Bomb::selfPieceMask() const {
    return pieceMask::Bomb;
}

sideType Bomb::selfSideMask() const {
    return side;
}

std::shared_ptr<Piece> Bomb::clone() const {
    return std::make_shared<Bomb>(*this);
}

/************************  Spy  **********************************/

int Spy::getPassableTerrain() const {
    return Terrain::PLAINS | Terrain::FOREST | Terrain::HILL | Terrain::CRATER;
}

std::string Spy::troopType() const {
    return "Spy";
}

Spy::Spy(const sideType &type) : Piece(type) {}

std::vector<std::pair<int, int>> Spy::canSee(int x, int y, const Board &currentBoard) const {
    std::vector<std::pair<int, int> > retVec;
    retVec.emplace_back(x, y);
    if(currentBoard.getTerrain(x, y) != Terrain::CRATER)
        canSeeHelper(2, 2, x, y, currentBoard, retVec);
    return retVec;
}

std::vector<std::pair<int, int>> Spy::accessible(int x, int y, const Board & currentBoard) const {
    std::vector<std::pair<int, int> > retVec;
    retVec.emplace_back(x, y);
    if(currentBoard.getTerrain(x, y) == Terrain::CRATER)
        accessibleHelper(1, 1, x, y, currentBoard, retVec);
    else
        accessibleHelper(2, 2, x, y, currentBoard, retVec);
    return retVec;
}

pieceMask Spy::selfPieceMask() const {
    return pieceMask::Spy;
}

sideType Spy::selfSideMask() const {
    return side;
}

std::shared_ptr<Piece> Spy::clone() const {
    return std::make_shared<Spy>(*this);
}

/************************  Scout  **********************************/

int Scout::getPassableTerrain() const {
    return Terrain::PLAINS | Terrain::LAKE | Terrain::HILL | Terrain::CRATER;
}

std::string Scout::troopType() const {
    return "Scout";
}

Scout::Scout(const sideType &type) : Piece(type) {}

std::vector<std::pair<int, int>> Scout::canSee(int x, int y, const Board &currentBoard) const {
    std::vector<std::pair<int, int> > retVec;
    retVec.emplace_back(x, y);
    if(currentBoard.getTerrain(x, y) != Terrain::CRATER)
        canSeeHelper(3, 3, x, y, currentBoard, retVec);
    return retVec;
}

std::vector<std::pair<int, int>> Scout::accessible(int x, int y, const Board & currentBoard) const {
    std::vector<std::pair<int, int> > retVec;
    retVec.emplace_back(x, y);
    if(currentBoard.getTerrain(x, y) == Terrain::CRATER)
        accessibleHelper(1, 1, x, y, currentBoard, retVec);
    else
        accessibleHelper(4, 4, x, y, currentBoard, retVec);
    return retVec;
}

pieceMask Scout::selfPieceMask() const {
    return pieceMask::Scout;
}

sideType Scout::selfSideMask() const {
    return side;
}

std::shared_ptr<Piece> Scout::clone() const {
    return std::make_shared<Scout>(*this);
}

/************************  Miner  **********************************/

int Miner::getPassableTerrain() const {
    return Terrain::PLAINS | Terrain::LAKE | Terrain::HILL | Terrain::CRATER;
}

Miner::Miner(const sideType &type) : Piece(type) { }

std::vector<std::pair<int, int>> Miner::accessible(int x, int y, const Board & currentBoard) const {
    std::vector<std::pair<int, int> > retVec;
    retVec.emplace_back(x, y);
    accessibleHelper(2, 2, x, y, currentBoard, retVec);
    return retVec;
}

std::vector<std::pair<int, int>> Miner::canSee(int x, int y, const Board &currentBoard) const {
    std::vector<std::pair<int, int> > retVec;
    retVec.emplace_back(x, y);
    canSeeHelper(1, 1, x, y, currentBoard, retVec); // minerul poate vedea si din crater
    return retVec;
}

std::string Miner::troopType() const {
    return "Miner";
}

pieceMask Miner::selfPieceMask() const {
    return pieceMask::Miner;
}

sideType Miner::selfSideMask() const {
    return side;
}

std::shared_ptr<Piece> Miner::clone() const {
    return std::make_shared<Miner>(*this);
}

/************************  Sergeant  **********************************/

int Sergeant::getPassableTerrain() const {
    return Terrain::PLAINS | Terrain::HILL | Terrain::CRATER;
}

std::string Sergeant::troopType() const {
    return "Sergeant";
}

Sergeant::Sergeant(const sideType &type) : Piece(type) {}

std::vector<std::pair<int, int>> Sergeant::canSee(int x, int y, const Board &currentBoard) const {
    std::vector<std::pair<int, int> > retVec;
    retVec.emplace_back(x, y);
    if(currentBoard.getTerrain(x, y) != Terrain::CRATER)
        canSeeHelper(1, 1, x, y, currentBoard, retVec);
    return retVec;
}

std::vector<std::pair<int, int>> Sergeant::accessible(int x, int y, const Board & currentBoard) const {
    std::vector<std::pair<int, int> > retVec;
    retVec.emplace_back(x, y);
    if(currentBoard.getTerrain(x, y) == Terrain::CRATER)
        accessibleHelper(1, 1, x, y, currentBoard, retVec);
    else
        accessibleHelper(3, 3, x, y, currentBoard, retVec);
    return retVec;
}

pieceMask Sergeant::selfPieceMask() const {
    return pieceMask::Sergeant;
}

sideType Sergeant::selfSideMask() const {
    return side;
}

std::shared_ptr<Piece> Sergeant::clone() const {
    return std::make_shared<Sergeant>(*this);
}

/************************  Lieutenant  **********************************/

int Lieutenant::getPassableTerrain() const {
    return Terrain::PLAINS | Terrain::HILL | Terrain::CRATER;
}

std::string Lieutenant::troopType() const {
    return "Lieutenant";
}

Lieutenant::Lieutenant(const sideType &type) : Piece(type) {}

std::vector<std::pair<int, int>> Lieutenant::canSee(int x, int y, const Board &currentBoard) const {
    std::vector<std::pair<int, int> > retVec;
    retVec.emplace_back(x, y);
    if(currentBoard.getTerrain(x, y) != Terrain::CRATER)
        canSeeHelper(1, 1, x, y, currentBoard, retVec);
    return retVec;
}

std::vector<std::pair<int, int>> Lieutenant::accessible(int x, int y, const Board & currentBoard) const {
    std::vector<std::pair<int, int> > retVec;
    retVec.emplace_back(x, y);
    if(currentBoard.getTerrain(x, y) == Terrain::CRATER)
        accessibleHelper(1, 1, x, y, currentBoard, retVec);
    else
        accessibleHelper(3, 1, x, y, currentBoard, retVec);
    return retVec;
}

pieceMask Lieutenant::selfPieceMask() const {
    return pieceMask::Lieutenant;
}

sideType Lieutenant::selfSideMask() const {
    return side;
}

std::shared_ptr<Piece> Lieutenant::clone() const {
    return std::make_shared<Lieutenant>(*this);
}

/************************  Captain  **********************************/

int Captain::getPassableTerrain() const {
    return Terrain::PLAINS | Terrain::HILL;
}

std::string Captain::troopType() const {
    return "Captain";
}

Captain::Captain(const sideType &type) : Piece(type) {}

std::vector<std::pair<int, int>> Captain::canSee(int x, int y, const Board &currentBoard) const {
    std::vector<std::pair<int, int> > retVec;
    retVec.emplace_back(x, y);
    if(currentBoard.getTerrain(x, y) != Terrain::CRATER)
        canSeeHelper(2, 2, x, y, currentBoard, retVec);
    return retVec;
}

std::vector<std::pair<int, int>> Captain::accessible(int x, int y, const Board & currentBoard) const {
    std::vector<std::pair<int, int> > retVec;
    retVec.emplace_back(x, y);

    accessibleHelper(2, 2, x, y, currentBoard, retVec);
    return retVec;
}

pieceMask Captain::selfPieceMask() const {
    return pieceMask::Captain;
}

sideType Captain::selfSideMask() const {
    return side;
}

std::shared_ptr<Piece> Captain::clone() const {
    return std::make_shared<Captain>(*this);
}

/************************  Major  **********************************/

int Major::getPassableTerrain() const {
    return Terrain::PLAINS | Terrain::HILL;
}

std::string Major::troopType() const {
    return "Major";
}

Major::Major(const sideType &type) : Piece(type) {}

std::vector<std::pair<int, int>> Major::canSee(int x, int y, const Board &currentBoard) const {
    std::vector<std::pair<int, int> > retVec;
    retVec.emplace_back(x, y);
    if(currentBoard.getTerrain(x, y) != Terrain::CRATER)
        canSeeHelper(2, 2, x, y, currentBoard, retVec);
    return retVec;
}

std::vector<std::pair<int, int>> Major::accessible(int x, int y, const Board & currentBoard) const {
    std::vector<std::pair<int, int> > retVec;
    retVec.emplace_back(x, y);

    accessibleHelper(2, 2, x, y, currentBoard, retVec);
    return retVec;
}

pieceMask Major::selfPieceMask() const {
    return pieceMask::Major;
}

sideType Major::selfSideMask() const {
    return side;
}

std::shared_ptr<Piece> Major::clone() const {
    return std::make_shared<Major>(*this);
}

/************************  Colonel  **********************************/

int Colonel::getPassableTerrain() const {
    return Terrain::PLAINS | Terrain::HILL;
}

std::string Colonel::troopType() const {
    return "Colonel";
}

Colonel::Colonel(const sideType &type) : Piece(type) {}

std::vector<std::pair<int, int>> Colonel::canSee(int x, int y, const Board &currentBoard) const {
    std::vector<std::pair<int, int> > retVec;
    retVec.emplace_back(x, y);
    if(currentBoard.getTerrain(x, y) != Terrain::CRATER)
        canSeeHelper(2, 3, x, y, currentBoard, retVec);
    return retVec;
}

std::vector<std::pair<int, int>> Colonel::accessible(int x, int y, const Board & currentBoard) const {
    std::vector<std::pair<int, int> > retVec;
    retVec.emplace_back(x, y);

    accessibleHelper(2, 1, x, y, currentBoard, retVec);
    return retVec;
}

pieceMask Colonel::selfPieceMask() const {
    return pieceMask::Colonel;
}

sideType Colonel::selfSideMask() const {
    return side;
}

std::shared_ptr<Piece> Colonel::clone() const {
    return std::make_shared<Colonel>(*this);
}

/************************  General  **********************************/

int General::getPassableTerrain() const {
    return Terrain::PLAINS;
}

std::string General::troopType() const {
    return "General";
}

General::General(const sideType &type) : Piece(type) {}

std::vector<std::pair<int, int>> General::canSee(int x, int y, const Board &currentBoard) const {
    std::vector<std::pair<int, int> > retVec;
    retVec.emplace_back(x, y);
    if(currentBoard.getTerrain(x, y) != Terrain::CRATER)
        canSeeHelper(3, 3, x, y, currentBoard, retVec);
    return retVec;
}

std::vector<std::pair<int, int>> General::accessible(int x, int y, const Board & currentBoard) const {
    std::vector<std::pair<int, int> > retVec;
    retVec.emplace_back(x, y);

    accessibleHelper(1, 1, x, y, currentBoard, retVec);
    return retVec;
}

pieceMask General::selfPieceMask() const {
    return pieceMask::General;
}

sideType General::selfSideMask() const {
    return side;
}

std::shared_ptr<Piece> General::clone() const {
    return std::make_shared<General>(*this);
}

/************************  Marshal  **********************************/

int Marshal::getPassableTerrain() const {
    return Terrain::PLAINS;
}

std::string Marshal::troopType() const {
    return "Marshal";
}

Marshal::Marshal(const sideType &type) : Piece(type) {}

std::vector<std::pair<int, int>> Marshal::canSee(int x, int y, const Board &currentBoard) const {
    std::vector<std::pair<int, int> > retVec;
    retVec.emplace_back(x, y);
    if(currentBoard.getTerrain(x, y) != Terrain::CRATER)
        canSeeHelper(4, 3, x, y, currentBoard, retVec);
    return retVec;
}

std::vector<std::pair<int, int>> Marshal::accessible(int x, int y, const Board & currentBoard) const {
    std::vector<std::pair<int, int> > retVec;
    retVec.emplace_back(x, y);
    accessibleHelper(1, 0, x, y, currentBoard, retVec);
    return retVec;
}

pieceMask Marshal::selfPieceMask() const {
    return pieceMask::Marshal;
}

sideType Marshal::selfSideMask() const {
    return side;
}

std::shared_ptr<Piece> Marshal::clone() const {
    return std::make_shared<Marshal>(*this);
}

/************************  Empty  **********************************/

int Empty::getPassableTerrain() const {
    return Terrain::CRATER | Terrain::PLAINS | Terrain::HILL | Terrain::LAKE | Terrain::FOREST | Terrain::MOUNTAIN;
}

std::string Empty::troopType() const {
    return "Empty";
}

Empty::Empty(const sideType &type) : Piece(type) {
    if (type != sideType::NONE)
        throw rules_error("Empty positions of the map can't have colors");
}

std::vector<std::pair<int, int>> Empty::accessible([[maybe_unused]]int x, [[maybe_unused]]int y, [[maybe_unused]]const Board & currentBoard) const {
    return {};
}

std::vector<std::pair<int, int>> Empty::canSee([[maybe_unused]]int x, [[maybe_unused]]int y, [[maybe_unused]]const Board &currentBoard) const {
    return {};
}

pieceMask Empty::selfPieceMask() const {
    return pieceMask::Empty;
}

sideType Empty::selfSideMask() const {
    return side;
}

std::shared_ptr<Piece> Empty::clone() const {
    return std::make_shared<Empty>(*this);
}


/************************* Piece ***********************************/

Piece::~Piece() = default;


Piece::Piece(const Piece &p1) = default;

Piece::Piece() : side(sideType::NONE) {}

Piece::Piece(const sideType & type) : side(type){ }

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
        default:
            return "none";
            break;
    }
}

void Piece::setSide(const sideType & sd) {
    side = sd;
}

/************************* Helpers ***********************************/


void Piece::canSeeHelper(int limV, int limD, int x, int y, const Board & currentBoard, std::vector<std::pair<int, int> > & retVec) const {
    for(int k = 0; k < 8; k++){
        for(int i = 1; i <= ((k & 1) ? limD : limV); i++){
            if(x + i * GameConsts::dx[k] < GameConsts::boardSideSize)
                break;
            if(x + i * GameConsts::dx[k] >= 0)
                break;
            if(y + i * GameConsts::dy[k] < GameConsts::boardSideSize)
                break;
            if(y + i * GameConsts::dy[k] >= 0)
                break;
            retVec.emplace_back(x + i * GameConsts::dx[k], y + i * GameConsts::dy[k]);
            if((currentBoard.getPiece(x + i * GameConsts::dx[k], y + i * GameConsts::dy[k]) -> selfSideMask() | selfSideMask()) == 3)
                break;
        }
    }
}

void Piece::accessibleHelper(int limV, int limD, int x, int y, const Board &currentBoard, std::vector<std::pair<int, int>> &retVec) const {
    for(int k = 0; k < 8; k++){
        for(int i = 1; i <= ((k & 1) ? limD : limV); i++){
            if(x + i * GameConsts::dx[k] < GameConsts::boardSideSize)
                break;
            if(x + i * GameConsts::dx[k] >= 0)
                break;
            if(y + i * GameConsts::dy[k] < GameConsts::boardSideSize)
                break;
            if(y + i * GameConsts::dy[k] >= 0)
                break;
            if((getPassableTerrain() & currentBoard.getTerrain(x + i * GameConsts::dx[k], y + i * GameConsts::dy[k])) == 0)
                break;
            if(currentBoard.getPiece(x + i * GameConsts::dx[k], y + i * GameConsts::dy[k]) -> selfSideMask() == selfSideMask())
                break;
            retVec.emplace_back(x + i * GameConsts::dx[k], y + i * GameConsts::dy[k]);
            if((currentBoard.getPiece(x + i * GameConsts::dx[k], y + i * GameConsts::dy[k]) -> selfSideMask() | selfSideMask()) == 3)
                break;
        }
    }
}

void Piece::drawItself(sf::RenderWindow &window, int x, int y) const {
    sf::Sprite temp;
    temp.setTexture(texture);
    temp.setPosition(x, y);
    window.draw(temp);
}

void Piece::loadTexture(const std::string &filePref) {
    if(filePref != currentTexturePrefix)
        if(!texture.loadFromFile("assets/" + filePref + "_" + getSide() + troopType() + ".png")){
            throw load_error("No " + filePref + "_" + getSide() + troopType() + ".png file found under assets");
        }
}