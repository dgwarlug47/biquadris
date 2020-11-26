//
// Created by User on 4/14/2020.
//
//
// Created by User on 4/14/2020.
//
#include "observeroftimeandactivationtime.h"
void ObserverOfTimeAndActivationTime::notify(vector<string> s, vector<int> i) {
    if(s[0].find("endOfRound") != string::npos){
        currentTime = i[0];
    }else if (s[0].find(activator) != string::npos) {
        if (condition(s,i)) {
            lastTimeChosen = currentTime;
            if(s.size() > 1) {
                extraInfo = s[2];
            }
        }
    }
}
ObserverOfTimeAndActivationTime::ObserverOfTimeAndActivationTime(string myName, string activator, int validityDate, int expiryDate): myName{myName}, activator{activator}, validityDate{validityDate}, expiryDate{expiryDate}{}
bool ObserverOfTimeAndActivationTime::getState(){
    if(lastTimeChosen == -1){
        return false;
    }
    if (expiryDate > currentTime - lastTimeChosen and currentTime - lastTimeChosen >= validityDate){
        return true;
    }
    else{
        return false;
    }
}
string ObserverOfTimeAndActivationTime::getExtraInfo() {
    return extraInfo;
}

bool ObserverOfTimeAndActivationTime::condition(vector<string> s, vector<int>){
    return s.size() == 1 or  s[1] == myName;
}