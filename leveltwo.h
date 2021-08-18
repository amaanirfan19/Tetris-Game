#ifndef _LEVELTWO_
#define _LEVELTWO_
#include "levels.h"

class LevelTwo : public Level {
public:
    LevelTwo();
    char generateBlock() override;
};

#endif