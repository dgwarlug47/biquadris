//
// Created by User on 4/15/2020.
//

#include "cell.h"

void Celula::fill(char c){
    filled = true;
    type = c;
}

void Celula::unFill(){
    filled = false;
    type = ' ';
}

bool Celula::isItFilled(){
    return filled;
}

char Celula::getType() {
    return type;
}