//
// Created by locw on 04/03/19.
//

#include "transition.h"

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

Transition::Transition() = default;

Transition::Transition(char inputSymbol, const string &nextStateID, char outputSymbol, char direction) : inputSymbol(
        inputSymbol), nextStateID(nextStateID), outputSymbol(outputSymbol), direction(direction) {}
