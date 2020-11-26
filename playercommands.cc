//
// Created by User on 4/14/2020.
//

#include "playercommands.h"
//TODO this whole class needs to be updated
string PlayerCommands::getCommandNameOnOurInterpretation(string commandOnTheirInterpretation) {
    string commandOnOurInterpretation;
    for(auto it : prefixesAndFullNames){
        if(commandOnTheirInterpretation.rfind(it.second, 0) == 0){
            return it.first;
        }
    }
    //if did not find anything
    return "didNotFindAnyThing";
}

PlayerCommands::PlayerCommands(){
    prefixesAndFullNames["left"] = "lef";
    prefixesAndFullNames["right"] = "ri";
    prefixesAndFullNames["drop"] = "dr";
    prefixesAndFullNames["down"] = "do";
    prefixesAndFullNames["levelup"] = "levelu";
    prefixesAndFullNames["leveldown"] = "leveld";
    prefixesAndFullNames["I"] = "I";
    prefixesAndFullNames["J"] = "J";
    prefixesAndFullNames["S"] = "S";
    prefixesAndFullNames["Z"] = "Z";
    prefixesAndFullNames["O"] = "O";
    prefixesAndFullNames["T"] = "T";
    prefixesAndFullNames["L"] = "L";
    prefixesAndFullNames["clockwise"] = "cl";
    prefixesAndFullNames["counterclockwise"] = "co";
    prefixesAndFullNames["norandom"] = "n";
    prefixesAndFullNames["sequence"] = "s";
    prefixesAndFullNames["restart"] = "re";
}