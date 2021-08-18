#ifndef _JBLOCK_H_
#define _JBLOCK_H_

#include "block.h"
#include <vector>
using namespace std;
class Block;
class jBlock : public Block {
	public:
    jBlock();    
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
