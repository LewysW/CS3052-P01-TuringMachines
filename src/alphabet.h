//
// Created by locw on 04/03/19.
//

#ifndef CS3052_P01_TURINGMACHINES_ALPHABET_H
#define CS3052_P01_TURINGMACHINES_ALPHABET_H

#include <unordered_set>

using namespace std;

class Alphabet {
private:
    unordered_set<char> charSet;

public:
    bool contains(char c);
    int addSymbol(char c);
};


#endif //CS3052_P01_TURINGMACHINES_ALPHABET_H
