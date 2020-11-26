//
// Created by User on 4/14/2020.
//
#include "subject.h"
void Subject::attach(Observer *o) {
    observers.emplace_back(o);
}

void Subject::notifyObservers(vector<string> s, vector<int> i) {
    for (auto &ob : observers) ob->notify(s, i);
}