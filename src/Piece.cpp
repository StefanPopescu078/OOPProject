//
// Created by Popescu Stefan on Apr 2, 2023.
//

#include "../headers/Piece.h"

std::vector<Terrain> Flag::getPassableTerrain() const {
    return {Terrain::PLAINS};
}

std::vector<Terrain> Bomb::getPassableTerrain() const {
    return {Terrain::PLAINS};
}

std::vector<Terrain> Spy::getPassableTerrain() const {
    return {Terrain::PLAINS, Terrain::FOREST, Terrain::HILL, Terrain::CRATER};
}

std::vector<Terrain> Scout::getPassableTerrain() const {
    return {Terrain::PLAINS, Terrain::LAKE, Terrain::HILL, Terrain::CRATER};
}

std::vector<Terrain> Miner::getPassableTerrain() const {
    return {Terrain::PLAINS, Terrain::LAKE, Terrain::HILL, Terrain::CRATER};
}

std::vector<Terrain> Sergeant::getPassableTerrain() const {
    return {Terrain::PLAINS, Terrain::HILL, Terrain::CRATER};
}

std::vector<Terrain> Lieutenant::getPassableTerrain() const {
    return {Terrain::PLAINS, Terrain::HILL, Terrain::CRATER};
}

std::vector<Terrain> Captain::getPassableTerrain() const {
    return {Terrain::PLAINS, Terrain::HILL};
}

std::vector<Terrain> Major::getPassableTerrain() const {
    return {Terrain::PLAINS, Terrain::HILL};
}

std::vector<Terrain> Colonel::getPassableTerrain() const {
    return {Terrain::PLAINS, Terrain::HILL};
}

std::vector<Terrain> General::getPassableTerrain() const {
    return {Terrain::PLAINS};
}

std::vector<Terrain> Marshal::getPassableTerrain() const {
    return {Terrain::PLAINS};
}