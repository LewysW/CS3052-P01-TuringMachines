//
// Created by locw on 04/03/19.
//

#include "fileParser.h"

FileParser::FileParser(const string &tmPath) : tmPath(tmPath) {}

FileParser::FileParser(const string &tmPath, const string &tapePath) : tmPath(tmPath), tapePath(tapePath) {}

void FileParser::populateAlphabet(Alphabet alphabet) {}

void FileParser::populateTape(Tape tape) {}

void populateStates(string currentState, string acceptState, string rejectState, unordered_map<string, State> states) {}
