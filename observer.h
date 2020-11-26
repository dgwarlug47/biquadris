//
// Created by User on 4/14/2020.
//

#ifndef BIQUADRIS_OBSERVER_H
#define BIQUADRIS_OBSERVER_H

#include <string>
#include <vector>
using namespace std;
class Observer {

public:
    virtual ~Observer() = default;

    virtual void notify(vector<string>, vector<int> = {}) = 0;
};

#endif //BIQUADRIS_OBSERVER_H
