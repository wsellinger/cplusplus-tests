#include <list>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include "ProjectEulerProblems.h"

#include <iostream>

using namespace std;

bool isPrime(long long input);
bool isPalindrome(int input);

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

		while (true)
		{
			multiple = *iterator * factor;

			if (multiple < limit)
			{
				multipleVector.push_back(multiple);
				factor++;
			}
			else 
			{
				break;
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
	vector<int> termVector;

	while (true)
	{
		currentTerm = termOne + termTwo;
		
		if (currentTerm <= limit)
		{
			if (currentTerm % 2 == 0)
			{
				termVector.push_back(currentTerm);
			}
		}
		else
		{
			break;
		}

		termOne = termTwo;
		termTwo = currentTerm;
	}

	return accumulate(termVector.begin(), termVector.end(), 0);
}

long long problem_003_largestPrimeFactor(long long multiple)
{
	long double factor = 0;

	for (long long i = 1; i < multiple; i++)
	{
		factor = long double (multiple) / i;

		if (floor(factor) == factor && isPrime(factor))
		{
			return factor;
		}
	}

	return 1;
}

bool isPrime(long long input)
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