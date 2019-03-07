//
// Created by locw on 04/03/19.
//

#ifndef CS3052_P01_TURINGMACHINES_TAPE_H
#define CS3052_P01_TURINGMACHINES_TAPE_H

#include <vector>

using namespace std;

class Tape {
public:
    vector<char> &getCells();

    void setCells(const vector<char> &cells);

private:
    vector<char> cells;
};


#endif //CS3052_P01_TURINGMACHINES_TAPE_H
