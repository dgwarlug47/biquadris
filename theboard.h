//
// Created by User on 4/14/2020.
//

#ifndef BIQUADRIS_THEBOARD_H
#define BIQUADRIS_THEBOARD_H

class Board;

#include <vector>
#include "cell.h"
#include "subject.h"
using namespace std;
class TheBoard{
    vector<vector<Celula>> theBoard;
public:
    int id;
    TheBoard();
    vector<vector<Celula>> getTheBoardState();
    void setCelula(int, int, char);
    void unsetCelula(int, int);
    friend class Board;
};
#endif //BIQUADRIS_THEBOARD_H
