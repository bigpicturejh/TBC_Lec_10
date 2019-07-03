#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
#include<chrono>

using namespace std;

class Timer
{
	
	using clock_t=chrono::high_resolution_clock;
	using second_t=chrono::duration<double, ratio<1>>;

	chrono::time_point<clock_t> start_time = clock_t::now();

public:
	void elapsed()
	{
		chrono::time_point<clock_t> end_time = clock_t::now();

		std::cout << chrono::duration_cast<second_t>(end_time - start_time).count() << std::endl;
	}
};