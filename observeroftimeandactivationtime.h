//
// Created by User on 4/14/2020.
//

#ifndef BIQUADRIS_OBSERVEROFTIMEANDACTIVATIONTIME_H
#define BIQUADRIS_OBSERVEROFTIMEANDACTIVATIONTIME_H

#include "observer.h"
#include <vector>
using namespace std;

class ObserverOfTimeAndActivationTime: public Observer {
    int currentTime = 0;
    // i just put a -1 because if I do not initialize it
    // there will be a memory error
    // and I put a negative number to indicate that it hasn't been chosen yet
    int lastTimeChosen = -1;
    const string myName;
    const string activator;
    int validityDate;
    int expiryDate;
    string extraInfo;
    virtual bool condition(vector<string>, vector<int>);
public:
    void notify(vector <string> s, vector<int> i);
    ObserverOfTimeAndActivationTime(string, string, int, int);
    bool getState();
    string getExtraInfo();
    friend class PlayerInfo;
};
#endif //BIQUADRIS_OBSERVEROFTIMEANDACTIVATIONTIME_H
