#include <iostream>
#include "tm.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2 || argc > 3) {
        cout << "Invalid number of command line arguments:" << endl;
        cout << "Usage: ./runtm <path to TM description> <optional path to initial tape description>";
        exit(EXIT_FAILURE);
    } else {
        TM tm;
        tm.run();
    }
    cout << "EXIT_SUCCESS!" << endl;
    return 0;
}