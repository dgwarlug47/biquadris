//
// Created by User on 4/15/2020.
//

#ifndef BIQUADRIS_CELL_H
#define BIQUADRIS_CELL_H


class Celula {
    bool filled = false;
    char type;

public:
    void fill(char);
    void unFill();
    bool isItFilled();
    char getType();

};


#endif //BIQUADRIS_CELL_H
