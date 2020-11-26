//
// Created by User on 4/18/2020.
//

#include "lblockcontent.h"

void LBlockContent::init(){
    type = 'L';
    shape.clear();
    shape.push_back({2,2});
    shape.push_back({3,0});
    shape.push_back({3,1});
    shape.push_back({3,2});
    updateCorners();
}

LBlockContent::LBlockContent() {
    LBlockContent::init();
}