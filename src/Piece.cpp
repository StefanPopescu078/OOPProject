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

std::vector<std::pair<int, int>> Flag::canSee(int x, int y, const Board &currentBoard) const {
    return {std::make_pair(x, y)};
}

std::vector<std::pair<int, int>> Flag::accessible(int x, int y, const Board & currentBoard) const {
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

void Flag::loadTexture(const std::string &filePref) {
    if(side == sideType::Red){
        if(!texture.loadFromFile("assets/" + filePref + "_redFlag.png"))
            throw "No redFlag";
    }
    else{
        if(!texture.loadFromFile("assets/" + filePref + "_blueFlag.png"))
            throw "No blueFlag";
    }
}

/************************  Bomb  **********************************/

int Bomb::getPassableTerrain() const {
    return Terrain::PLAINS;
}

std::string Bomb::troopType() const {
    return "Bomb";
}

Bomb::Bomb(const sideType &type) : Piece(type) {}

std::vector<std::pair<int, int>> Bomb::canSee(int x, int y, const Board &currentBoard) const {
    return {std::make_pair(x, y)};
}

std::vector<std::pair<int, int>> Bomb::accessible(int x, int y, const Board & currentBoard) const {
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

void Bomb::loadTexture(const std::string &filePref) {
    if(side == sideType::Red){
        if(!texture.loadFromFile("assets/" + filePref + "_redBomb.png"))
            throw "No redBomb";
    }
    else{
        if(!texture.loadFromFile("assets/" + filePref + "_blueBomb.png"))
            throw "No blueBomb";
    }
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

void Spy::loadTexture(const std::string &filePref) {
    if(side == sideType::Red){
        if(!texture.loadFromFile("assets/" + filePref + "_redSpy.png"))
            throw "No redSpy";
    }
    else{
        if(!texture.loadFromFile("assets/" + filePref + "_blueSpy.png"))
            throw "No blueSpy";
    }
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

void Scout::loadTexture(const std::string &filePref) {
    if(side == sideType::Red){
        if(!texture.loadFromFile("assets/" + filePref + "_redScout.png"))
            throw "No redScout";
    }
    else{
        if(!texture.loadFromFile("assets/" + filePref + "_blueScout.png"))
            throw "No blueScout";
    }
}

/************************  Miner  **********************************/

int Miner::getPassableTerrain() const {
    return Terrain::PLAINS | Terrain::LAKE | Terrain::HILL | Terrain::CRATER;
}

Miner::Miner(const sideType &type) : Piece(type) {

}

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

void Miner::loadTexture(const std::string &filePref) {
    if(side == sideType::Red){
        if(!texture.loadFromFile("assets/" + filePref + "_redMiner.png"))
            throw "No redMiner";
    }
    else{
        if(!texture.loadFromFile("assets/" + filePref + "_blueMiner.png"))
            throw "No blueMiner";
    }
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

void Sergeant::loadTexture(const std::string &filePref) {
    if(side == sideType::Red){
        if(!texture.loadFromFile("assets/" + filePref + "_red1.png"))
            throw "No red1";
    }
    else{
        if(!texture.loadFromFile("assets/" + filePref + "_blue1.png"))
            throw "No blue1";
    }
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

void Lieutenant::loadTexture(const std::string &filePref) {
    if(side == sideType::Red){
        if(!texture.loadFromFile("assets/" + filePref + "_red2.png"))
            throw "No red2";
    }
    else{
        if(!texture.loadFromFile("assets/" + filePref + "_blue2.png"))
            throw "No blue2";
    }
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

void Captain::loadTexture(const std::string &filePref) {
    if(side == sideType::Red){
        if(!texture.loadFromFile("assets/" + filePref + "_red3.png"))
            throw "No red3";
    }
    else{
        if(!texture.loadFromFile("assets/" + filePref + "_blue3.png"))
            throw "No blue3";
    }
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

void Major::loadTexture(const std::string &filePref) {
    if(side == sideType::Red){
        if(!texture.loadFromFile("assets/" + filePref + "_red4.png"))
            throw "No red4";
    }
    else {
        if (!texture.loadFromFile("assets/" + filePref + "_blue4.png"))
            throw "No blue4";
    }
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

void Colonel::loadTexture(const std::string &filePref) {
    if(side == sideType::Red){
        if(!texture.loadFromFile("assets/" + filePref + "_red5.png"))
            throw "No red5";
    }
    else{
        if(!texture.loadFromFile("assets/" + filePref + "_blue5.png"))
            throw "No blue5";
    }
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

void General::loadTexture(const std::string &filePref) {
    if(side == sideType::Red){
        if(!texture.loadFromFile("assets/" + filePref + "_red6.png"))
            throw "No red6";
    }
    else{
        if(!texture.loadFromFile("assets/" + filePref + "_blue6.png"))
            throw "No blue6";
    }
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

void Marshal::loadTexture(const std::string &filePref) {
    if(side == sideType::Red){
        if(!texture.loadFromFile("assets/" + filePref + "_red7.png"))
            throw "No red7";
    }
    else{
        if(!texture.loadFromFile("assets/" + filePref + "_blue7.png"))
            throw "No blue7";
    }
}

/************************  Empty  **********************************/

int Empty::getPassableTerrain() const {
    return Terrain::CRATER | Terrain::PLAINS | Terrain::HILL | Terrain::LAKE | Terrain::FOREST | Terrain::MOUNTAIN;
}

std::string Empty::troopType() const {
    return "Empty";
}

Empty::Empty(const sideType &type) : Piece(type) {}

std::vector<std::pair<int, int>> Empty::accessible(int x, int y, const Board & currentBoard) const {
    return {};
}

std::vector<std::pair<int, int>> Empty::canSee(int x, int y, const Board &currentBoard) const {
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

void Empty::loadTexture(const std::string &filePref) {
    if(!texture.loadFromFile("assets/" + filePref + "_empty.png"))
        throw "No empty";
}

/************************* Piece ***********************************/

Piece::~Piece() = default;



Piece::Piece(const Piece &p1) = default;

Piece::Piece() : side(sideType::None) {}

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
    throw "You shouldn't be here";
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
