//
// Created by locw on 04/03/19.
//

#include <sstream>
#include "fileParser.h"

void FileParser::loadTMFile(char* path, string& currentState, string& acceptState,
                            string& rejectState, Alphabet& alphabet, unordered_map<string, State>& states) {

    ifstream tmFile;
    tmFile.open(path);

    if (tmFile.is_open()) {
        cout << "Opened TM file for reading..." << endl;
    } else {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    populateStates(tmFile, currentState, acceptState, rejectState, states);
}

void FileParser::populateStates(ifstream& tmFile, string& currentState, string& acceptState,
                                string& rejectState, unordered_map<string, State>& states) {
    int numStates = 0;
    string line;
    vector<string> tokens;

    //Gets first line to check for the number of states
    if (getline(tmFile, line)) {
        tokens = tokenizeLine(line);

        //Checks that first line is valid
        if (tokens.at(0) != "states" || (numStates = stoi(tokens.at(1))) <= 0) {
            cout << "invalid file format. Exiting" << endl;
            exit(EXIT_FAILURE);
        }

        numStates = stoi(tokens[1]);

        //Iterates over and parses each state
        for (int stateNum = 0; stateNum < numStates; stateNum++) {
            if (getline(tmFile, line)) {
                tokens.clear();
                tokens = tokenizeLine(line);

                //Ensures that current parsed state has not already been added
                if (!(states.find(tokens[0]) == states.end())) {
                    cout << "invalid file format - repeated states. Exiting" << endl;
                    exit(EXIT_FAILURE);
                }

                if (tokens.size() == 1 && !(tokens[0] == "+" || tokens[0] == "-")) {
                    if (stateNum == START_STATE) {
                        currentState = tokens[0];
                    }
                } else if (tokens.size() == 2 && (tokens[0] != "+" && tokens[0] != "-") && (tokens[1] == "+" || tokens[1] == "-")) {
                    if (tokens[1] == "+") {
                        acceptState = tokens[0];
                    } else {
                        rejectState = tokens[0];
                    }
                } else {
                    cout << "invalid file format - state format invalid. Exiting" << endl;
                    exit(EXIT_FAILURE);
                }

                //Creates new state with transitions initially NULL
                states[tokens[0]] = State(tokens[0]);
            }
        }
    } else {
        cout << "invalid file format - file empty. Exiting" << endl;
    }

    cout << "current state: " << currentState << endl;
    cout << "accept state: " << acceptState << endl;
    cout << "reject state: " << rejectState << endl;
}

//Tokenizing a string https://www.geeksforgeeks.org/tokenizing-a-string-cpp/
vector<string> FileParser::tokenizeLine(string line) {
    vector<string> tokens;
    stringstream checkStream(line);
    string intermediate;

    while (getline(checkStream, intermediate, ' ')) {
        tokens.push_back(intermediate);
    }

    return tokens;
}

void FileParser::loadTapeFile(char* path, Tape& tape) {
    ifstream tapeFile(path, ifstream::in);

    if (tapeFile.is_open()) {
        cout << "Opened tape file for reading..." << endl;
    } else {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
}
