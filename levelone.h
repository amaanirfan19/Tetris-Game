#ifndef _LEVELONE_
#define _LEVELONE_
#include "levels.h"
#include "grid.h"
#include <vector>

class Grid;

class LevelOne : public Level {
  public:
    LevelOne();
    char generateBlock() override;    
};

#endif 