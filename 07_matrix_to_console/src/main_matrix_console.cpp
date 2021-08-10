﻿#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
	Define a simple matrix.
*/
class Matrix
{
private:
	size_t column_count;
	size_t line_count;

	// TODO: store the data
	// hints: you can use std::string, std::vectors + string, char**, vector<vector<char>>, etc
	vector<vector<char>> matrix;
public:
	Matrix(size_t numColumnsX, size_t numLinesY)
		// TODO: add functionality
	{
		column_count = numColumnsX;
		line_count = numLinesY;
		// TODO: add functionality
		matrix.clear();
		matrix.resize(line_count);
		//for (size_t count = 0; count < line_count; count++) {
		//	matrix[count].resize(column_count);
		//}

	}

	// Set an entire line
	void setLine(size_t line_number, const std::string& data)
	{
		vector<char> aux(data.begin(), data.end());
		matrix[line_number] = vector<char>(data.begin(),data.end());
	}

	//OPTIONAL
	//char getCellXY(size_t x, size_t y, char cell_content)
	//{
	//	// TODO: add functionality
	//	return 0;
	//}

	/**
		Sets the cell content for a specific cell identified by its coordinates (X and Y)
		@param x The horizontal coordinate of the cell to set. Index starts at zer0.
		@param y The vertical coordinate of the cell to set. Index starts at zer0.
		@param cell_content A cell char to set.

		E.g.
		 X axis: 0 -------- ... -------> Width
		 Y axis
		 0       0,0  1,0                W-1, 0
		 |       0,1  1,1
		 |       0,2
		 .
		 .
		 .
		 |       0, H-1     ...          W-1, H-1
		 V

		 Height
	*/
	void setCellYX(size_t y, size_t x, char cell_content)
	{
		// TODO: add functionality
		matrix[y][x] = cell_content;
	}

	void print()
	{
		// print all lines and columns
		// TODO: add functionality
		for (auto rand : matrix) {
			for (auto element : rand) {
				cout << element << " ";
				cout.flush();
			}
			cout << "\n";
		}
	}
};

int main()
{
	// Create a matrix with the width of 20 and height of 10.
	Matrix matrix(20, 10);

	matrix.setLine(0, "X-----X----X-----XX-");
	matrix.setLine(1, "--X-----------------");
	matrix.setLine(2, "-----X--------------");
	matrix.setLine(3, "--------X-----------");
	matrix.setLine(4, "-----------X--------");
	matrix.setLine(5, "--------------X-----");
	matrix.setLine(6, "-----------------X--");
	matrix.setLine(7, "-------------------X");
	matrix.setLine(8, "------------------X-");
	matrix.setLine(9, "-----------------X--");

	matrix.print();
	// Would print
/*
X-----X----X-----XX-
--X-----------------
-----X--------------
--------X-----------
-----------X--------
--------------X-----
-----------------X--
-------------------X
------------------X-
-----------------X--
*/ 

	cout << "Next exercise" << endl;
	cout << "\n";
	matrix.setCellYX(1, 2, '-');
	matrix.print();
	// Would print
/*
X-----X----X-----XX-
--------------------
-----X--------------
--------X-----------
-----------X--------
--------------X-----
-----------------X--
-------------------X
------------------X-
-----------------X--
*/

	matrix.setCellYX(7, 3, 'O');
	matrix.print();
	/*
	X-----X----X-----XX-
	--------------------
	-----X--------------
	--------X-----------
	-----------X--------
	--------------X-----
	-----------------X--
	---O---------------X
	------------------X-
	-----------------X--
	*/

	// This should silently fail (not trigger an error): cell Y=11 invalid due to limited height.
	matrix.setCellYX(9, 3, 'O');
	return 0;
}