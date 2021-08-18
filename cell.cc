#include "cell.h"

int Cell::getRow() {
    return r;
}

int Cell::getCol() {
    return c;
}

void Cell::setRow(int row) {
    r = row;
}

void Cell::setCol(int col) {
    c = col;
}

bool Cell::isFilled() {
    return filled;
}

char Cell::getType() {
    return type;
}

void Cell::setType(char t) {
    type = t;
}

void Cell::setFilled(bool fill) {
	filled = fill;
}
Cell::Cell(int r, int c, bool filled, char type): r{r}, c{c}, filled{filled}, type{type} {}
