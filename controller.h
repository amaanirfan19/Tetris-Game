#ifndef _CONTROLLER_
#define _CONTROLLER_
#include <string>
#include "grid.h"
#include "textdisplay.h"
using namespace std;

class Controller  {
    Grid playerOne;
    Grid playerTwo; 
	TextDisplay td; 
    int level; 
    void reset();
    void restart();
    void end();
  public:
    Controller(int level, string fileOne, string fileTwo);
    void playGame();
};

#endif
