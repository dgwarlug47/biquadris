//
// Created by User on 4/14/2020.
//

#ifndef BIQUADRIS_TBLOCKCONTENT_H
#define BIQUADRIS_TBLOCKCONTENT_H

#include "blockcontent.h"
class TBlockContent : public BlockContent{
public:
    TBlockContent();
    void init() override;
};

#endif //BIQUADRIS_TBLOCKCONTENT_H