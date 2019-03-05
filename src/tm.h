//
// Created by locw on 04/03/19.
//

#ifndef CS3052_P01_TURINGMACHINES_TM_H
#define CS3052_P01_TURINGMACHINES_TM_H

#include <iostream>
#include "alphabet.h"
#include "state.h"

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
    void run();

    const Alphabet &getAlphabet() const;
    void setAlphabet(const Alphabet &alphabet);

private:
    Alphabet alphabet;
    unordered_set<State> states;
    string rejectState;
    string acceptState;
    string currentState;
public:
    const unordered_set<State> &getStates() const;

    void setStates(const unordered_set<State> &states);

    const string &getRejectState() const;

    void setRejectState(const string &rejectState);

    const string &getAcceptState() const;

    void setAcceptState(const string &acceptState);

    const string &getCurrentState() const;

    void setCurrentState(const string &currentState);
};


#endif //CS3052_P01_TURINGMACHINES_TM_H
