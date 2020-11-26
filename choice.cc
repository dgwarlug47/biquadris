//
// Created by User on 4/14/2020.
//

#include "choice.h"
bool Choice::choose() {
    if(getState()){
        string action;
        string block = "";
        cout << "type the option you want to choose: blind, force or heavy" << endl;
        cin >> action;
        if (action == "force"){
            cin >> block;
        }
        vector<string> s = {"choice", action, block};
        notifyObservers(s);
    }
    return getState();
}
bool Choice::condition(vector<string>, vector<int> i) {
    return i[0] > 1;
}

Choice::Choice(string myName, string activator, int i, int j): ObserverOfTimeAndActivationTime(myName, activator, i,  j){}