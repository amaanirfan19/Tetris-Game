#include "levels.h"
#include <fstream> 
#include <iostream> 

using namespace std;

Level::Level(int level, string file): currentLevel(level), fileString(file) {
    if (fileString != "") readFile(); 
}

void Level::readFile(){
    if (fileString == "")  {
        cerr << "ERROR: unable to open input file or does not exist"; 
    } else {
        char block; 
        ifstream is(fileString);
        while(is >> block){
            blockTypes.emplace_back(block);
        }
    }
}

void Level::setIdx(int i) {
    idx = i;
}

int Level::getIdx() {
    return idx;
}