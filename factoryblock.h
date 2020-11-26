//
// Created by User on 4/14/2020.
//

#ifndef BIQUADRIS_FACTORYBLOCK_H
#define BIQUADRIS_FACTORYBLOCK_H

#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <string>
#include <fstream>

using namespace std;
class FactoryBlock {
public:
    bool isThereAnySeed = false;
    int seed;
    char createNewBlock();
    char virtual restOfCreateNewBlock() = 0;
    // these three member functions should only be used in the Level0Block only
    void setFile(string);
    string filename;
    ifstream fileInput;
};

#endif //BIQUADRIS_FACTORYBLOCK_H