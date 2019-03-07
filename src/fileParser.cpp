//
// Created by locw on 04/03/19.
//

#include "fileParser.h"

void FileParser::loadTMFile(char* path, string& currentState, string& acceptState,
                            string& rejectState, Alphabet& alphabet, unordered_map<string, State>& states) {

    ifstream tmFile;
    tmFile.open(path);

    if (tmFile.is_open()) {
        readStates(tmFile, currentState, acceptState, rejectState, states);
        readAlphabet(tmFile, alphabet);
        readTransitions(tmFile, alphabet, acceptState, rejectState, states);
    } else {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
}

void FileParser::loadTapeFile(char *path, Alphabet &alphabet, Tape &tape) {
    ifstream tapeFile;
    string line;
    tapeFile.open(path);
    vector<char> tapeCells;

    //Checks that file has opened correctly
    if (tapeFile.is_open()) {
        //Reads characters, adding them to tape if they are in the alphabet (or are blank, '_') and are not whitespace characters
        char c;
        while (tapeFile.get(c)) {
            if (isspace(c)) continue;

            if (alphabet.contains(c) || c == '_') {
                tapeCells.push_back(c);
            } else {
                cout << "Invalid tape file characters. Exiting" << endl;
                exit(EXIT_FAILURE);
            }
        }

        tape.setCells(tapeCells);
    } else {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
}

void FileParser::readStates(ifstream& tmFile, string& currentState, string& acceptState,
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

                //Checks If non accepting or rejecting state
                if (tokens.size() == 1 && !(tokens[0] == "+" || tokens[0] == "-")) {
                    if (stateNum == START_STATE) {
                        currentState = tokens[0];
                    }
                //Checks if accepting or rejecting state
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
                unordered_map<char, Transition> transitions;
                states[tokens[0]].setTransitions(transitions);
            }
        }
    } else {
        cout << "invalid file format - file empty. Exiting" << endl;
        exit(EXIT_FAILURE);
    }
}

void FileParser::readAlphabet(ifstream& tmFile, Alphabet &alphabet) {
    string line;
    vector<string> tokens;

    if (getline(tmFile, line)) {
        tokens = tokenizeLine(line);

        //If there is no 'alphabet' token, or alphabet is the only token, exit.
        if (tokens[0] != "alphabet" || tokens.size() <= 1) {
            cout << "invalid file format - no alphabet. Exiting" << endl;
            exit(EXIT_FAILURE);
        } else {
            //Otherwise iterate over each token, ensuring the tokens are the correct length (and not '_') and add to the alphabet
            for (unsigned int tokenNum = 1; tokenNum < tokens.size(); tokenNum++) {
                if (tokens[tokenNum].length() == sizeof(char) && tokens[tokenNum] != "_") {
                    alphabet.addSymbol(tokens[tokenNum][0]);
                } else {
                    cout << "invalid file format - alphabet invalid. Exiting" << endl;
                    exit(EXIT_FAILURE);
                }
            }
        }

    } else {
        cout << "invalid file format - no alphabet. Exiting" << endl;
        exit(EXIT_FAILURE);
    }
}

void FileParser::readTransitions(ifstream &tmFile, Alphabet& alphabet, string& acceptState,
                                 string& rejectState, unordered_map<string, State> &states) {
    string line;
    vector<string> tokens;
    int currentToken;
    string currentState;
    char inputSymbol;
    string nextState;
    char outputSymbol;
    char direction;

    if (getline(tmFile, line)) {
        //Loops while there are additional transition lines
        do {
            tokens = tokenizeLine(line);
            currentToken = 0;

            if (tokens.size() != TRANSITION_SIZE) {
                cout << "invalid file - transition invalid. Exiting" << endl;
                exit(EXIT_FAILURE);
            } else {
                //Checks that current state of transition is valid (in list of states and not an accept or reject state)
                if (states.find(tokens[currentToken]) != states.end() && !(tokens[currentToken] == acceptState ||
                    tokens[currentToken] == rejectState)) {
                    currentState = tokens[currentToken++];
                } else {
                    cout << "invalid file - current state " << tokens[currentToken] << "in transition invalid. Exiting" << endl;
                    exit(EXIT_FAILURE);
                }

                //Ensures that input character is in alphabet and is the correct length (or is '_')
                if ((tokens[currentToken].length() == sizeof(char) && alphabet.contains(tokens[currentToken][0])) || (tokens[currentToken] == "_")) {
                    inputSymbol = tokens[currentToken++][0];
                } else {
                    cout << "invalid file - invalid input character " << tokens[currentToken] << " to transition. Exiting" << endl;
                    exit(EXIT_FAILURE);
                }

                //Validates next state of transition
                if (states.find(tokens[currentToken]) != states.end()) {
                    nextState = tokens[currentToken++];
                } else {
                    cout << "invalid file - invalid next state. Exiting" << endl;
                    exit(EXIT_FAILURE);
                }

                //Ensures that output character is in alphabet and is the correct length (or is '_')
                if ((tokens[currentToken].length() == sizeof(char) && alphabet.contains(tokens[currentToken][0])) || (tokens[currentToken] == "_")) {
                    outputSymbol = tokens[currentToken++][0];
                } else {
                    cout << "invalid file - invalid output character " << tokens[currentToken] << " to transition. Exiting" << endl;
                    exit(EXIT_FAILURE);
                }

                if ((tokens[currentToken]).length() == sizeof(char) && (tokens[currentToken] == "L"|| tokens[currentToken] == "R")) {
                    direction = tokens[currentToken++][0];
                } else {
                    cout << "invalid file - direction is not L or R. Exiting" << endl;
                    exit(EXIT_FAILURE);
                }

                //Adds transition to state
                Transition t(inputSymbol, nextState, outputSymbol, direction);
                states[currentState].addTransition(t);
            }
        } while (getline(tmFile, line));


    } else {
        cout << "invalid file - no transitions. Exiting" << endl;
        exit(EXIT_FAILURE);
    }
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
