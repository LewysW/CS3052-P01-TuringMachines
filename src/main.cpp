#include <iostream>
#include "tm.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2 || argc > 3) {
        cout << "Invalid number of command line arguments:" << endl;
        cout << "Usage: ./runtm <path to TM description> <optional path to initial tape description>";
        exit(INPUT_ERROR);
    } else {
        TM tm;

        if (argc == 2) {
            tm.run(argv[TM_FILE_PATH], nullptr);
        } else {
            tm.run(argv[TM_FILE_PATH], argv[TAPE_FILE_PATH]);
        }

    }
    cout << "EXIT_SUCCESS!" << endl;
    return 0;
}