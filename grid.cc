#include "grid.h"
#include "levels.h"
#include "levelone.h"
#include "levelzero.h"
#include "leveltwo.h"
#include "levelthree.h"
#include "cell.h"
#include "block.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "tblock.h"
#include "zblock.h"

Grid::Grid() {
	Cells.clear();
	setScore(0);
	for (int i = 0; i < grid_max_row; ++i) {
		vector <Cell> cell_row;
		for (int j = 0; j < grid_col; ++j) {
			Cell new_cell(i, j, false, ' ');
			cell_row.push_back(new_cell);
		}
		Cells.push_back(cell_row);
	}
}

Cell Grid::findcell(int r, int c) {
    return Cells[r][c];
}

char Grid::getNew_b() {
	return new_b;
}

void Grid::displayNextBlock() {
	char next_blk;
	if (level == 0) {
        LevelZero l_0 = LevelZero(file);
        l_0.setIdx(idx);
        if (l_0.getIdx() == 0) {
            idx = 0;
        }
        next_blk = l_0.generateBlock();
        idx++;
    } else if (level == 1) {
		LevelOne l_1 = LevelOne();
		next_blk = l_1.generateBlock();
		
	} else if (level == 2) {
		LevelTwo l_2 = LevelTwo();
		next_blk = l_2.generateBlock();
	} else if (level == 3) {
		LevelThree l_3 = LevelThree();
		next_blk = l_3.generateBlock();
	}
	new_b = next_blk;
	
	Block blk = Block();
	
	if (new_b == 'I') {
		blk = iBlock();
	} else if (new_b == 'J') {
		blk = jBlock();
	} else if (new_b == 'L') {
		blk = lBlock();
	} else if (new_b == 'O') {
		blk = oBlock();
	} else if (new_b == 'S') {
		blk = sBlock();
	} else if (new_b == 'T') {
		blk = tBlock();
	} else if (new_b == 'Z') {
		blk = zBlock();
	}
	blk.setType(next_blk);
	blk_ptr = blk;

	vector<vector<int>> imag = blk.getImag();
	for (int i = 0; i < imag.size(); ++i) {
		for (int j = 0; j < imag[i].size(); ++j) {
			if (imag[i][j] == 1) {
				if (findcell(i + blk_ptr.getTopr(), j + blk_ptr.getTopc()).isFilled()) {	
					game_over = true;
					return;
				}
				Cell new_cell = Cell(i + blk_ptr.getTopr(), j + blk_ptr.getTopc(), true, next_blk);
				setCells(new_cell);
			}
		}
	}
}

bool Grid::getGame_over() {
	return game_over;
}

void Grid::setCells(Cell & c) {
	Cells[c.getRow()][c.getCol()] = c;
}

void Grid::setScore(int s) {
	score = s;
}

void Grid::setFile(string name) {
	file = name;
}


int Grid::getScore() {
	return score;
}

void Grid::setLevel(int l) {
	level = l;
}

int Grid::getLevel(){
	return level; 
}

void Grid::levelUp() {
	if (level < 3) {
		++level;
	}
}


void Grid::deleteRow(int row) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < 11; j++)
		{
			Cells[i+1][j].setFilled(Cells[i][j].isFilled());
			Cells[i+1][j].setType(Cells[i][j].getType());
		}
		
	}
	
}

void Grid::removeRows() {
	int count = 0;
	while(count < 18) {
	int start_row;
	for (int i = 17; i >= 0; --i) {
		bool status = false;
		for (int j = 0; j < 11; ++j) {
			if (Cells[i][j].isFilled()) {
				status = true;
			} else {
				status = false;
				break;
			}
		}
		if (status) {
			start_row = i - 1;
			for (int k = 0; k < 11; ++k) {
				Cells[i][k] = Cell(i, k, false, ' ');
			}
			for (int s = start_row; s >= 0; --s) {
				for (int c = 0; c < 11; ++c) {
					if (Cells[s][c].isFilled()) {
					int row = Cells[s][c].getRow();
					int col = Cells[s][c].getCol();
					char type = Cells[s][c].getType();
					Cells[s + 1][c] = Cell(s + 1, c, true, type);
					Cells[s][c] = Cell(row, col, false, ' ');

					}
				}
			}
		}
	}
	++count;
	}
}


vector<vector<Cell>> Grid::getCells() {
	return Cells;
}

void Grid::levelDown() {
	if (level > 0) {
		--level;
 	}
}


bool member(int r, int c, vector<Cell> list) {
	for (auto p : list) {
		if ((p.getRow() == r) && (p.getCol() == c)) {
			return true;
		}
	}
	return false;
}

void Grid::checkLeft() {
	vector<pair<int, int>> temp_coords;
	vector<vector<int>> imag;
	for (auto i: blk_ptr.getImag()) {
		vector<int> new_g;
		for (auto j : i) {
			new_g.push_back(j);
		}
		imag.push_back(new_g);
	}
	bool proceed = true;
	for (int i = 0; i < imag.size(); ++i) {
		for (int j = 0; j < imag[i].size(); ++j) {
			if (imag[i][j] == 1) {
				
				int row = blk_ptr.getTopr() + i;
				int col = blk_ptr.getTopc() + j - 1;
				if (col < 0 || ((!member(row, col, blk_ptr.getlistCells())) && Cells[row][col].isFilled())) {
					//cout << "A1: " << (member(row, col, blk_ptr.getlistCells())) << endl;
					//cout << "A2: " << Cells[row][col].isFilled() << endl;
					proceed = false;
					break;
				}
				temp_coords.push_back(make_pair(row, col)); 
			}	
		}
	}
	if (proceed) {
		for (auto c : temp_coords) {
			//cout << "c.first: " << c.first << "c.second: " << c.second << endl;
			Cells[c.first][c.second + 1] = Cell{c.first, c.second + 1, false, ' '};
		}
		vector<Cell> newlist;
		for (auto c : temp_coords) {
			Cell new_c = Cell(c.first, c.second, true, blk_ptr.getType());
			Cells[c.first][c.second] = new_c;
			newlist.push_back(new_c);
			blk_ptr.setListCells(newlist);
		}
		
		blk_ptr.setTopc(blk_ptr.getTopc() - 1);
	}
}


