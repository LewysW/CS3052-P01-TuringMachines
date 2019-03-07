//
// Created by locw on 04/03/19.
//

#ifndef CS3052_P01_TURINGMACHINES_TM_H
#define CS3052_P01_TURINGMACHINES_TM_H

#define TM_FILE_PATH 1
#define TAPE_FILE_PATH 2
#define ACCEPTED 0
#define REJECTED 1
#define EMPTY_TAPE -1

#include <iostream>
#include "alphabet.h"
#include "state.h"
#include "tape.h"
#include "transition.h"
#include "state.h"
#include "fileParser.h"
#include <stack>

using namespace std;

namespace std
{
    template<>
    struct hash<State>
    {
        size_t
        operator()(const State & obj) const
        {
            return hash<string>()(obj.getId());
        }
    };
}

class TM {
public:
    void run(char* tmFilePath, char* tapeFilePath);

    const Alphabet &getAlphabet() const;
    void setAlphabet(const Alphabet &alphabet);

private:
    //Σ
    Alphabet alphabet;
    //Γ
    Tape tape;
    //Q
    unordered_map<string, State> states;
    //qr
    string rejectState;
    //qa
    string acceptState;
    //initially q0
    string currentState;
    //Head
    unsigned long long head = 0;
public:
    void delta(string& currentState, char currentSymbol);

    void printTape(Tape& tape);

    const unordered_map<string, State> &getStates() const;

    void setStates(const unordered_map<string, State> &states);

    const string &getRejectState() const;

    void setRejectState(const string &rejectState);

    const string &getAcceptState() const;

    void setAcceptState(const string &acceptState);

    const string &getCurrentState() const;

    void setCurrentState(const string &currentState);
};


#endif //CS3052_P01_TURINGMACHINES_TM_H
