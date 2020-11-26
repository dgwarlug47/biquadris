//
// Created by User on 4/14/2020.
//

#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include <memory>
#include <string>
#include "observer.h"
// DO NOT MODIFY THIS FILE!

using namespace std;

class  Subject{
    vector<Observer *> observers;
public:
    void notifyObservers(vector<string>, vector<int> = {});

    void attach(Observer *);
};
#endif //BIQUADRIS__H