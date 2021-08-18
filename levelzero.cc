#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "levelzero.h"
using namespace std;

LevelZero::LevelZero(string file): Level(0, file) {}

char LevelZero::generateBlock(){
    if (idx == blockTypes.size()) idx = 0;

    char block = blockTypes[idx];
    idx++;

    return block;
}