void Grid::checkRight() {
	vector<pair<int, int>> temp_coords;
	vector<vector<int>> imag;
	for (auto i: blk_ptr.getImag()) {
		vector<int> new_g;
		for (auto j : i) {
			new_g.push_back(j);
		}
		imag.push_back(new_g);
	}
	bool proceed = true;
	for (int i = 0; i < imag.size(); ++i) {
		for (int j = 0; j < imag[i].size(); ++j) {
			if (imag[i][j] == 1) {
				
				int row = blk_ptr.getTopr() + i;
				int col = blk_ptr.getTopc() + j + 1;
				if (col > 10 || ((!member(row, col, blk_ptr.getlistCells())) && Cells[row][col].isFilled())) {
					
					proceed = false;
					break;
				}
				temp_coords.push_back(make_pair(row, col)); 
			}	
		}
	}
	if (proceed) {
		for (auto c : temp_coords) {
			Cells[c.first][c.second - 1] = Cell{c.first, c.second - 1, false, ' '};
		}
		vector<Cell> newlist;
		for (auto c : temp_coords) {
			Cell new_c = Cell(c.first, c.second, true, blk_ptr.getType());
			Cells[c.first][c.second] = new_c;
			newlist.push_back(new_c);
			blk_ptr.setListCells(newlist);
		}
		
		blk_ptr.setTopc(blk_ptr.getTopc() + 1);
	} 
}


void Grid::checkDown() {
	vector<pair<int, int>> temp_coords;
	vector<vector<int>> imag;
	for (auto i: blk_ptr.getImag()) {
		vector<int> new_g;
		for (auto j : i) {
			new_g.push_back(j);
		}
		imag.push_back(new_g);
	}
	bool proceed = true;
	for (int i = 0; i < imag.size(); ++i) {
		for (int j = 0; j < imag[i].size(); ++j) {
			if (imag[i][j] == 1) {
				int row = blk_ptr.getTopr() + i + 1;
				int col = blk_ptr.getTopc() + j;
				//cout << "row: " << row << "   " << "col: " << col << endl;
				if (row > 17 || ((!member(row, col, blk_ptr.getlistCells())) && Cells[row][col].isFilled())) {
					proceed = false;
					break;
				}
				temp_coords.push_back(make_pair(row, col)); 
			}	
		}
	}
	if (proceed) {
		for (auto c : temp_coords) {
			//cout << "c.first: " << c.first << "c.second: " << c.second << endl;
			Cells[c.first - 1][c.second] = Cell{c.first - 1, c.second, false, ' '};
		}
		vector<Cell> newlist;
		for (auto c : temp_coords) {
			Cell new_c = Cell(c.first, c.second, true, blk_ptr.getType());
			Cells[c.first][c.second] = new_c;
			newlist.push_back(new_c);
			blk_ptr.setListCells(newlist);
		}
		
		blk_ptr.setTopr(blk_ptr.getTopr() + 1);
	} else {
		blk_ptr.setBottom(true);
	}
}


void Grid::checkClockwise() {    
    vector<pair<int, int>> temp_coords;
    vector<vector<int>> imag; 
    vector<vector<int>> new_imaginary = blk_ptr.Clockwise();
  //  cout << "printing imaginary" << endl;
    for (auto i: blk_ptr.getImag()) {
        vector<int> new_g;
        for (auto j : i) {
            new_g.push_back(j);
        }
        imag.push_back(new_g);
    }
    
    bool proceed = true;
    for (int i = 0; i < new_imaginary.size(); ++i) {
        for (int j = 0; j < new_imaginary[i].size(); ++j) {
            if (new_imaginary[i][j] == 1) {
                int row = blk_ptr.getTopr() + i;
                int col = blk_ptr.getTopc() + j;
    
                if (col < 0 || col > 10 || row < 0 || row > 17 || ((!member(row, col, blk_ptr.getlistCells())) && Cells[row][col].isFilled())) {
                    
                    proceed = false;
                    break;
                }
                temp_coords.push_back(make_pair(row, col)); 
            }    
        }
    }
    if (proceed) {
        for (int i = 0; i < imag.size(); ++i) {
            for (int j = 0; j < imag.size(); ++j) {
                if (imag[i][j] == 1) {
                int row = i + blk_ptr.getTopr();
                int col = j + blk_ptr.    getTopc();
            Cells[row][col] = Cell{row, col, false, 'F'};
                }
            }
        }
        blk_ptr.setImag(new_imaginary);
        vector<Cell> newlist;
        for (auto c : temp_coords) {
            Cell new_c = Cell(c.first, c.second, true, blk_ptr.getType());
            Cells[c.first][c.second] = new_c;
            newlist.push_back(new_c);
            blk_ptr.setListCells(newlist);
        }
    }
}




void Grid::checkDrop() {
	while (!blk_ptr.hasReached()) {
		checkDown();
	}
}
