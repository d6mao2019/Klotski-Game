#include "klotski.h"
#include <assert.h>

// constructor.
Table::Table() {
	for (int j = 0; j < height; ++j) {
		for (int k = 0; k < width; ++k) {
			data[j][k] = EMPTY;
		}
	}
}

bool Table::is_solved() {
	return data[3][1] == 0 &&
		data[3][2] == 0 &&
		data[4][1] == 0 &&
		data[4][2] == 0;
}

void Table::move(int index, int direc) {
	assert(index >= 0);
	assert(index < block_num);
	assert(direc == UP || direc == DOWN || direc == LEFT || direc == RIGHT);
	if (direc == UP) {
		for (int j = 0; j < height; ++j) {
			for (int k = 0;; k < width; ++k) {
				if (j == 0) {
					std::cout << "error: invalid move." << std::endl;
					return;
				}
				assert(data[j - 1][k] != data[j][k]);
				if (data[j - 1][k] != EMPTY) {
					std::cout << "error: invalid move." << std::endl;
					return;
				}
				data[j - 1][k] = data[j][k];
				data[j][k] = EMPTY;
			}
		}
	}
	else if (direc == DOWN) {
		for (int j = height - 1; j >= 0; --j) {
			for (int k = 0; k < width; ++k) {
				if (j == height - 1) {
					std::cout << "error: invalid move." << std::endl;
					return;
				}
				assert(data[j + 1][k] != data[j][k]);
				if (data[j + 1][k] != EMPTY) {
					std::cout << "error: invalid move." << std::endl;
					return;
				}
				data[j + 1][k] = data[j][k];
				data[j][k] = EMPTY;
			}
		}
	}
	else if (direc = LEFT) {
		for (int k = 0; k < width; ++k) {
			for (int j = 0; j < height; ++j) {
				if (k == 0) {
					std::cout << "error: invalid move." << std::endl;
					return;
				}
				assert(data[j][k - 1] != data[j][k]);
				if (data[j][k - 1] != EMPTY) {
					std::cout << "error: invalid move." << std::endl;
					return;
				}
				data[j][k - 1] = data[j][k];
				data[j][k] = EMPTY;
			}
		}
	}
	else if (direc = RIGHT) {
		for (int k = width - 1; k >= 0; --k) {
			for (int j = 0; j < height; ++j) {
				if (k == width - 1) {
					std::cout << "error: invalid move." << std::endl;
					return;
				}
				assert(data[j][k + 1] != data[j][k]);
				if (data[j][k + 1] != EMPTY) {
					std::cout << "error: invalid move." << std::endl;
					return;
				}
				data[j][k + 1] = data[j][k];
				data[j][k] = EMPTY;
			}
		}
	}
	else assert(0);
}

std::ostream& print_border(std::ostream& out, const Table& table, int index) {
	assert(index >= 0);
	assert(index <= height);
	if (index == 0 || index == height) {
		out << "+-------+" << std::endl;
	}
	else {
		out << "|";
		for (int j = 0; j < 2 * width - 1; ++j) {
			if (j % 2 == 0) {// corresponds to a number.
				int above = table.data[index - 1][j / 2];
				int below = table.data[index][j / 2];
				if (above != below) out << "-";
			}
			else {// corresponds to a vertical border.
				int upper_right = table.data[index - 1][j / 2 + 1];
				int upper_left = table.data[index - 1][j / 2];
				int lower_left = table.data[index][j / 2];
				int lower_right = table.data[index][j / 2 + 1];
				if (upper_left == upper_right || lower_left == lower_right) out << "-";
				else if (upper_left == lower_left || upper_right == lower_right) out << "|";
				else out << "+";
			}
		}
		out << "|" << std::endl;
	}
	return out;
}

std::ostream& print_number(std::ostream& out, const Table& table, int index) {
	assert(index >= 0);
	assert(index < height);
	out << "|";
	for (int j = 0; j < 2 * width - 1; ++j) {
		if (j % 2 == 0) {// it is a nubmer.
			out << table.data[index][j / 2];
		}
		else {// is is a vertical border.
			int left = table.data[index][j / 2];
			int right = table.data[index][j / 2 + 1];
			if (left == right) out << " ";
			else out << "|";
		}
	}
	out << "|" << std::endl;
	return out;
}

std::ostream& operator<<(std::ostream& out, const Table& table) {
	for (int j = 0; j < 2 * height - 1; ++j) {
		if (j % 2 == 0) out = print_border(out, table, j / 2);
		else out = print_number(out, table, j / 2);
	}
	return out;
}

std::istream& operator>>(std::istream& in, Table& table) {
	int n;
	int counter = 0;
	for (int j = 0; j < height; ++j) {
		std::cout << "please enter line" << j << std::endl;
		for (int k = 0; k < width; ++k) {
			if (in >> n) {
				data[j][k] = n;
				++counter;
			}
			else std::cout << "warning: entering an non-int value!" << std::endl;
		}
	}
	if (counter < height * width) std::cout << "error: not enough data input." << std::endl;
}