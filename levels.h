#ifndef _LEVELS_
#define _LEVELS_
#include <string>
#include <fstream> 
#include <vector> 
#include "grid.h"

using namespace std; 

class Level {
  public:
    int currentLevel; 
    vector <char> blockTypes;
    int idx = 0;
    string fileString;

    Level(int level, string file = ""); 
    virtual ~Level() = default; 
    
    virtual char generateBlock() = 0; 
    void setIdx(int i);
    int getIdx();
    void readFile();
};

#endif