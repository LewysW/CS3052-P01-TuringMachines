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

const unordered_set<Transition> &State::getTransitions() const {
    return transitions;
}

State::State(const string &id, const unordered_set<Transition> &transitions) : id(id), transitions(transitions) {}
