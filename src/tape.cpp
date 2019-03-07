//
// Created by locw on 04/03/19.
//

#include "tape.h"

vector<char> &Tape::getCells(){
    return cells;
}

void Tape::setCells(const vector<char> &cells) {
    Tape::cells = cells;
}
