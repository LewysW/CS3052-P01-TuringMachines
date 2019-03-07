//
// Created by locw on 04/03/19.
//

#include "state.h"

const string &State::getId() const {
    return id;
}

void State::setId(const string &id) {
    State::id = id;
}

unordered_map<char, Transition> &State::getTransitions() {
    return transitions;
}

void State::setTransitions(const unordered_map<char, Transition> &transitions) {
    State::transitions = transitions;
}

State::State(const string &id) : id(id) {}
