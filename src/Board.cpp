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
    pieces[0][0] = std::make_shared<Empty>(sideType::None);
    for(int i = 0; i < GameConsts::boardSideSize; i++)
        for(int j = 0; j < GameConsts::boardSideSize; j++)
            if(i != 0 || j != 0)
                pieces[i][j] = pieces[0][0];
    pieces[0][1] = std::make_shared<Marshal>(sideType::Red);
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
            out << "[ " << i << " " << j << " ] : piece - " << (*board.pieces[i][j]) << " ; terrain - " << static_cast<int>(board.getTerrain(i, j)) << "\n";
        }
    return out;
}

Terrain Board::getTerrain(int x, int y) const {
    if(!(x >= 0 && y >= 0 && x < GameConsts::boardSideSize && y < GameConsts::boardSideSize)) // debugging
        throw "Invalid coordinates in Board::getTerrain";
    return cellTypes[x][y];
}

std::shared_ptr<Piece> Board::getPiece(int x, int y) const {
    if(!(x >= 0 && y >= 0 && x < GameConsts::boardSideSize && y < GameConsts::boardSideSize)) // debugging
        throw "Invalid coordinates in Board::getPiece";
    return pieces[x][y];
}

Board::Board(const Board &b1) {
    cellTypes = b1.cellTypes; // se face copierea propriu-zisa a tipurilor de celule
//    std::map<Piece*, std::shared_ptr<Piece>> usedPointers; // pentru o tabela avem cate o piesa de fiecare tip, fiecare board cu tabela ei
//    for(int i = 0; i < GameConsts::boardSideSize; i++) // fiecare pozitie din tabela e un pointer catre un obiect, (fiecare piesa ar trebui sa fie singleton per tabela?)
//        for(int j = 0; j < GameConsts::boardSideSize; j++){ // se va modifica ulterior cu clone
//            if(usedPointers.find(b1.pieces[i][j].get()) == usedPointers.end()){
//                usedPointers[b1.pieces[i][j].get()] = pieces[i][j] = std::make_shared<Piece>(*(b1.pieces[i][j].get())); ///se apeleaza copy constructor-ul pentru piesa
//            }
//            else{
//                pieces[i][j] = usedPointers[b1.pieces[i][j].get()];
//            }
//        }
}

Board &Board::operator=(const Board &b1) {
    cellTypes = b1.cellTypes;
    return *this;
}
