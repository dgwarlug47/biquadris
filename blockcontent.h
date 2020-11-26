//
// Created by User on 4/14/2020.
//

#ifndef BIQUADRIS_BLOCKCONTENT_H
#define BIQUADRIS_BLOCKCONTENT_H

#include <vector>
class BlockOperation;
using namespace std;
class BlockContent {

protected:
    char type;
    vector<vector<int>> shape;
    vector<int> Corners;
    void updateCorners();


public:
    virtual void init() = 0;
    char getType();
    vector<vector<int>>  getShape();
    // the method above just returns a pair, thus the vector always has size equal to one
    // but if I try to make the function return a pair, it just gives me a compiler error
    vector<int> getCorners();
    friend BlockOperation;
};

#endif //BIQUADRIS_BLOCKCONTENT_H