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

string const eulerInput008 = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";

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
		
		if (product > largestProduct)
		{
			largestProduct = product;
		}
	}

	return largestProduct;
}

int problem_009_specialPythagoreanTriplet(int tripletSum)
{
	int c = 0;

	for (size_t a = 1; a < tripletSum - 1; a++)
	{
		for (size_t b = a + 1; b < tripletSum; b++)
		{
			c = tripletSum - a - b;

			if (pow(a, 2) + pow(b, 2) == pow(c, 2))
			{
				return a * b * c;
			}
		}
	}

	return 0;
}

long long problem_010_sumOfPrimes(long limit)
{
	long long sum = 0;

	for (long long i = 2; i < limit; i++)
	{
		if (isPrime(i))
		{
			sum += i;
		}
	}

	return sum;
}