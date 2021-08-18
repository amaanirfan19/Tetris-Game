#include "leveltwo.h"
using namespace std;

LevelTwo::LevelTwo(): Level(2){}

char LevelTwo::generateBlock() {
    int pr = rand() % 7; // 1/6 probability
    char block;

    if (pr == 0) {
        block = 'S';
    }

    if (pr == 1) {
        block = 'I';
    } 
    
    if (pr == 2) {
        block = 'J';
    } 
    
    if (pr == 3) {
        block = 'L';
    } 
    
    if (pr == 4) {
        block = 'O';
    } 
    
    if (pr == 5) {
        block = 'T';
    }

    if (pr == 6) {
        block = 'Z';
    }

    return block;
}