#include "iblock.h"
#include <vector>
#include <iostream>
using namespace std;

iBlock::iBlock() {
    type = 'I';
    imag_length = 4;
    top_left_r = 1;
    top_left_c = 0;
    for (int i = 0; i < imag_length; ++i) {
        vector<int> new_row;
        for (int j = 0; j < imag_length; ++j) {
            if (i == 2) {
                new_row.push_back(1);
				Cell new_c = Cell(top_left_r + i, top_left_c + j, true, type);
				listCells.push_back(new_c);
            } else {
                new_row.push_back(0);
            }
        }
        imaginary.push_back(new_row);
    }
	
}

/*
vector<Cell> listCells;
    char type;
    vector<vector<int>> imaginary;
    int imag_length;
    int top_left_r;
    int top_left_c;
*/