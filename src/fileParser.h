//
// Created by locw on 04/03/19.
//

#ifndef CS3052_P01_TURINGMACHINES_FILEPARSER_H
#define CS3052_P01_TURINGMACHINES_FILEPARSER_H
#include <string>
#include <fstream>
#include "alphabet.h"
#include "tape.h"
#include "state.h"

using namespace std;

class FileParser {
public:
    void loadTMFile(string& path, string& currentState, string& acceptState,
                    string& rejectState, Alphabet& alphabet, unordered_map<string, State>& states);

    void loadTapeFile(string& path, Tape& tape);
private:
    string tmPath;
    string tapePath;
};


#endif //CS3052_P01_TURINGMACHINES_FILEPARSER_H
