//
// Created by User on 4/15/2020.
//

#include "blockcontent.h"

char BlockContent::getType() {
    return type;
}
vector<vector<int>> BlockContent::getShape() {
    return shape;
}
vector<int> BlockContent::getCorners(){
    return Corners;
}
void BlockContent::updateCorners() {
    if(shape.empty()){return;}
    int up = shape[0][0];
    int down = shape[0][0];
    int left = shape[0][1];
    int right = shape[0][1];
    for(auto it: shape){
        up = min(it[0], up);
        down = max(it[0], down);
        left = min(it[1], left);
        right = max(it[1], right);
    }
    Corners.clear();
    Corners.push_back(left);
    Corners.push_back(right);
    Corners.push_back(up);
    Corners.push_back(down);
}