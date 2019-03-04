//
// Created by locw on 04/03/19.
//

#include "alphabet.h"

bool Alphabet::contains(char c) {
    return !(charSet.find(c) == charSet.end());
}

int Alphabet::addSymbol(char c) {
    if (c != '_') {
        charSet.insert(c);
        return 0;
    } else {
        return -1;
    }
}

