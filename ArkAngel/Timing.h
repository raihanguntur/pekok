#pragma once

struct Timer
{
	std::chrono::steady_clock::time_point startingPoint;
	void Start()
	{
		startingPoint = std::chrono::high_resolution_clock::now();
	}
	double Stop()
	{
		return std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - startingPoint).count();
	}
};

struct ScopedConsoleTimer
{
	std::chrono::steady_clock::time_point startingPoint;
	ScopedConsoleTimer()
	{
		startingPoint = std::chrono::high_resolution_clock::now();
	}
	~ScopedConsoleTimer()
	{
		Console.printf("%f", std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - startingPoint).count());
	}
};