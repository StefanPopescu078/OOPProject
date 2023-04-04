//
// Created by Popescu Stefan on Apr 2, 2023.
//

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
    // configuratiile vor fi citite dintr-un fisier de config in viitor (sper)

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
    pieces[0][0] = std::shared_ptr<Empty>(new Empty(sideType::None));
    for(int i = 0; i < GameConsts::boardSideSize; i++)
        for(int j = 0; j < GameConsts::boardSideSize; j++)
            if(i != 0 || j != 0)
                pieces[i][j] = pieces[0][0];
    pieces[0][1] = std::shared_ptr<Marshal>(new Marshal(sideType::Red));
}

Board::~Board() {
    for(int i = 0; i < GameConsts::boardSideSize; i++)
        for(int j = 0; j < GameConsts::boardSideSize; j++)
            pieces[i][j].reset();
}

std::ostream &operator<<(std::ostream &out, const Board &board) {
    for(int i = 0; i < GameConsts::boardSideSize; i++)
        for (int j = 0; j < GameConsts::boardSideSize; j++) {
            // din cate inteleg, e cam hacky sa obtin pointer-ul raw si sa accesez obiectul prin el
            out << "[ " << i << " " << j << " ] : piece - " << *(board.getPiece(i, j).get()) << " ; terrain - " << static_cast<int>(board.getTerrain(i, j)) << "\n";
        }
    return out;
}

Terrain Board::getTerrain(const int &x, const int &y) const {
    assert(x >= 0 && y >= 0 && x < GameConsts::boardSideSize && y < GameConsts::boardSideSize); // debugging

    return cellTypes[x][y];
}

std::shared_ptr<Piece> Board::getPiece(const int &x, const int &y) const {
    assert(x >= 0 && y >= 0 && x < GameConsts::boardSideSize && y < GameConsts::boardSideSize); // debugging

    return std::shared_ptr<Piece>(pieces[x][y]);
}

Board::Board(Board &b1) {
    cellTypes = b1.cellTypes; // se face copierea propriu-zisa a

}
