//
// Created by locw on 04/03/19.
//

#ifndef CS3052_P01_TURINGMACHINES_FILEPARSER_H
#define CS3052_P01_TURINGMACHINES_FILEPARSER_H
#define START_STATE 0
#define ACCEPTING_STATE "+"
#define REJECTING STATE "-"

#include <string>
#include <fstream>
#include "alphabet.h"
#include "tape.h"
#include "state.h"

using namespace std;

class FileParser {
public:
    void loadTMFile(char* path, string& currentState, string& acceptState,
                    string& rejectState, Alphabet& alphabet, unordered_map<string, State>& states);

    void loadTapeFile(char* path, Tape& tape);

    void populateStates(ifstream& tmFile, string& currentState, string& acceptState, string& rejectState, unordered_map<string, State>& states);

    vector<string> tokenizeLine(string line);
private:
    string tmPath;
    string tapePath;
};


#endif //CS3052_P01_TURINGMACHINES_FILEPARSER_H
