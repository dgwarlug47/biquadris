//
// Created by User on 4/14/2020.
//
#include "tblockcontent.h"

void TBlockContent::init(){
    type = 'T';
    shape.clear();
    shape.push_back({3,1});
    shape.push_back({2,0});
    shape.push_back({2,1});
    shape.push_back({2,2});
    updateCorners();
}

TBlockContent::TBlockContent() {
    TBlockContent::init();
}