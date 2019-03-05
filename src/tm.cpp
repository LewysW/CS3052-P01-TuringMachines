//
// Created by locw on 04/03/19.
//

#include "tm.h"
#include "transition.h"
#include "state.h"

void TM::run() {

}

void TM::delta() {
    char currentSymbol = tape.getCells().at(head);
    
}

const Alphabet &TM::getAlphabet() const {
    return alphabet;
}

void TM::setAlphabet(const Alphabet &alphabet) {
    TM::alphabet = alphabet;
}

const unordered_set<State> &TM::getStates() const {
    return states;
}

void TM::setStates(const unordered_set<State> &states) {
    TM::states = states;
}

const string &TM::getRejectState() const {
    return rejectState;
}

void TM::setRejectState(const string &rejectState) {
    TM::rejectState = rejectState;
}

const string &TM::getAcceptState() const {
    return acceptState;
}

void TM::setAcceptState(const string &acceptState) {
    TM::acceptState = acceptState;
}

const string &TM::getCurrentState() const {
    return currentState;
}

void TM::setCurrentState(const string &currentState) {
    TM::currentState = currentState;
}
