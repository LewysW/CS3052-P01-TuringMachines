//
// Created by locw on 04/03/19.
//

#include "tm.h"
#include "transition.h"
#include "state.h"

void TM::run() {
    Transition t1('a', "q1", 'b', 'R');
    Transition t2('a', "q1", 'b', 'R');
    Transition t3('a', "q2", 'b', 'R');

    unordered_set<Transition> transitions;

    transitions.insert(t1);
    transitions.insert(t2);
    transitions.insert(t3);

    if (transitions.find(t1) != transitions.end() && transitions.find(t2) == transitions.end() && transitions.find(t3) != transitions.end()) {
        cout << "t1 and t3 added, t2 not added" << endl;
    }
    cout << "Running Turing Machine!" << endl;
}

const Alphabet &TM::getAlphabet() const {
    return alphabet;
}

void TM::setAlphabet(const Alphabet &alphabet) {
    TM::alphabet = alphabet;
}
