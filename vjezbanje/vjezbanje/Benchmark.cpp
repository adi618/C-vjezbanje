#include "pch.h"


class Timer
{
private:
	std::chrono::time_point <std::chrono::high_resolution_clock> start_point;

public:
	Timer()
	{
		start_point = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		auto end_point = std::chrono::high_resolution_clock::now();

		auto start = std::chrono::time_point_cast <std::chrono::microseconds>(start_point).time_since_epoch().count();
		auto stop = std::chrono::time_point_cast <std::chrono::microseconds>(end_point).time_since_epoch().count();

		auto duration = stop - start;
		double ms = duration * 0.001;

		std::cout << ms << " miliseconds\n";
	}
};