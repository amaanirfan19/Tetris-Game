#ifndef _IBLOCK_H_
#define _IBLOCK_H_

#include "block.h"
#include <vector>
using namespace std;
class Block;
class iBlock : public Block {
	public:
    iBlock();    
};

#endif

/*
vector<Cell> listCells;
    char type;
    vector<vector<int>> imaginary;
    int imag_length;
    int top_left_r;
    int top_left_c;
*/
