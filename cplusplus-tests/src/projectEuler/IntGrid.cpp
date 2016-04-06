#include "IntGrid.h"
#include "utils\TestUtils.h"

#include <string>
#include <vector>

using namespace std;

IntGrid::IntGrid(string input, int gridWidth, int gridHeight)
{
	grid = intGridFromStringVector(split(input, ' '), gridWidth, gridHeight);
}

IntGrid::IntGrid(vector<string> input, int gridWidth, int gridHeight)
{
	grid = intGridFromStringVector(input, gridWidth, gridHeight);
}


IntGrid::~IntGrid()
{
}

vector<vector<int>> IntGrid::intGridFromStringVector(vector<string> input, int gridWidth, int gridHeight)
{
	vector<vector<int>> intGrid;
	int inputIndex = 0;
	string::size_type stringSizeType;

	for (size_t y = 0; y < gridHeight; y++)
	{
		vector<int> rowVector;
		intGrid.push_back(rowVector);

		for (size_t x = 0; x < gridWidth; x++)
		{
			intGrid[y].push_back(stoi(input[inputIndex], &stringSizeType));
			inputIndex++;
		}
	}

	return intGrid;
}

long long IntGrid::greatestProductFromCoord(int row, int col, int sequenceLength)
{
	long long greatestProduct = 0;
	vector<long long> products;

	products.push_back(leftRightProduct(row, col, sequenceLength));
	products.push_back(downRightProduct(row, col, sequenceLength));
	products.push_back(downProduct(row, col, sequenceLength));
	products.push_back(downLeftProduct(row, col, sequenceLength));

	for (size_t i = 0; i < products.size(); i++)
	{
		greatestProduct = products[i] > greatestProduct ? products[i] : greatestProduct;
	}

	return greatestProduct;
}

long long IntGrid::leftRightProduct(int row, int col, int sequenceLength)
{
	long long product = 1;
	
	if (col + sequenceLength - 1 < grid[row].size())
	{
		for (size_t i = 0; i < sequenceLength; i++)
		{
			product *= grid[row][col + i];
		}
	}

	return product;
}

long long IntGrid::downRightProduct(int row, int col, int sequenceLength)
{
	long long product = 1;

	if ((col + sequenceLength - 1 < grid[row].size()) && (row + sequenceLength - 1 < grid.size()))
	{
		for (size_t i = 0; i < sequenceLength; i++)
		{
			product *= grid[row + i][col + i];
		}
	}

	return product;
}

long long IntGrid::downProduct(int row, int col, int sequenceLength)
{
	long long product = 1;

	if (row + sequenceLength - 1 < grid.size())
	{
		for (size_t i = 0; i < sequenceLength; i++)
		{
			product *= grid[row + i][col];
		}
	}

	return product;
}

long long IntGrid::downLeftProduct(int row, int col, int sequenceLength)
{
	long long product = 1;

	if ((col - sequenceLength + 1 < grid[row].size()) && (row + sequenceLength - 1 < grid.size()))
	{
		for (size_t i = 0; i < sequenceLength; i++)
		{
			product *= grid[row + i][col - i];
		}
	}

	return product;
}
