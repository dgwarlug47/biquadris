//
// Created by User on 4/18/2020.
//

#include "rightoperation.h"

int RightOperation::transformationOnRow(vector<int> i, BlockContent& b){
    return i[0];
}
int RightOperation::transformationOnColumn(vector<int> i, BlockContent& b){
    return i[1] + 1;
}