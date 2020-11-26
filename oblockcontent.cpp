//
// Created by User on 4/18/2020.
//

#include "oblockcontent.h"

void OBlockContent::init(){
    type = 'O';
    shape.clear();
    shape.push_back({3,0});
    shape.push_back({3,1});
    shape.push_back({2,0});
    shape.push_back({2,1});
    updateCorners();
}

OBlockContent::OBlockContent() {
    OBlockContent::init();
}