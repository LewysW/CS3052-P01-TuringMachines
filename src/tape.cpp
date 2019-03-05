//
// Created by locw on 04/03/19.
//

#include "tape.h"

const vector<char> &Tape::getCells() const {
    return cells;
}

void Tape::setCells(const vector<char> &cells) {
    Tape::cells = cells;
}
