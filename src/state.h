//
// Created by locw on 04/03/19.
//

#ifndef CS3052_P01_TURINGMACHINES_STATE_H
#define CS3052_P01_TURINGMACHINES_STATE_H

#include <string>
#include <unordered_map>
#include <ruby/intern.h>
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
            string s;
            s += obj.getInputSymbol();
            return hash<string>()(s);
        }
    };
}


class State {
private:
    string id;
    unordered_map<char, Transition> transitions;

public:

    State() = default;

    explicit State(const string &id);

    const string &getId() const;

    void setId(const string &id);

    const unordered_map<char, Transition> &getTransitions() const;

    void setTransitions(const unordered_map<char, Transition> &transitions);

    bool operator ==(const State & obj) const {
        return (id == obj.id);
    }
};


#endif //CS3052_P01_TURINGMACHINES_STATE_H
