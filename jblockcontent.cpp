//
// Created by User on 4/18/2020.
//

#include "jblockcontent.h"

void JBlockContent::init(){
    type = 'J';
    shape.clear();
    shape.push_back({2,0});
    shape.push_back({3,0});
    shape.push_back({3,1});
    shape.push_back({3,2});
    updateCorners();
}

JBlockContent::JBlockContent() {
    JBlockContent::init();
}