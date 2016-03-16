#include <list>
#include <vector>
#include <algorithm>
#include <iostream>
#include "ProjectEulerProblems.h"

using namespace std;

int problem_001_sumOfMultiples_solution01(list<int> factorList, int limit)
{
	int sum = 0;

	factorList.sort();

	for (int i = *factorList.begin(); i < limit; i++)
	{
		for (list<int>::iterator listIterator = factorList.begin(); listIterator != factorList.end(); listIterator++)
		{
			if (i % *listIterator == 0)
			{
				sum += i;
				break;
			}
		}
	}

	return sum;
}

int problem_001_sumOfMultiples_solution02(vector<int> factorVector, int limit)
{
	int sum = 0;
	int factor = 0;
	int multiple = 0;
	vector<int> multipleVector;

	sort(factorVector.begin(), factorVector.end());

	for (vector<int>::iterator vectorIterator = factorVector.begin(); vectorIterator != factorVector.end(); vectorIterator++)
	{
		factor = 0;
		multiple = 0;

		while (true)
		{
			multiple = *vectorIterator * factor;

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

	for (vector<int>::iterator listIterator = multipleVector.begin(); listIterator != multipleVector.end(); listIterator++)
	{
		sum += *listIterator;
	}

	return sum;
}

int problem_002_evenFibonacciNumbers(int termOne, int termTwo, int limit)
{
	int sum = 0;
	
	while (true)
	{

	}

	return sum;
}