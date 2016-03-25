#include <list>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <string>
#include "ProjectEulerProblems.h"

#include <iostream>

using namespace std;

bool isPrime(long long input);
bool isPalindrome(int input);
bool isEvenlyDivisibleByRange(int multiple, int min, int max);
int sumSquares(int limit);
int squareSums(int limit);

int problem_001_sumMultiples_solution01(list<int> factorList, int limit)
{
	int sum = 0;

	factorList.sort();

	for (int i = *factorList.begin(); i < limit; i++)
	{
		for (list<int>::iterator iterator = factorList.begin(); iterator != factorList.end(); iterator++)
		{
			if (i % *iterator == 0)
			{
				sum += i;
				break;
			}
		}
	}

	return sum;
}

int problem_001_sumMultiples_solution02(vector<int> factorVector, int limit)
{
	int factor = 0;
	int multiple = 0;
	vector<int> multipleVector;

	sort(factorVector.begin(), factorVector.end());

	for (vector<int>::iterator iterator = factorVector.begin(); iterator != factorVector.end(); iterator++)
	{
		factor = 0;
		multiple = 0;

		while (multiple < limit)
		{
			multiple = *iterator * factor;

			if (multiple < limit)
			{
				multipleVector.push_back(multiple);
				factor++;
			}
		}
		
	}

	sort(multipleVector.begin(), multipleVector.end());
	multipleVector.erase(unique(multipleVector.begin(), multipleVector.end()), multipleVector.end());

	return accumulate(multipleVector.begin(), multipleVector.end(), 0);
}

int problem_002_sumEvenFibonacciNumbers(int limit)
{
	int termOne = 0;
	int termTwo = 1;
	int currentTerm = 0;
	int sum = 0;

	while (currentTerm <= limit)
	{
		currentTerm = termOne + termTwo;
		
		if (currentTerm <= limit)
		{
			if (currentTerm % 2 == 0)
			{
				sum += currentTerm;
			}
		}

		termOne = termTwo;
		termTwo = currentTerm;
	}

	return sum;
}

long long problem_003_largestPrimeFactor(long long multiple)
{
	long long factor = 0;

	for (long long i = 1; i < multiple; i++)
	{
		factor = multiple / i;

		if (multiple % i == 0 && isPrime(factor))
		{
			return factor;
		}
	}

	return 1;
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

int problem_004_largestPalindrome(int numDigits)
{
	int min = pow(10, numDigits - 1);
	int max = pow(10, numDigits) - 1;
	int multiple = 0;
	vector<int> palindromeVector;

	for (int i = min; i <= max; i++)
	{
		for (int j = i; j <= max; j++)
		{
			multiple = i * j;

			if (isPalindrome(multiple))
			{
				palindromeVector.push_back(multiple);
			}
		}
	}

	return *max_element(palindromeVector.begin(), palindromeVector.end());
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

int problem_005_smallestEvenlyDivisible(int min, int max)
{
	int multiple = max;

	while (!isEvenlyDivisibleByRange(multiple, min, max))
	{
		multiple++;
	}

	return multiple;
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

int problem_006_sumSquareDifference(int limit)
{
	return squareSums(limit) - sumSquares(limit);
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

int problem_007_nthPrime(int n)
{
	int numPrimes = 0;
	int integer = 0;

	while (numPrimes != n)
	{
		integer++;

		if (isPrime(integer))
		{
			numPrimes++;
		}
	}

	return integer;
}

long long problem_008_largestProductInSeries(string input, int seriesLength)
{
	long long product = 0;
	long long largestProduct = 0;

	for (size_t i = 0; i < input.size() - seriesLength; i++)
	{
		product = 1;

		for (size_t j = 0; j < seriesLength; j++)
		{
			product *= input[i + j] - '0';
		}
		cout << product << endl;
		if (product > largestProduct)
		{
			largestProduct = product;
		}
	}

	return largestProduct;
}