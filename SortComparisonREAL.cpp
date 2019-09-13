// SortComparisonREAL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
#include "Source.cpp"
#include <chrono>
#include <cmath>

int main()
{
	int size = 10000;
	int rndmax = 2000;
	diffs d;
	double expected_ratio = ((double)size * (double)size) / ((double)size * (double)std::log((double)size));
	double real_ratio = d.calc_diff(size, rndmax);
	
	int iterations = 1;
	double avg_ratio = d.calc_diff(size, rndmax);

	do
	{
		real_ratio = d.calc_diff(size, rndmax);
		float percent_of_whole = ((float)iterations / (float)(iterations + 1));
		avg_ratio = (avg_ratio * percent_of_whole) + (real_ratio * (1 - percent_of_whole));
		std::cout << " Avg ratio: " << avg_ratio << " Expected ratio: " << expected_ratio << " This trial: " << real_ratio << std::endl;
		iterations++;
	} while (true);
};

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

		