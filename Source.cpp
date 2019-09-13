#include <iostream>
#include <random>
#include <chrono>
#include <cmath>
#include <random>

class printer
{
public:
	void print(int array[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << array[i] << ' ';
		}
		std::cout << "\n";
	}
};
class sort
{
public:
	void swap(int array[], int a, int b)
	{
		int intermediary = array[a];
		array[a] = array[b];
		array[b] = intermediary;
	};
	void bubble(int array[], int size)
	{
		bool switched = false;
		do
		{
			switched = false;
			for (int i = 0; i < size - 1; i++)
			{
				if (array[i] > array[i + 1])
				{
					//MAY BE THE SAME NUMBER/DATA
					swap(array, i, i + 1);
					switched = true;
				}
			}
		} while (switched == true);
	}
	int partition(int array[], int min, int max)
	{
		int pivot = array[(min + (max - min) / 2)];
		int i = min - 1;
		int j = max + 1;
		do
		{
			do { i++; } while (array[i] < pivot);
			do { j--; } while (array[j] > pivot);
			if (i >= j) { return j; }
			swap(array, i, j);
		} while (true);
	}
	void quick(int array[], int min, int max)
	{
		if (min < max)
		{
			int pivot = partition(array, min, max);
			quick(array, min, pivot);
			quick(array, pivot + 1, max);
		}	
	}
};

class generator
{
public:
	void generate(int array[], int size, int rndmax)
	{
		for (int i = 0; i < size; i++)
		{
			array[i] = rand() % rndmax;
		}
	}
};

class diffs
{
public:
	double calc_diff(int size, int rndmax)
	{
		using namespace std::chrono;

		sort s;
		generator g;
		printer p;
		int* array = new int[size];
		g.generate(array, size, rndmax);

		//quicksort
		clock_t time1 = clock();
		auto q_start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
		s.quick(array, 0, size - 1);
		auto q_end = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
		auto quicktime = q_end - q_start;
		time1 = clock() - time1;

		g.generate(array, size, rndmax);
		//bubblesort
		clock_t time2 = clock();
		auto b_start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
		s.bubble(array, size);
		auto b_end = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
		auto bubbletime = b_end - b_start;
		time2 = clock() - time2;

		int ratio = double(time2 / time1) / CLOCKS_PER_SEC * 1000;
		return ratio;
	}
};