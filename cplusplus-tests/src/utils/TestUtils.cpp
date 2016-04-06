#include "TestUtils.h"
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string input, char delimiter)
{
	vector<string> splitStringVector;
	stringstream inputStream(input);
	string subString;

	while (getline(inputStream, subString, delimiter))
	{
		splitStringVector.push_back(subString);
	}

	return splitStringVector;
}

bool isPrime(long long input)
{
	if (input > 1)
	{
		long long sqrtInput = sqrt(input);

		for (long long i = 2; i <= sqrtInput; i++)
		{
			if (input % i == 0)
			{
				return false;
			}
		}

		return true;
	}

	return false;
}

bool isPalindrome(int input)
{
	vector<int> intVector;

	while (input > 0)
	{
		intVector.push_back(input % 10);
		input /= 10;
	}

	for (size_t i = 0; i < intVector.size() / 2; i++)
	{
		if (intVector[i] != intVector[intVector.size() - i - 1])
		{
			return false;
		}
	}

	return true;
}

bool isEvenlyDivisibleByRange(int multiple, int min, int max)
{
	for (int i = min; i < max; i++)
	{
		if (multiple % i != 0)
		{
			return false;
		}
	}

	return true;
}

int sumSquares(int limit)
{
	int sum = 0;

	for (int i = 1; i <= limit; i++)
	{
		sum += pow(i, 2);
	}

	return sum;
}

int squareSums(int limit)
{
	int sum = 0;

	for (int i = 1; i <= limit; i++)
	{
		sum += i;
	}

	return pow(sum, 2);
}