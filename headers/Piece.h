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

class Piece{
protected:
    sideType side;
    sf::Texture texture;
    void canSeeHelper(int limV, int limD, int x, int y, const Board & currentBoard, std::vector<std::pair<int, int> > & retVec) const;
    void accessibleHelper(int limV, int limD, int x, int y, const Board & currentBoard, std::vector<std::pair<int, int> > & retVec) const;
public:
    Piece();
    explicit Piece(const sideType &);
    Piece(const Piece & p1);
    virtual ~Piece(); // are clase derivate
    [[maybe_unused]]virtual std::vector<std::pair<int, int>> accessible(int x, int y, const Board & currentBoard) const = 0;
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
    virtual void loadTexture(const std::string & filePref) = 0;
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
    void loadTexture(const std::string & filePref) override;
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
    void loadTexture(const std::string & filePref) override;
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
    void loadTexture(const std::string & filePref) override;
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
    void loadTexture(const std::string & filePref) override;
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
    void loadTexture(const std::string & filePref) override;
};

class Sergeant : public Piece {
public:
    explicit Sergeant(const sideType &type);

    std::vector<std::pair<int, int>> accessible(int x, int y, const Board & currentBoard) const override;
    int getPassableTerrain() const override;
    std::vector<std::pair<int, int>> canSee(int x, int y, const Board & currentBoard) const override;
    std::string troopType() const override;
    pieceMask selfPieceMask() const override;
    sideType selfSideMask() const override;
    std::shared_ptr<Piece> clone() const override;
    void loadTexture(const std::string & filePref) override;
};

class Lieutenant : public Piece {
public:
    explicit Lieutenant(const sideType &type);

    std::vector<std::pair<int, int>> accessible(int x, int y, const Board & currentBoard) const override;
    int getPassableTerrain() const override;
    std::vector<std::pair<int, int>> canSee(int x, int y, const Board & currentBoard) const override;
    std::string troopType() const override;
    pieceMask selfPieceMask() const override;
    sideType selfSideMask() const override;
    std::shared_ptr<Piece> clone() const override;
    void loadTexture(const std::string & filePref) override;
};

class Captain : public Piece {
public:
    explicit Captain(const sideType &type);

    std::vector<std::pair<int, int>> accessible(int x, int y, const Board & currentBoard) const override;
    int getPassableTerrain() const override;
    std::vector<std::pair<int, int>> canSee(int x, int y, const Board & currentBoard) const override;
    std::string troopType() const override;
    pieceMask selfPieceMask() const override;
    sideType selfSideMask() const override;
    std::shared_ptr<Piece> clone() const override;
    void loadTexture(const std::string & filePref) override;
};

class Major : public Piece {
public:
    explicit Major(const sideType &type);

    std::vector<std::pair<int, int>> accessible(int x, int y, const Board & currentBoard) const override;
    int getPassableTerrain() const override;
    std::vector<std::pair<int, int>> canSee(int x, int y, const Board & currentBoard) const override;
    std::string troopType() const override;
    pieceMask selfPieceMask() const override;
    sideType selfSideMask() const override;
    std::shared_ptr<Piece> clone() const override;
    void loadTexture(const std::string & filePref) override;
};

class Colonel : public Piece {
public:
    explicit Colonel(const sideType &type);

    std::vector<std::pair<int, int>> accessible(int x, int y, const Board & currentBoard) const override;
    int getPassableTerrain() const override;
    std::vector<std::pair<int, int>> canSee(int x, int y, const Board & currentBoard) const override;
    std::string troopType() const override;
    pieceMask selfPieceMask() const override;
    sideType selfSideMask() const override;
    std::shared_ptr<Piece> clone() const override;
    void loadTexture(const std::string & filePref) override;
};

class General : public Piece {
public:
    explicit General(const sideType &type);

    std::vector<std::pair<int, int>> accessible(int x, int y, const Board & currentBoard) const override;
    int getPassableTerrain() const override;
    std::vector<std::pair<int, int>> canSee(int x, int y, const Board & currentBoard) const override;
    std::string troopType() const override;
    pieceMask selfPieceMask() const override;
    sideType selfSideMask() const override;
    std::shared_ptr<Piece> clone() const override;
    void loadTexture(const std::string & filePref) override;
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
    void loadTexture(const std::string & filePref) override;
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
    void loadTexture(const std::string & filePref) override;
};

#endif //OOP_PIECE_H
