#pragma once

#include <list>
#include <vector>
#include <string>

using namespace std;

extern string const eulerInput008;
extern string const eulerInput011;

int problem_001_sumMultiples_solution01(list<int> factorList, int limit);
int problem_001_sumMultiples_solution02(vector<int> factorList, int limit);
int problem_002_sumEvenFibonacciNumbers(int limit);
long long problem_003_largestPrimeFactor(long long multiple);
int problem_004_largestPalindrome(int numDigits);
int problem_005_smallestEvenlyDivisible(int min, int max);
int problem_006_sumSquareDifference(int limit);
int problem_007_nthPrime(int n); 
long long problem_008_largestProductInSeries(string input, int seriesLength);
int problem_009_specialPythagoreanTriplet(int tripletSum);
long long problem_010_sumOfPrimes(long limit);
long long problem_011_greatestProductAdjacentInGrid(string input, int gridX, int gridY, int sequenceLength);