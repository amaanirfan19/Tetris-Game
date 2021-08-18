#ifndef _LEVELTHREE_
#define _LEVELTHREE_
#include "levels.h"
#include <iostream>
#include <fstream>
#include <vector>

class LevelThree : public Level {
public:
    LevelThree();
    char generateBlock() override;    
};

#endif 