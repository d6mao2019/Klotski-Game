#include "table.h"
#include "util.h"

// constructor.
Table::Table()
{
	for (int i = 0; i < height; ++i)
	{
		for (int k = 0; k < width; ++k)
		{
			data[i][k] = -1;
		}
	}
}

bool Table::is_solved() const
{
	return data[3][1] == 0 &&
		   data[3][2] == 0 &&
		   data[4][1] == 0 &&
		   data[4][2] == 0;
}

void Table::move(int index, Direction direction)
{
	switch (direction)
	{
	case Direction::up:
		for (int j = 0; j < height; ++j)
		{
			for (int k = 0; k < width; ++k)
			{
				if (j == 0)
				{
					std::cout << "error: invalid move." << std::endl;
					return;
				}
				if (data[j - 1][k] != -1)
				{
					std::cout << "error: invalid move." << std::endl;
					return;
				}
				data[j - 1][k] = data[j][k];
				data[j][k] = -1;
			}
		}
	case Direction::down:
		for (int j = height - 1; j >= 0; --j)
		{
			for (int k = 0; k < width; ++k)
			{
				if (j == height - 1)
				{
					std::cout << "error: invalid move." << std::endl;
					return;
				}
				if (data[j + 1][k] != -1)
				{
					std::cout << "error: invalid move." << std::endl;
					return;
				}
				data[j + 1][k] = data[j][k];
				data[j][k] = -1;
			}
		}
	case Direction::left:
		for (int k = 0; k < width; ++k)
		{
			for (int j = 0; j < height; ++j)
			{
				if (k == 0)
				{
					std::cout << "error: invalid move." << std::endl;
					return;
				}
				if (data[j][k - 1] != -1)
				{
					std::cout << "error: invalid move." << std::endl;
					return;
				}
				data[j][k - 1] = data[j][k];
				data[j][k] = -1;
			}
		}
	case Direction::right:
		for (int k = width - 1; k >= 0; --k)
		{
			for (int j = 0; j < height; ++j)
			{
				if (k == width - 1)
				{
					std::cout << "error: invalid move." << std::endl;
					return;
				}
				if (data[j][k + 1] != -1)
				{
					std::cout << "error: invalid move." << std::endl;
					return;
				}
				data[j][k + 1] = data[j][k];
				data[j][k] = -1;
			}
		}
	}
}

std::ostream &print_border(std::ostream &out, const std::vector<std::vector<int>> &data, int index)
{
	if (index == 0 || index == height)
	{
		out << "+-------+" << std::endl;
	}
	else
	{
		out << "|";
		for (int i = 0; i < 2 * width - 1; ++i)
		{
			if (i % 2 == 0)
			{ // corresponds to a number.
				int above = data[index - 1][i / 2];
				int below = data[index][i / 2];
				if (above != below)
					out << "-";
			}
			else
			{ // corresponds to a vertical border.
				int upper_right = data[index - 1][i / 2 + 1];
				int upper_left = data[index - 1][i / 2];
				int lower_left = data[index][i / 2];
				int lower_right = data[index][i / 2 + 1];
				if (upper_left == upper_right || lower_left == lower_right)
					out << "-";
				else if (upper_left == lower_left || upper_right == lower_right)
					out << "|";
				else
					out << "+";
			}
		}
		out << "|" << std::endl;
	}
	return out;
}

std::ostream &print_number(std::ostream &out, const std::vector<std::vector<int>> &data, int index)
{
	out << "|";
	for (int i = 0; i < 2 * width - 1; ++i)
	{
		if (i % 2 == 0)
		{ // it is a nubmer.
			out << data[index][i / 2];
		}
		else
		{ // is is a vertical border.
			int left = data[index][i / 2];
			int right = data[index][i / 2 + 1];
			if (left == right)
				out << " ";
			else
				out << "|";
		}
	}
	out << "|" << std::endl;
	return out;
}

std::istream &operator>>(std::istream &in, Table &table)
{
	int n;
	int counter = 0;
	for (int i = 0; i < height; ++i)
	{
		std::cout << "please enter line" << i << std::endl;
		for (int k = 0; k < width; ++k)
		{
			if (in >> n)
			{
				table.data[i][k] = n;
				++counter;
			}
			else
				std::cout << "warning: entering an non-int value!" << std::endl;
		}
	}
	if (counter < height * width)
		std::cout << "error: not enough data input." << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Table &table)
{
	for (int i = 0; i < 2 * height - 1; ++i)
	{
		if (i % 2 == 0)
			print_border(out, table.data, i / 2);
		else
			print_number(out, table.data, i / 2);
	}
	return out;
}
