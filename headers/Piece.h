//
// Created by Popescu Stefan on Apr 2, 2023.
//

#ifndef OOP_PIECE_H
#define OOP_PIECE_H


class Board;

#include "Board.h"
#include <vector>
#include <ostream>
#include <string>
#include "CustomExceptions.h"


class Piece{
protected:
    sideType side;
    std::string currentTexturePrefix; // variable that stores the current texture prefix
    sf::Texture texture;
    void canSeeHelper(int limV, int limD, int x, int y, const Board & currentBoard, std::vector<std::pair<int, int> > & retVec) const;
    void accessibleHelper(int limV, int limD, int x, int y, const Board & currentBoard, std::vector<std::pair<int, int> > & retVec) const;
public:
    Piece();
    explicit Piece(const sideType &);
    Piece(const Piece & p1);
    virtual ~Piece(); // are clase derivate

    virtual std::vector<std::pair<int, int>> accessible(int x, int y, const Board & currentBoard) const = 0;
    virtual int getPassableTerrain() const = 0;
    virtual std::vector<std::pair<int, int>> canSee(int x, int y, const Board & currentBoard) const = 0;
    virtual std::string troopType() const = 0;
    virtual pieceMask selfPieceMask() const = 0;
    virtual sideType selfSideMask() const = 0;
    std::string getSide() const;
    void setSide(const sideType & sd);
    friend std::ostream & operator << (std::ostream & out, const Piece & p1);
    void drawItself(sf::RenderWindow& window, int x, int y) const;
    virtual std::shared_ptr<Piece> clone() const = 0;
    void loadTexture(const std::string & filePref);
};

class Flag : public Piece {
public:
    explicit Flag(const sideType &type);

    std::vector<std::pair<int, int>> accessible(int x, int y, const Board & currentBoard) const override;

    int getPassableTerrain() const override;
    std::vector<std::pair<int, int>> canSee(int x, int y, const Board & currentBoard) const override;
    std::string troopType() const override;
    pieceMask selfPieceMask() const override;
    sideType selfSideMask() const override;
    std::shared_ptr<Piece> clone() const override;
};

class Bomb : public Piece {
public:
    explicit Bomb(const sideType &type);

    std::vector<std::pair<int, int>> accessible(int x, int y, const Board & currentBoard) const override;
    int getPassableTerrain() const override;
    std::vector<std::pair<int, int>> canSee(int x, int y, const Board & currentBoard) const override;
    std::string troopType() const override;
    pieceMask selfPieceMask() const override;
    sideType selfSideMask() const override;
    std::shared_ptr<Piece> clone() const override;
};

class Spy : public Piece {
public:
    explicit Spy(const sideType &type);

    std::vector<std::pair<int, int>> accessible(int x, int y, const Board & currentBoard) const override;
    int getPassableTerrain() const override;
    std::vector<std::pair<int, int>> canSee(int x, int y, const Board & currentBoard) const override;
    std::string troopType() const override;
    pieceMask selfPieceMask() const override;
    sideType selfSideMask() const override;
    std::shared_ptr<Piece> clone() const override;
};

class Scout : public Piece {
public:
    explicit Scout(const sideType &type);

    std::vector<std::pair<int, int>> accessible(int x, int y, const Board & currentBoard) const override;
    int getPassableTerrain() const override;
    std::vector<std::pair<int, int>> canSee(int x, int y, const Board & currentBoard) const override;
    std::string troopType() const override;
    pieceMask selfPieceMask() const override;
    sideType selfSideMask() const override;
    std::shared_ptr<Piece> clone() const override;
};

class Miner : public Piece {
public:
    explicit Miner(const sideType &type);

    std::vector<std::pair<int, int>> accessible(int x, int y, const Board & currentBoard) const override;
    int getPassableTerrain() const override;
    std::vector<std::pair<int, int>> canSee(int x, int y, const Board & currentBoard) const override;
    std::string troopType() const override;
    pieceMask selfPieceMask() const override;
    sideType selfSideMask() const override;
    std::shared_ptr<Piece> clone() const override;
};

class MilitaryPieceBase : public Piece{
protected:
    std::string selfName;
    pieceMask selfMask;
public:
    virtual void playDrums() const;
    MilitaryPieceBase(const sideType&, const pieceMask&, std::string);
};

// argumentele
template<bool canTakeCrater, bool canTakeHill, int canOrt, int canDiag, int seeOrt, int seeDiag>
class MilitaryPiece : public MilitaryPieceBase{
public:
    explicit MilitaryPiece(const sideType&, const pieceMask&, std::string );
    std::vector<std::pair<int, int>> accessible(int x, int y, const Board & currentBoard) const override;
    int getPassableTerrain() const override;
    std::vector<std::pair<int, int>> canSee(int x, int y, const Board & currentBoard) const override;
    std::string troopType() const override;
    pieceMask selfPieceMask() const override;
    sideType selfSideMask() const override;
    std::shared_ptr<Piece> clone() const override;
};

class MilitaryFactory{
public:
    static std::shared_ptr<Piece> getSergeant(const sideType&);
    static std::shared_ptr<Piece> getLieutenant(const sideType&);
    static std::shared_ptr<Piece> getCaptain(const sideType&);
    static std::shared_ptr<Piece> getMajor(const sideType&);
    static std::shared_ptr<Piece> getColonel(const sideType&);
    static std::shared_ptr<Piece> getGeneral(const sideType&);
};

class Marshal: public Piece {
public:
    explicit Marshal(const sideType &type);

    std::vector<std::pair<int, int>> accessible(int x, int y, const Board & currentBoard) const override;
    int getPassableTerrain() const override;
    std::vector<std::pair<int, int>> canSee(int x, int y, const Board & currentBoard) const override;
    std::string troopType() const override;
    pieceMask selfPieceMask() const override;
    sideType selfSideMask() const override;
    std::shared_ptr<Piece> clone() const override;
};

class Empty: public Piece {
public:
    explicit Empty(const sideType &type);

    std::vector<std::pair<int, int>> accessible(int x, int y, const Board & currentBoard) const override;
    int getPassableTerrain() const override;
    std::vector<std::pair<int, int>> canSee(int x, int y, const Board & currentBoard) const override;
    std::string troopType() const override;
    pieceMask selfPieceMask() const override;
    sideType selfSideMask() const override;
    std::shared_ptr<Piece> clone() const override;
};

#endif //OOP_PIECE_H
