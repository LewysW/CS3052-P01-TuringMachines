//
// Created by locw on 04/03/19.
//

#ifndef CS3052_P01_TURINGMACHINES_TRANSITION_H
#define CS3052_P01_TURINGMACHINES_TRANSITION_H


#include <iosfwd>
#include <iostream>
#include "state.h"

using namespace std;
class State;

class Transition {
public:
    Transition(char inputSymbol, string nextStateID, char outputSymbol, char direction);

    //Code to overload an operator:
    // https://thispointer.com/using-stdset-with-user-defined-classes/
    bool operator< (const Transition & transObj) const;

    char getInputSymbol() const;

    void setInputSymbol(char inputSymbol);

    const string &getNextStateID() const;

    void setNextStateID(const string &nextStateID);

    char getOutputSymbol() const;

    void setOutputSymbol(char outputSymbol);

    char getDirection() const;

    void setDirection(char direction);

private:
    char inputSymbol;
    string nextStateID;
    char outputSymbol;
    char direction;
};


#endif //CS3052_P01_TURINGMACHINES_TRANSITION_H
