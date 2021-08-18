#ifndef _CELL_H_
#define _CELL_H_

class Cell {
    public:
    Cell(int r, int c, bool filled, char type);
    int getRow();
    int getCol();
    void setRow(int r);
    void setType(char type);
    void setCol(int c);
    char getType();
    bool isFilled();
	void setFilled(bool fill);
    void addTolistCells(Cell c);
    private:
    char type;
    int r;
    int c;
    bool filled;    
};

#endif
