#include "sblock.h"
#include <vector>
using namespace std;

sBlock::sBlock() {
    type = 'S';
    imag_length = 3;
    top_left_r = 1;
    top_left_c = 0;
    for (int i = 0; i < imag_length; ++i) {
        vector<int> new_row;
        for (int j = 0; j < imag_length; ++j) {
            if ((i == 2 && (j == 0 || j == 1)) || (i == 1 && (j == 1 || j == 2))) {
                new_row.push_back(1);
				listCells.emplace_back(Cell{top_left_r + i, top_left_c + j, true, type});
            } else {
                new_row.push_back(0);
            }
        }	
        imaginary.push_back(new_row);
    }
}
