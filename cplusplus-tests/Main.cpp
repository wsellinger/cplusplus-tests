#include <iostream>
#include <vector>
#include "ProjectEulerProblems.h"

using namespace std;

int main()
{
	cout << problem_001_sumMultiples_solution01(list<int>{3, 5}, 10000) << endl;
	cout << problem_001_sumMultiples_solution02(vector<int>{3, 5}, 10000) << endl;
	cout << problem_002_sumEvenFibonacciNumbers(4000000) << endl;
}