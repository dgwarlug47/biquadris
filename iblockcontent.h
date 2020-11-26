//
// Created by User on 4/18/2020.
//

#ifndef BIQUADRIS_IBLOCKCONTENT_H
#define BIQUADRIS_IBLOCKCONTENT_H

#include "blockcontent.h"
class IBlockContent :public BlockContent{
public:
    void init() override;
    IBlockContent();
};


#endif //BIQUADRIS_IBLOCKCONTENT_H
