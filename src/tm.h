//
// Created by locw on 04/03/19.
//

#ifndef CS3052_P01_TURINGMACHINES_TM_H
#define CS3052_P01_TURINGMACHINES_TM_H

#include <iostream>
#include "alphabet.h"

using namespace std;


class TM {
public:
    void run();

    const Alphabet &getAlphabet() const;

    void setAlphabet(const Alphabet &alphabet);

private:
    Alphabet alphabet;
};


#endif //CS3052_P01_TURINGMACHINES_TM_H
