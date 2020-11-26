//
// Created by User on 4/18/2020.
//

#include "sblockcontent.h"

void SBlockContent::init(){
    type = 'S';
    shape.clear();
    shape.push_back({3,0});
    shape.push_back({3,1});
    shape.push_back({2,1});
    shape.push_back({2,2});
    updateCorners();
}

SBlockContent::SBlockContent() {
    SBlockContent::init();
}