//
// Created by User on 4/18/2020.
//

#include "iblockcontent.h"

void IBlockContent::init(){
    type = 'I';
    shape.clear();
    shape.push_back({3,0});
    shape.push_back({3,1});
    shape.push_back({3,2});
    shape.push_back({3,3});
    updateCorners();
}

IBlockContent::IBlockContent() {
    //TODO this might lead to problems I don't know
    IBlockContent::init();
}