//
// Created by User on 4/14/2020.
//

#include "board.h"

bool Board::setNewBlock(char c) {
    isThereAnyBlockHere = true;
    for(auto it = interpreterBetweenCharsAndBlocks.begin(); it != interpreterBetweenCharsAndBlocks.end(); it++){
        if(c == it->first){
            blockContent = it->second.get();
            blockContent->init();
        }
    }
    for(auto it: blockContent->getShape()){
        if(theBoard.getTheBoardState()[it[0]][it[1]].isItFilled()){
            return false;
        }
    }
    return true;
}

string Board::stringfy(bool b){
    string ans = "";
    vector<vector<Celula>> boardCopy = theBoard.getTheBoardState();
    for(int row = 0; row < rowSize; row++){
        for(int column = 0; column < columnSize; column++){
            if(boardCopy[row][column].isItFilled()){
                ans +=  boardCopy[row][column].getType();
                continue;
            } else{
                ans += " ";
            }
        }
    }
    if(isThereAnyBlockHere){
        for (auto it : blockContent->getShape()) {
            ans[it[0]*columnSize + it[1]] = blockContent->getType();
        }
    }
    if(b) {
        for(int row = 2; row < 12; row ++) {
            for (int column = 2; column < 9; column++) {
                ans[row*columnSize + column] = '?';
            }
        }
    }
    return ans;
}

void Board::left() {
    LeftOperation().executeTransformation(*blockContent, theBoard);
}

void Board::right() {
    RightOperation().executeTransformation(*blockContent, theBoard);
}

void Board::clockWise() {
    RotateOperation().executeTransformation(*blockContent, theBoard);
}

void Board::counterClockWise() {
    CounterRotateOperation().executeTransformation(*blockContent, theBoard);
}

bool Board::down() {
    return DownOperation().executeTransformation(*blockContent, theBoard);
}

void Board::drop(){
    if(down()){
        drop();
    }
    else{
        addNewBlockToTheBoard();
        clears();
    }
}

void Board::addNewBlockToTheBoard(){
    isThereAnyBlockHere = false;
    for(auto it: blockContent->getShape()){
        theBoard.setCelula(it[0], it[1], blockContent->getType());
    }
}

void Board::clears(){
    bool didWeAlreadyWentThroughTheWholeBoard = false;
    int numberOfRowsCleared = 0;
    while(!didWeAlreadyWentThroughTheWholeBoard) {
        didWeAlreadyWentThroughTheWholeBoard = true;
        int row;
        int column;
        bool needToClear;
        for (row = rowSize - 1; row >= 0; row--) {
            needToClear = true;
            for (column = 0; column < columnSize; column ++) {
                if (!theBoard.getTheBoardState()[row][column].isItFilled()) {
                    needToClear = false;
                    break;
                }
            }
            if (needToClear) {
                didWeAlreadyWentThroughTheWholeBoard = false;
                numberOfRowsCleared ++;
                clearThisRow(row);
                break;
            }
        }
    }
    if(numberOfRowsCleared > 0) {
        vector<string> s{"clear"};
        vector<int> i{numberOfRowsCleared};
        clear.notifyObservers(s, i);
    }
}

void Board::clearThisRow(int rowToBeCleared) {
    for(int column = 0; column < columnSize; column ++){
        theBoard.unsetCelula(rowToBeCleared, column);
    }
    for(int row = rowToBeCleared - 1; row >= 0; row --){
        for (int column = 0; column < columnSize; column++){
            if(theBoard.getTheBoardState()[row][column].isItFilled()) {
                theBoard.setCelula(row + 1, column, theBoard.getTheBoardState()[row][column].getType());
                theBoard.unsetCelula(row, column);
            }
        }
    }
}
bool Board::addBrown(){
    int middle = columnSize/2;
    vector<vector<struct Celula>> boardCopy = theBoard.getTheBoardState();
    for(int row = 0; row < rowSize; row ++){
        if(!boardCopy[row][middle].isItFilled()){
            theBoard.setCelula(row,middle,'*');
            clears();
            return true;
        }
    }
    return false;
}
bool Board::heavy() {
    if(!down()){
        addNewBlockToTheBoard();
        clears();
        return false;
    }
    else{
        return true;
    }
}

vector<int> Board::shapeNotification(const vector<vector<int>> s) {
    vector<int> v;
    v.push_back(id);
    for(auto it: s){
        v.push_back(it[0]);
        v.push_back(it[1]);
    }
}