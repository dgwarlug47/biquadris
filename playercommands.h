//
// Created by User on 4/14/2020.
//

#ifndef BIQUADRIS_PLAYERCOMMANDS_H
#define BIQUADRIS_PLAYERCOMMANDS_H

#include <string>
#include <sstream>
#include <map>
#include <memory>
using namespace std;
class PlayerCommands{
    map<string,string> prefixesAndFullNames;

public:
    string getCommandNameOnOurInterpretation(string);
    PlayerCommands();
};
#endif //BIQUADRIS_PLAYERCOMMANDS_H
