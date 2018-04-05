#pragma once

class edge
{
public:
	edge(int num)
	{
		number = num;
		weight = 0;
	}

	edge(int num, int distance)
	{
		number = num;
		weight = distance;
	}

	int number; 
	int weight;
};