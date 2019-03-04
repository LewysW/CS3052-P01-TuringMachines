//
// Created by locw on 04/03/19.
//

#include "transition.h"

Transition::Transition(char inputSymbol, string nextState, char outputSymbol, char direction) : inputSymbol(
        inputSymbol), State(nextState), outputSymbol(outputSymbol), direction(direction) {}

//Code to overload an operator:
// https://thispointer.com/using-stdset-with-user-defined-classes/
bool operator <(const Transition & transObj) const {
    std::string rightStr = 	transObj.getInputSymbol() + transObj.getOutputSymbol() + transObj.getDirection() + transObj.getNextStateID();
    std::string leftStr = 	this->getInputSymbol() + this->getOutputSymbol() + this->getDirection() + this->getNextStateID();
    return (leftStr < rightStr);
}

char Transition::getInputSymbol() const {
    return inputSymbol;
}

void Transition::setInputSymbol(char inputSymbol) {
    Transition::inputSymbol = inputSymbol;
}

char Transition::getOutputSymbol() const {
    return outputSymbol;
}

void Transition::setOutputSymbol(char outputSymbol) {
    Transition::outputSymbol = outputSymbol;
}

char Transition::getDirection() const {
    return direction;
}

void Transition::setDirection(char direction) {
    Transition::direction = direction;
}

const string &Transition::getNextStateID() const {
    return nextStateID;
}

void Transition::setNextStateID(const string &nextStateID) {
    Transition::nextStateID = nextStateID;
}
