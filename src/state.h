//
// Created by locw on 04/03/19.
//

#ifndef CS3052_P01_TURINGMACHINES_STATE_H
#define CS3052_P01_TURINGMACHINES_STATE_H

#include <string>
#include <unordered_map>
#include "transition.h"

using namespace std;

namespace std
{
    template<>
    struct hash<Transition>
    {
        size_t
        operator()(const Transition & obj) const
        {
            return hash<string>()(obj.getInputSymbol() + obj.getNextStateID() + obj.getOutputSymbol() + obj.getDirection());
        }
    };
}


class State {
private:
    string id;
    unordered_map<char, Transition> transitions;

public:
    State(const string &id, const unordered_map<char, Transition> &transitions);

    const string &getId() const;

    void setId(const string &id);

    const unordered_map<char, Transition> &getTransitions() const;

    bool operator ==(const State & obj) const {
        return (id == obj.id);
    }
};


#endif //CS3052_P01_TURINGMACHINES_STATE_H
