//
// Created by locw on 04/03/19.
//

#ifndef CS3052_P01_TURINGMACHINES_TRANSITION_H
#define CS3052_P01_TURINGMACHINES_TRANSITION_H


#include <iosfwd>
#include <iostream>

using namespace std;

class Transition {
public:
    Transition(char inputSymbol, const string &nextStateID, char outputSymbol, char direction);

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

    bool operator ==(const Transition & obj) const {
        return (inputSymbol == obj.inputSymbol && nextStateID == obj.nextStateID && outputSymbol == obj.outputSymbol && direction == obj.direction);
    }

private:
    char inputSymbol;
    string nextStateID;
    char outputSymbol;
    char direction;
};


#endif //CS3052_P01_TURINGMACHINES_TRANSITION_H
