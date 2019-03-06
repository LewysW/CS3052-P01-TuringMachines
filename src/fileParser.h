//
// Created by locw on 04/03/19.
//

#ifndef CS3052_P01_TURINGMACHINES_FILEPARSER_H
#define CS3052_P01_TURINGMACHINES_FILEPARSER_H
#include <string>
#include "alphabet.h"
#include "tape.h"
#include "state.h"

using namespace std;

class FileParser {
public:
    FileParser(const string &tmPath);
    FileParser(const string &tmPath, const string &tapePath);

    void populateAlphabet(Alphabet alphabet);
    void populateTape(Tape tape);
    void populateStates(string currentState, string acceptState, string rejectState, unordered_map<string, State> states);
private:
    string tmPath;
    string tapePath;
};


#endif //CS3052_P01_TURINGMACHINES_FILEPARSER_H
