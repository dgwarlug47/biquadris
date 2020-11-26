//
// Created by User on 4/20/2020.
//

#ifndef BIQUADRIS_LEVEL0BLOCK_H
#define BIQUADRIS_LEVEL0BLOCK_H

#include <fstream>
#include "factoryblock.h"
class Level0Block : public FactoryBlock{
    char restOfCreateNewBlock() override;
};

#endif //BIQUADRIS_LEVEL0BLOCK_H
