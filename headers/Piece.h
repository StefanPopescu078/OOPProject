//
// Created by Popescu Stefan on Apr 2, 2023.
//

#ifndef OOP_PIECE_H
#define OOP_PIECE_H


class Board;
enum class Terrain;

#include "Board.h"
#include <vector>

class Piece {
public:
    virtual ~Piece() {}
    virtual std::vector<std::pair<int, int>> accessible(int x, int y) const = 0;
    virtual std::vector<Terrain> getPassableTerrain() const = 0;
    virtual std::vector<std::pair<int, int>> canSee(int x, int y, const Board & currentBoard) const = 0;
};

class Flag : public Piece {
public:
    std::vector<std::pair<int, int>> accessible(int x, int y) const override;
    std::vector<Terrain> getPassableTerrain() const override;
    virtual std::vector<std::pair<int, int>> canSee(int x, int y, const Board & currentBoard) const override;
};

class Bomb : public Piece {
public:
    std::vector<std::pair<int, int>> accessible(int x, int y) const override;
    std::vector<Terrain> getPassableTerrain() const override;
    virtual std::vector<std::pair<int, int>> canSee(int x, int y, const Board & currentBoard) const override;
};

class Spy : public Piece {
public:
    std::vector<std::pair<int, int>> accessible(int x, int y) const override;
    std::vector<Terrain> getPassableTerrain() const override;
    virtual std::vector<std::pair<int, int>> canSee(int x, int y, const Board & currentBoard) const override;
};

class Scout : public Piece {
public:
    std::vector<std::pair<int, int>> accessible(int x, int y) const override;
    std::vector<Terrain> getPassableTerrain() const override;
    virtual std::vector<std::pair<int, int>> canSee(int x, int y, const Board & currentBoard) const override;
};

class Miner : public Piece {
public:
    std::vector<std::pair<int, int>> accessible(int x, int y) const override;
    std::vector<Terrain> getPassableTerrain() const override;
    virtual std::vector<std::pair<int, int>> canSee(int x, int y, const Board & currentBoard) const override;
};

class Sergeant : public Piece {
public:
    std::vector<std::pair<int, int>> accessible(int x, int y) const override;
    std::vector<Terrain> getPassableTerrain() const override;
    virtual std::vector<std::pair<int, int>> canSee(int x, int y, const Board & currentBoard) const override;
};

class Lieutenant : public Piece {
public:
    std::vector<std::pair<int, int>> accessible(int x, int y) const override;
    std::vector<Terrain> getPassableTerrain() const override;
    virtual std::vector<std::pair<int, int>> canSee(int x, int y, const Board & currentBoard) const override;
};

class Captain : public Piece {
public:
    std::vector<std::pair<int, int>> accessible(int x, int y) const override;
    std::vector<Terrain> getPassableTerrain() const override;
    virtual std::vector<std::pair<int, int>> canSee(int x, int y, const Board & currentBoard) const override;
};

class Major : public Piece {
public:
    std::vector<std::pair<int, int>> accessible(int x, int y) const override;
    std::vector<Terrain> getPassableTerrain() const override;
    virtual std::vector<std::pair<int, int>> canSee(int x, int y, const Board & currentBoard) const override;
};

class Colonel : public Piece {
public:
    std::vector<std::pair<int, int>> accessible(int x, int y) const override;
    std::vector<Terrain> getPassableTerrain() const override;
    virtual std::vector<std::pair<int, int>> canSee(int x, int y, const Board & currentBoard) const override;
};

class General : public Piece {
public:
    std::vector<std::pair<int, int>> accessible(int x, int y) const override;
    std::vector<Terrain> getPassableTerrain() const override;
    virtual std::vector<std::pair<int, int>> canSee(int x, int y, const Board & currentBoard) const override;
};

class Marshal: public Piece {
public:
    std::vector<std::pair<int, int>> accessible(int x, int y) const override;
    std::vector<Terrain> getPassableTerrain() const override;
    virtual std::vector<std::pair<int, int>> canSee(int x, int y, const Board & currentBoard) const override;
};

#endif //OOP_PIECE_H
