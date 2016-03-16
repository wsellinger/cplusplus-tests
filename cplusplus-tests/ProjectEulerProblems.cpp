#include <list>
#include "ProjectEulerProblems.h"

using namespace std;

int problem_001_SumOfMultiples(list<int> factorList, int limit)
{
	int sum = 0;

	for (int i = 0; i < limit; i++)
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