#ifndef KLOTSKI_H
#define KLOTSKI_H
#include <iostream>

const int width = 4;
const int height = 5;

const int EMPTY = -1;

const int UP = 101;
const int DOWN = 102;
const int LEFT = 103;
const int RIGHT = 104;

class Table {
private:
	int block_num;
	int** data;
	bool is_solved();
public:
	// initialize an empty table with no blocks added.
	Table();
	// moves the block with index in direc or do nothing if the move is invalid.
	// requires: 0 <= index < block_num
	//           direc is one of {UP, DOWN, LEFT, RIGHT}
	void Table::move(int index, int direc);
};

std::ostream& operator<<(std::ostream& out, const Table& table);

#endif // !KLOTSKI_H