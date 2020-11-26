//
// Created by User on 4/18/2020.
//

#include "zblockcontent.h"

void ZBlockContent::init(){
    type = 'Z';
    shape.clear();
    shape.push_back({2,0});
    shape.push_back({2,1});
    shape.push_back({3,1});
    shape.push_back({3,2});
    updateCorners();
}

ZBlockContent::ZBlockContent() {
    ZBlockContent::init();
}