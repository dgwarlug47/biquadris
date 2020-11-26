//
// Created by User on 4/14/2020.
//

#ifndef BIQUADRIS_CHOICE_H
#define BIQUADRIS_CHOICE_H

#include "subject.h"
#include <iostream>
#include "observeroftimeandactivationtime.h"
class Choice : public ObserverOfTimeAndActivationTime, public Subject{
    bool condition(vector<string>, vector<int>) override;
public:
    bool choose();
    Choice(string, string, int, int);
};
#endif //BIQUADRIS_CHOICE_H
