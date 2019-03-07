//
// Created by locw on 04/03/19.
//

#include "tm.h"

void TM::run(char* tmFilePath, char* tapeFilePath) {
    FileParser fileParser;
    fileParser.loadTMFile(tmFilePath, currentState, acceptState, rejectState, alphabet, states);

    if (tapeFilePath != nullptr) {
        fileParser.loadTapeFile(tapeFilePath, tape);
    } else {
        tape.getCells().insert(tape.getCells().begin(), '_');
    }

    int numSteps = -1;
    char currentSymbol;

    while (currentState != acceptState && currentState != rejectState) {
        numSteps++;
        currentSymbol = tape.getCells().at(head);
        delta(currentState, currentSymbol);
    }

    if (currentState == acceptState) {
        cout << "accept" << endl;
        cout << numSteps << endl;
        printTape(tape);
        exit(ACCEPTED);

    } else if (currentState == rejectState) {
        cout << "reject" << endl;
        cout << numSteps << endl;
        printTape(tape);
        exit(REJECTED);
    }
}

void TM::delta(string& currentState, char currentSymbol) {
    Transition t;
    //cout << "CURRENT SYMBOL UNDER HEAD: " << currentSymbol << endl;
    //cout << "TAPE: ";
    //printTape(tape);
    //cout << endl;
    //Checks if transition exists for state and input symbol
    if (states[currentState].getTransitions().find(currentSymbol) != states[currentState].getTransitions().end()) {
        t = states[currentState].getTransitions()[currentSymbol];
    //Otherwise rejecting transition implied
    } else {
        t = Transition(currentSymbol, rejectState, currentSymbol, 'L');
    }

    //cout << "CURRENT STATE: " << currentState << " TRANSITION - INPUT SYMBOL: " << t.getInputSymbol() << " NEXT STATE: " << t.getNextStateID() << " OUTPUT SYMBOL: " << t.getOutputSymbol() << " DIRECTION: " << t.getDirection() << endl;

    //Changes current state to next state
    currentState = t.getNextStateID();

    //Writes symbol to location of head on tape
    tape.getCells()[head] = t.getOutputSymbol();

    if (t.getDirection() == 'L' && head > 0) {
        head--;
    } else if (t.getDirection() == 'R') {
        head++;
    }

}

void TM::printTape(Tape& tape) {
    long tapeOutput = -1;

    //Iterates from end of tape to beginning, recording characters to print
    for (long cell = tape.getCells().size() - 1; cell >= 0; cell--) {
        if (tape.getCells()[cell] != '_') {
            tapeOutput = cell;
            break;
        }
    }

    if (tapeOutput != EMPTY_TAPE) {
        for (long cell = 0; cell <= tapeOutput; cell++) {
            cout << tape.getCells()[cell];
        }
    } else {
        cout << '_';
    }

    cout << endl;
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
