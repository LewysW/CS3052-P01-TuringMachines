//
// Created by locw on 04/03/19.
//

#include "fileParser.h"

void FileParser::loadTMFile(string& path, string& currentState, string& acceptState,
                            string& rejectState, Alphabet& alphabet, unordered_map<string, State>& states) {

    ifstream file(path, ifstream::in);

    if (ifstream.is_open()) {
        cout << "Opened TM file for reading..." << endl;
    } else {
        cout << "File failed to open. Exiting" << endl;
        exit(EXIT_FAILURE);
    }

}

void FileParser::loadTapeFile(string& path, Tape& tape) {}
