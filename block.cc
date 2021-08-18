#include "block.h"
#include <iostream>
using namespace std;

int Block::getTopr() {
	return top_left_r;
}

int Block::getTopc() {
	return top_left_c;
}

char Block::getType() {
	return type;
}

void Block::setTopr(int r) {
	top_left_r = r;
}

void Block::setTopc(int c) {
	top_left_c = c;



	
}

void Block::setType(char t) {
	type = t;
}

void Block::right() {
	bool proceed = false;
	//--top_left_c;
	for (auto cell: listCells) {
		int row = cell.getRow();
		int col = cell.getCol();
		if (col + 1 > 10) {
			proceed = false;
			break;
		}
	}
	if (proceed) {
		vector<Cell> copyList;
		for (auto cell: listCells) {
			int row = cell.getRow();
			int col = cell.getCol();
			Cell new_c = Cell(row, col + 1, true, cell.getType());
			copyList.push_back(new_c);
			cell.setFilled(false);
			cell.setType(' ');
		}
		for (auto cell : copyList) {
			//g.setCells(cell);
		}
		++top_left_c;
	}
}


vector<vector<int>> Block::Clockwise() {
    int end = 0;
    vector <vector<int>> new_imag;
    for (int col = 0; col < imag_length; ++col) {
        vector<int> new_row;
        for (int start = imag_length - 1; start >= 0; --start) {
            if (imaginary[start][col] == 1) {
                new_row.push_back(1);
            } else {
                new_row.push_back(0);
            }
        }
        new_imag.push_back(new_row);
    }
	return new_imag;
}

void Block::setImag(vector<vector<int>> imag) {
	imaginary = imag;
}

vector<Cell> Block::getlistCells() {
	return listCells;
}

vector<vector<int>> Block::getImag() {
	return imaginary;
}

void Block::addTolistCells(Cell c) {
	listCells.push_back(c);
}

void Block::setListCells(vector<Cell> c) {
	listCells.clear();
	listCells = c;
}

void Block::printblk() {
	for (int i = 0; i < imag_length; ++i) {
		for (int j = 0; j < imag_length; ++j) {
			if (imaginary[i][j] == 1) {
				cout << type;
			} else {
				cout << ' ';
			}
		}
		cout << endl;
	}
	cout << endl;
}

bool Block::hasReached() {
	return reachedBottom;
}
void Block::setBottom(bool reached) {
	reachedBottom = reached;
}
