#ifndef TABLE_H
#define TABLE_H
#include <iostream>
#include <vector>
enum class Direction;

const int width = 4;
const int height = 5;

class Table
{
private:
	int block_num;
	std::vector<std::vector<int>> data;
	bool is_solved() const;

public:
	// initialize an empty table with no blocks added.
	Table();
	// moves the block with index in direc or do nothing if the move is invalid.
	// requires: 0 <= index < block_num
	void move(int index, Direction direction);
	friend std::istream &operator>>(std::istream &in, Table &table);
	friend std::ostream &operator<<(std::ostream &out, const Table &table);
};

std::istream &operator>>(std::istream &in, Table &table);
std::ostream &operator<<(std::ostream &out, const Table &table);

#endif
