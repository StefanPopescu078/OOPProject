//
// Created by Popescu Stefan on Apr 2, 2023.
//

#ifndef OOP_PIECE_H
#define OOP_PIECE_H


class Board;
enum class Terrain;

#include "Board.h"
#include <vector>
#include <ostream>
#include <string>

enum class sideType{
    Red,
    Blue,
    None
};

class Piece{
private:
    sideType side;
    sf::Sprite texture;
public:
    Piece();
    explicit Piece(const sideType &);
    Piece(const Piece & p1);
    virtual ~Piece(); // are clase derivate
    virtual std::vector<std::pair<int, int>> accessible(int x, int y) const = 0;
    virtual std::vector<Terrain> getPassableTerrain() const = 0;
    virtual std::vector<std::pair<int, int>> canSee(int x, int y, const Board & currentBoard) const = 0;
    virtual std::string troopType() const = 0;
    std::string getSide() const;
    std::string setSide(const sideType & sd);
    friend std::ostream & operator << (std::ostream & out, const Piece & p1);
};

class Flag : public Piece {
public:
    explicit Flag(const sideType &type);

    std::vector<std::pair<int, int>> accessible(int x, int y) const override;
    std::vector<Terrain> getPassableTerrain() const override;
    std::vector<std::pair<int, int>> canSee(int x, int y, const Board & currentBoard) const override;
    std::string troopType() const override;
};

class Bomb : public Piece {
public:
    explicit Bomb(const sideType &type);

    std::vector<std::pair<int, int>> accessible(int x, int y) const override;
    std::vector<Terrain> getPassableTerrain() const override;
    std::vector<std::pair<int, int>> canSee(int x, int y, const Board & currentBoard) const override;
    std::string troopType() const override;
};

class Spy : public Piece {
public:
    explicit Spy(const sideType &type);

    std::vector<std::pair<int, int>> accessible(int x, int y) const override;
    std::vector<Terrain> getPassableTerrain() const override;
    std::vector<std::pair<int, int>> canSee(int x, int y, const Board & currentBoard) const override;
    std::string troopType() const override;
};

class Scout : public Piece {
public:
    explicit Scout(const sideType &type);

    std::vector<std::pair<int, int>> accessible(int x, int y) const override;
    std::vector<Terrain> getPassableTerrain() const override;
    std::vector<std::pair<int, int>> canSee(int x, int y, const Board & currentBoard) const override;
    std::string troopType() const override;
};

class Miner : public Piece {
public:
    explicit Miner(const sideType &type);

    std::vector<std::pair<int, int>> accessible(int x, int y) const override;
    std::vector<Terrain> getPassableTerrain() const override;
    std::vector<std::pair<int, int>> canSee(int x, int y, const Board & currentBoard) const override;
    std::string troopType() const override;
};

class Sergeant : public Piece {
public:
    explicit Sergeant(const sideType &type);

    std::vector<std::pair<int, int>> accessible(int x, int y) const override;
    std::vector<Terrain> getPassableTerrain() const override;
    std::vector<std::pair<int, int>> canSee(int x, int y, const Board & currentBoard) const override;
    std::string troopType() const override;
};

class Lieutenant : public Piece {
public:
    explicit Lieutenant(const sideType &type);

    std::vector<std::pair<int, int>> accessible(int x, int y) const override;
    std::vector<Terrain> getPassableTerrain() const override;
    std::vector<std::pair<int, int>> canSee(int x, int y, const Board & currentBoard) const override;
    std::string troopType() const override;
};

class Captain : public Piece {
public:
    explicit Captain(const sideType &type);

    std::vector<std::pair<int, int>> accessible(int x, int y) const override;
    std::vector<Terrain> getPassableTerrain() const override;
    std::vector<std::pair<int, int>> canSee(int x, int y, const Board & currentBoard) const override;
    std::string troopType() const override;
};

class Major : public Piece {
public:
    explicit Major(const sideType &type);

    std::vector<std::pair<int, int>> accessible(int x, int y) const override;
    std::vector<Terrain> getPassableTerrain() const override;
    std::vector<std::pair<int, int>> canSee(int x, int y, const Board & currentBoard) const override;
    std::string troopType() const override;
};

class Colonel : public Piece {
public:
    explicit Colonel(const sideType &type);

    std::vector<std::pair<int, int>> accessible(int x, int y) const override;
    std::vector<Terrain> getPassableTerrain() const override;
    std::vector<std::pair<int, int>> canSee(int x, int y, const Board & currentBoard) const override;
    std::string troopType() const override;
};

class General : public Piece {
public:
    explicit General(const sideType &type);

    std::vector<std::pair<int, int>> accessible(int x, int y) const override;
    std::vector<Terrain> getPassableTerrain() const override;
    std::vector<std::pair<int, int>> canSee(int x, int y, const Board & currentBoard) const override;
    std::string troopType() const override;
};

class Marshal: public Piece {
public:
    explicit Marshal(const sideType &type);

    std::vector<std::pair<int, int>> accessible(int x, int y) const override;
    std::vector<Terrain> getPassableTerrain() const override;
    std::vector<std::pair<int, int>> canSee(int x, int y, const Board & currentBoard) const override;
    std::string troopType() const override;
};

class Empty: public Piece {
public:
    explicit Empty(const sideType &type);

    std::vector<std::pair<int, int>> accessible(int x, int y) const override;
    std::vector<Terrain> getPassableTerrain() const override;
    std::vector<std::pair<int, int>> canSee(int x, int y, const Board & currentBoard) const override;
    std::string troopType() const override;
};

#endif //OOP_PIECE_H
