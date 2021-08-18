#ifndef _LEVELZERO_
#define _LEVELZERO_
#include "levels.h"
#include <iostream>
#include <fstream>
#include <vector>

class LevelZero : public Level {
public:
    LevelZero(std::string filename);
    char generateBlock() override;    
};

#endif 