#include "block.h"
#include "cell.h"
#include "block.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "tblock.h"
#include "zblock.h"
#include <iostream>

int main() {
	iBlock i_blk = iBlock();
	i_blk.printblk();
	i_blk.Clockwise();
	i_blk.printblk();
	cout << endl;

	jBlock j_blk = jBlock();
	j_blk.printblk();
	j_blk.Clockwise();
	j_blk.printblk();
	cout << endl;

	lBlock l_blk = lBlock();
	l_blk.printblk();
	l_blk.Clockwise();
	l_blk.printblk();
	cout << endl;

	oBlock o_blk = oBlock();
	o_blk.printblk();
	o_blk.Clockwise();
	o_blk.printblk();
	cout << endl;

	sBlock s_blk = sBlock();
	s_blk.printblk();
	s_blk.Clockwise();
	s_blk.printblk();
	cout << endl;

	tBlock t_blk = tBlock();
	t_blk.printblk();
	t_blk.Clockwise();
	t_blk.printblk();
	cout << endl;

	zBlock z_blk = zBlock();
	z_blk.printblk();
	z_blk.Clockwise();
	z_blk.printblk();
	cout << endl;
}