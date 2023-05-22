//
// Created by Popescu Stefan on Apr 2, 2023.
//

#include <utility>
#include <thread>
#include <chrono>
#include <iostream>
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

/************************  MilitaryPiece  **********************************/

MilitaryPieceBase::MilitaryPieceBase(const sideType & type, const pieceMask & pMask, std::string name) : Piece(type), selfName(std::move(name)), selfMask(pMask) {}

void MilitaryPieceBase::playDrums() const {
    sf::SoundBuffer buff;

    if(!buff.loadFromFile("assets/marchingSound.wav"))
        throw load_error("drums");
    sf::Sound snd;

    snd.setBuffer(buff);
    snd.play();
    while(snd.getStatus() == sf::Sound::Playing){
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(100ms);
    }
}

template<bool canTakeCrater, bool canTakeHill, int canOrt, int canDiag, int seeOrt, int seeDiag>
MilitaryPiece<canTakeCrater, canTakeHill, canOrt, canDiag, seeOrt, seeDiag>::MilitaryPiece(const sideType & type,
                                                                          const pieceMask & pMask, std::string name) : MilitaryPieceBase(type, pMask, name) {}

template<bool canTakeCrater, bool canTakeHill, int canOrt, int canDiag, int seeOrt, int seeDiag>
int MilitaryPiece<canTakeCrater, canTakeHill, canOrt, canDiag, seeOrt, seeDiag>::getPassableTerrain() const {
    return Terrain::PLAINS | (canTakeCrater ? Terrain::CRATER : 0) | (canTakeHill ? Terrain::HILL : 0);
    // avand in vedere ca linia de mai sus e dependenta de lucruri cunoscute strict la compilare,
    // ar trebui sa se comporte precum un constexpr
}


template<bool canTakeCrater, bool canTakeHill, int canOrt, int canDiag, int seeOrt, int seeDiag>
std::vector<std::pair<int, int>>
MilitaryPiece<canTakeCrater, canTakeHill, canOrt, canDiag, seeOrt, seeDiag>::canSee(int x, int y, const Board &currentBoard) const {
    std::vector<std::pair<int, int> > retVec;
    retVec.emplace_back(x, y);
    if(currentBoard.getTerrain(x, y) != Terrain::CRATER)
        canSeeHelper(seeOrt, seeDiag, x, y, currentBoard, retVec);
    return retVec;
}

template<bool canTakeCrater, bool canTakeHill, int canOrt, int canDiag, int seeOrt, int seeDiag>
std::vector<std::pair<int, int>>
MilitaryPiece<canTakeCrater, canTakeHill, canOrt, canDiag, seeOrt, seeDiag>::accessible(int x, int y, const Board &currentBoard) const {
    std::vector<std::pair<int, int> > retVec;
    retVec.emplace_back(x, y);
    if(currentBoard.getTerrain(x, y) == Terrain::CRATER)
        accessibleHelper(1, 1, x, y, currentBoard, retVec);
    else
        accessibleHelper(canOrt, canDiag, x, y, currentBoard, retVec);
    return retVec;
}

template<bool canTakeCrater, bool canTakeHill, int canOrt, int canDiag, int seeOrt, int seeDiag>
std::shared_ptr<Piece> MilitaryPiece<canTakeCrater, canTakeHill, canOrt, canDiag, seeOrt, seeDiag>::clone() const {
    return std::make_shared<MilitaryPiece<canTakeCrater, canTakeHill, canOrt, canDiag, seeOrt, seeDiag> >(*this);
}

template<bool canTakeCrater, bool canTakeHill, int canOrt, int canDiag, int seeOrt, int seeDiag>
std::string MilitaryPiece<canTakeCrater, canTakeHill, canOrt, canDiag, seeOrt, seeDiag>::troopType() const {
    return selfName;
}

template<bool canTakeCrater, bool canTakeHill, int canOrt, int canDiag, int seeOrt, int seeDiag>
pieceMask MilitaryPiece<canTakeCrater, canTakeHill, canOrt, canDiag, seeOrt, seeDiag>::selfPieceMask() const {
    return selfMask;
}

template<bool canTakeCrater, bool canTakeHill, int canOrt, int canDiag, int seeOrt, int seeDiag>
sideType MilitaryPiece<canTakeCrater, canTakeHill, canOrt, canDiag, seeOrt, seeDiag>::selfSideMask() const {
    return side;
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
            if(x + i * GameConsts::dx[k] >= GameConsts::boardSideSize)
                break;
            if(x + i * GameConsts::dx[k] < 0)
                break;
            if(y + i * GameConsts::dy[k] >= GameConsts::boardSideSize)
                break;
            if(y + i * GameConsts::dy[k] < 0)
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
            if(x + i * GameConsts::dx[k] >= GameConsts::boardSideSize)
                break;
            if(x + i * GameConsts::dx[k] < 0)
                break;
            if(y + i * GameConsts::dy[k] >= GameConsts::boardSideSize)
                break;
            if(y + i * GameConsts::dy[k] < 0)
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

/************************* MilitaryFactory ***********************************/


std::shared_ptr<Piece> MilitaryFactory::getSergeant(const sideType & sd) {
    return std::make_shared<MilitaryPiece<true, true, 3, 3, 1, 1>>(sd, pieceMask::Sergeant, "Sergeant");
}

std::shared_ptr<Piece> MilitaryFactory::getLieutenant(const sideType & sd) {
    return std::make_shared<MilitaryPiece<true, true, 3, 1, 1, 1>>(sd, pieceMask::Lieutenant, "Lieutenant");
}

std::shared_ptr<Piece> MilitaryFactory::getCaptain(const sideType & sd) {
    return std::make_shared<MilitaryPiece<false, true, 2, 2, 2, 2>>(sd, pieceMask::Captain, "Captain");
}

std::shared_ptr<Piece> MilitaryFactory::getMajor(const sideType & sd) {
    return std::make_shared<MilitaryPiece<false, true, 1, 2, 3, 2>>(sd, pieceMask::Major, "Major");
}

std::shared_ptr<Piece> MilitaryFactory::getColonel(const sideType & sd) {
    return std::make_shared<MilitaryPiece<false, true, 2, 1, 2, 3>>(sd, pieceMask::Colonel, "Colonel");
}

std::shared_ptr<Piece> MilitaryFactory::getGeneral(const sideType & sd) {
    return std::make_shared<MilitaryPiece<false, false, 1, 1, 3, 3>>(sd, pieceMask::General, "General");
}


MobileGeneral::MobileGeneral(const sideType &sd) : MilitaryPiece<true, true, 4, 4, 2, 2>(sd, pieceMask::General, "Mobile General") { }

std::shared_ptr<Piece> MobileGeneral::clone() const {
    return std::make_shared<MobileGeneral>(*this);
}

void MobileGeneral::playDrums() const {
    // se poate pune un sunet de flaut ca inlocuire
    MilitaryPieceBase::playDrums();
}

