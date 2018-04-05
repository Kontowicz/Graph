#pragma once
#include "edge.h"
#include <string>
#include <vector>

class vertex
{
public:
	vertex(std::string name)
	{
		this->name = name;
		this->edges.clear();
		this->visited = false;
	}


	void addEdge(int number)
	{
		edges.emplace_back(number);
	}

	void addEdge(int number, int distance)
	{
		edges.emplace_back(number, distance);
	}

	void removeEdge(int number)
	{
		auto it = edges.begin() + number;
			if(it!=edges.end())
			{
				edges.erase(it);
			}
			else
			{
				return;
			}
	}


	std::string name;
	std::vector<edge> edges;
	bool visited;
};
