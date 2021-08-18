#include "levelone.h"
using namespace std;

LevelOne::LevelOne(): Level(1){}

char LevelOne::generateBlock() {
    int pr = rand() % 6;
    char block;

    if (pr == 0) {
        // probability skew for Z and S
        int prSkew = rand() % 2;
        if (prSkew % 2 == 0){
            block = 'S';
        } else {
            block = 'Z';
        }
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

    return block;
}