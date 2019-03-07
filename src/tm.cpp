//
// Created by locw on 04/03/19.
//

#include "tm.h"

void TM::run(char* tmFilePath, char* tapeFilePath) {
    FileParser fileParser;
    fileParser.loadTMFile(tmFilePath, currentState, acceptState, rejectState, alphabet, states);

    if (tapeFilePath != NULL) {
        fileParser.loadTapeFile(tapeFilePath, alphabet, tape);
    }

    //TODO - simulate TM using transition function delta
    char currentSymbol;
    while (currentState != acceptState && currentState != rejectState) {
        currentSymbol = tape.getCells().at(head);
        delta(currentState, currentSymbol);
    }

    if (currentState == acceptState) {
        cout << "accept" << endl;
    } else if (currentState == rejectState) {
        cout << "reject" << endl;
    }
}

void TM::delta(string& currentState, char currentSymbol) {
    Transition t = states[currentState].getTransitions()[currentSymbol];
    currentState = t.getNextStateID();
    cout << t.getOutputSymbol();

    if (t.getDirection() == 'L' && head > 0) {
        head--;
    } else if (t.getDirection() == 'R') {
        head++;
    }
}

const Alphabet &TM::getAlphabet() const {
    return alphabet;
}

void TM::setAlphabet(const Alphabet &alphabet) {
    TM::alphabet = alphabet;
}

const unordered_map<string, State> &TM::getStates() const {
    return states;
}

void TM::setStates(const unordered_map<string, State> &states) {
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
