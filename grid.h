#ifndef _GRID_H_
#define _GRID_H_

#include "cell.h"
#include "levels.h"
#include "block.h"
#include <vector>
using namespace std;


class Grid : public Block {
    public:
        Grid();
        void displayNextBlock();    
        void levelUp();
        void levelDown();
        int getScore();
        void setScore(int s);
        Cell findcell(int r, int c);
        int getLevel();
        char getNew_b();
        void setLevel(int l);
        void setFile(string name);
        vector<vector<Cell>> getCells();
		void setCells(Cell & c);
		Block blk_ptr;
		
		void checkLeft();
		void checkRight();
		void checkDown();
        void checkClockwise();
		void checkDrop();
        void deleteRow(int row);
		bool getGame_over();

		//
		void removeRows();
		//
		//
		int count = 0;
		//
    private:
        vector<vector<Cell>> Cells;
        int grid_max_row = 18;
        int grid_row = 15;
        int grid_col = 11;
        int level = 0;
        int idx = 0;
        int score = 0;
        char new_b;
        string file;
        bool game_over = false;
};


#endif
