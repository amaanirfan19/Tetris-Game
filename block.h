#ifndef _BLOCK_H_
#define _BLOCK_H_
#include <vector>
#include "cell.h"
using namespace std;

class Block {
    public:
        void left();
        void right();
        void down();
        void drop();
        vector<vector<int>> Clockwise();
        bool AntiClockwise();
        void printblk();
        int getTopr();
        int getTopc();
        char getType();
        void setType(char type);
        void setTopr(int r);
        void setTopc(int c);
        vector<Cell> getlistCells();
        vector<vector<int>> getImag();
        void addTolistCells(Cell c);
        void setListCells(vector<Cell> c);
        void setImag(vector<vector<int>> imag);
        bool hasReached();
        void setBottom(bool reached);
    protected:
        vector<Cell> listCells;
        char type;
        vector<vector<int>> imaginary;
        int imag_length;
        int top_left_r;
        int top_left_c;
        bool reachedBottom = false;
};

#endif