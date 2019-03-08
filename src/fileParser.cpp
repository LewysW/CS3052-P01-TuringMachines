//
// Created by locw on 04/03/19.
//

#include <algorithm>
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
        exit(CANNOT_OPEN_FILE);
    }
}

void FileParser::loadTapeFile(char *path, Alphabet& alphabet, Tape &tape) {
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

            if ((c != '_' && alphabet.contains(c))) {
                tapeCells.push_back(c);
            } else if (c == '_') {
                tapeCells.push_back(c);
            } else {
                printf("%s", "input error");
                exit(INPUT_ERROR);
            }
        }

        tape.setCells(tapeCells);
    } else {
        perror("Cannot open tape");
        exit(CANNOT_OPEN_FILE);
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

        //Checks that first line starts with the word "states", and has a valid state number >= 0
        if (tokens.at(0) != "states" || tokens.size() < HEADER_SIZE
            || !is_number(tokens[1]) || (numStates = stoi(tokens[1])) <= 0) {
            printf("%s", "input error");
            exit(INPUT_ERROR);
        }

        numStates = stoi(tokens[1]);

        //Every TM must have at least one accept and one reject state
        if (numStates < MINIMUM_STATE_NUM) {
            printf("%s", "input error");
            exit(INPUT_ERROR);
        }

        //Iterates over and parses each state
        for (int stateNum = 0; stateNum < numStates; stateNum++) {
            if (getline(tmFile, line)) {
                tokens.clear();
                tokens = tokenizeLine(line);

                //Ensures that current parsed state has not already been added
                if (!(states.find(tokens[0]) == states.end())) {
                    printf("%s", "input error");
                    exit(INPUT_ERROR);
                }

                //Checks that non accepting state is not called +, -, or alphabet
                if (tokens.size() == 1 && !(tokens[0] == "+" || tokens[0] == "-" || tokens[0] == "alphabet")) {
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
                    printf("%s", "input error");
                    exit(INPUT_ERROR);
                }

                //Creates new state with transitions initially NULL
                states[tokens[0]] = State(tokens[0]);
                unordered_map<char, Transition> transitions;
                states[tokens[0]].setTransitions(transitions);
            }
        }
    } else {
        printf("%s", "input error");
        exit(INPUT_ERROR);
    }
}

void FileParser::readAlphabet(ifstream& tmFile, Alphabet &alphabet) {
    string line;
    vector<string> tokens;

    if (getline(tmFile, line)) {
        tokens = tokenizeLine(line);
        //If there is no 'alphabet' token, or alphabet is the only token, or alphabet is wrong size, exit.
        if (tokens.size() <= HEADER_SIZE || tokens[0] != "alphabet"
            || !is_number(tokens[1]) || (unsigned int) stoi(tokens[1]) != (tokens.size() - HEADER_SIZE)) {
            printf("%s", "input error");
            exit(INPUT_ERROR);
        } else {
            //Otherwise iterate over each token, ensuring the tokens are the correct length (and not '_') and add to the alphabet
            for (unsigned long tokenNum = FIRST_CHARACTER; tokenNum < tokens.size(); tokenNum++) {
                if (tokens[tokenNum].length() == sizeof(char) && tokens[tokenNum] != "_") {
                    alphabet.addSymbol(tokens[tokenNum][0]);
                } else {
                    printf("%s", "input error");
                    exit(INPUT_ERROR);
                }
            }
        }

    } else {
        printf("%s", "input error");
        exit(INPUT_ERROR);
    }
}

//https://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c
bool FileParser::is_number(const std::string &s) {
    return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
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

    //Loops while there are transitions to process
    while (getline(tmFile, line)) {
        tokens = tokenizeLine(line);
        currentToken = 0;

        if (tokens.size() != TRANSITION_SIZE) {
            if (tokens.empty()) break;

            printf("%s", "input error");
            exit(INPUT_ERROR);
        } else {
            //Checks that current state of transition is valid (in list of states and not an accept or reject state)
            if (states.find(tokens[currentToken]) != states.end() && !(tokens[currentToken] == acceptState ||
                tokens[currentToken] == rejectState)) {
                currentState = tokens[currentToken++];
            } else {
                printf("%s", "input error");
                exit(INPUT_ERROR);
            }

            //Ensures that input character is in alphabet and is the correct length (or is '_')
            if ((tokens[currentToken].length() == sizeof(char) && alphabet.contains(tokens[currentToken][0])) || (tokens[currentToken] == "_")) {
                inputSymbol = tokens[currentToken++][0];
            } else {
                printf("%s", "input error");
                exit(INPUT_ERROR);
            }

            //Validates next state of transition
            if (states.find(tokens[currentToken]) != states.end()) {
                nextState = tokens[currentToken++];
            } else {
                printf("%s", "input error");
                exit(INPUT_ERROR);
            }

            //Ensures that output character is in alphabet and is the correct length (or is '_')
            if ((tokens[currentToken].length() == sizeof(char) && alphabet.contains(tokens[currentToken][0])) || (tokens[currentToken] == "_")) {
                outputSymbol = tokens[currentToken++][0];
            } else {
                printf("%s", "input error");
                exit(INPUT_ERROR);
            }

            if ((tokens[currentToken]).length() == sizeof(char) && (tokens[currentToken] == "L"|| tokens[currentToken] == "R")) {
                direction = tokens[currentToken][0];
            } else {
                printf("%s", "input error");
                exit(INPUT_ERROR);
            }

            //Adds transition to state
            Transition t(inputSymbol, nextState, outputSymbol, direction);

            //Checks that the transition is not a duplicate
            if (states[currentState].getTransitions().find(inputSymbol) == states[currentState].getTransitions().end()) {
                states[currentState].addTransition(t);
            } else {
                printf("%s", "input error");
                exit(INPUT_ERROR);
            }
        }
    }
}

//Tokenizing a string https://www.geeksforgeeks.org/tokenizing-a-string-cpp/
vector<string> FileParser::tokenizeLine(string line) {
    vector<string> tokens;
    stringstream checkStream(line);
    string intermediate;

    while (getline(checkStream, intermediate, ' ')) {
        //https://stackoverflow.com/questions/6444842/efficient-way-to-check-if-stdstring-has-only-spaces
        if (intermediate.find_first_not_of(' ') != std::string::npos) {
            tokens.push_back(intermediate);
        }
    }

    return tokens;
}


