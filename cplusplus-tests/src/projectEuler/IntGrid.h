#pragma once

#include <string>
#include <vector>

using namespace std;

class IntGrid
{
	public:
		IntGrid(string, int, int);
		IntGrid(vector<string>, int, int);
		~IntGrid();

		long long greatestProductFromCoord(int row, int col, int sequenceLength);
		size_t size() { return grid.size(); }
	private:
		vector<vector<int>> grid;

		vector<vector<int>> intGridFromStringVector(vector<string> input, int gridX, int gridY);
		long long leftRightProduct(int row, int col, int sequenceLength);
		long long downRightProduct(int row, int col, int sequenceLength);
		long long downProduct(int row, int col, int sequenceLength);
		long long downLeftProduct(int row, int col, int sequenceLength);
};

