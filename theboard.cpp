//
// Created by User on 4/15/2020.
//

#include "theboard.h"

vector<vector<Celula>> TheBoard::getTheBoardState() {
    return theBoard;
}

void TheBoard::setCelula(int r, int c, char d) {
    theBoard[r][c].fill(d);
}

void TheBoard::unsetCelula(int r, int c){
    theBoard[r][c].unFill();
}

TheBoard::TheBoard(){
    for (int i = 0; i < 18; i ++){
        vector<Celula> v;
        for (int j =0; j < 11; j++){
            v.push_back(Celula());
        }
        theBoard.push_back(v);
    }
}
