#include "levelthree.h"
using namespace std;

LevelThree::LevelThree(): Level(3){}

char LevelThree::generateBlock() {
    char block;

    // need "heavy" command implementation 

    if (fileString == "") {
        if (idx == blockTypes.size()) idx = 0;
        block = blockTypes[idx];
        idx++; 
        return block;
    }

    int pr = rand() % 9;

    if (pr == 0 || pr == 1) { 
        block = 'S';
    }

    if (pr == 2 || pr == 3) {
        block = 'Z';
    } 
    
    if (pr == 4) {
        block = 'J';
    } 
    
    if (pr == 5) {
        block = 'L';
    } 
    
    if (pr == 6) {
        block = 'O';
    } 
    
    if (pr == 7) {
        block = 'T';
    }

    if (pr == 8) {
        block = 'I';
    }

    return block;
}