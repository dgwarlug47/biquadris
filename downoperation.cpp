//
// Created by User on 4/18/2020.
//

#include "downoperation.h"

int DownOperation::transformationOnRow(vector<int> i, BlockContent& b){
    return i[0] + 1;
}
int DownOperation::transformationOnColumn(vector<int> i, BlockContent& b){
    return i[1];
}