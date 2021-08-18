#include <string>
#include <sstream>
#include <iostream>
#include "controller.h"

using namespace std;

int main(int args, char *argv[]) {
    string fileOne = "sequence1.txt";
    string fileTwo = "sequence2.txt";
    string cmd; 
    int curLevel = 0; 
    bool showGraphic;
    for (int c = 1; c < args; c++) {
        cmd = argv[c];
        
        if (cmd == "-text") {
            showGraphic = false;
        } else if (cmd == "-seed") {
            int seed; 
            ++c; 
            string num = argv[c];
            istringstream is{num};
            is >> seed;
            srand(seed);    // random seed generation
        } else if (cmd == "-scriptfile1") {
            ++c;
            fileOne = argv[c];
        } else if (cmd == "-scriptfile2") {
            ++c;
            fileTwo = argv[c];
        } else if (cmd == "-startlevel") {
            ++c;
            istringstream is{argv[c]};
            is >> curLevel;
        }
    }

    Controller game{curLevel, fileOne, fileTwo};
	//cout << "playgame called" << endl;
    game.playGame(); 
}

