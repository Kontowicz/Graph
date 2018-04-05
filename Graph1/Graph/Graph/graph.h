#pragma once
#include "edge.h"
#include "vertex.h"
#include <iostream>

class graph
{
public:
	void addVertex(std::string name) // Func add new vertex to collection.
	{
		if (findVertex(name) == -1)
			vertexInGraph.emplace_back(name);
		else
			std::cout << "Error!\n";
	} 
	void removeVertex(std::string name) // This func remove specific vertex from collection.
	{
		int pos = findVertex(name);
		if(pos!=-1)
		{
			auto it = vertexInGraph.begin() + pos;
			vertexInGraph.erase(it);
		}
		else { return; }
	}
	int findVertex(const std::string& name)
	{
		for (uint64_t i = 0; i<vertexInGraph.size(); i++)
		{
			if (vertexInGraph[i].name.substr(0, name.length()) == name)
			{
				return i;
			}
		}
		return -1;
	}

	void connectUnoriented(std::string nameFirst, std::string nameSecod) // Will create non-directional edge between vertex nameFirst and nameSecond.
	{
		uint64_t f = findVertex(nameFirst);
		uint64_t s = findVertex(nameSecod);
		if (f != -1 || s != -1)
		{
			vertexInGraph[f].addEdge(s);
			vertexInGraph[s].addEdge(f);
		}
		else
		{
			std::cout << "Error!\n";
		}
	}
	void connectUnoriented(std::string nameFirst, std::string nameSecod, int weight)   // Will create non-directional edge between vertex nameFirst and nameSecond with weight equal weight.
	{
		uint64_t f = findVertex(nameFirst);
		uint64_t s = findVertex(nameSecod);
		if (f != -1 || s != -1)
		{
			vertexInGraph[f].addEdge(s, weight);
			vertexInGraph[s].addEdge(f, weight);
		}
		else
		{
			std::cout << "Error!\n";
		}
	}
	void connectOriented(std::string nameFirst, std::string nameSecod) // Will create directional edge between vertex nameFirst and nameSecond.
	{
		uint64_t f = findVertex(nameFirst);
		uint64_t s = findVertex(nameSecod);
		if (f != -1 || s != -1)
		{
			vertexInGraph[f].addEdge(s);
		}
		else
		{
			std::cout << "Error!\n";
		}
	} 
	void connectOriented(std::string nameFirst, std::string nameSecod, int weight) // Will create directional edge between vertex nameFirst and nameSecond with weight equal weight.
	{
		uint64_t f = findVertex(nameFirst);
		uint64_t s = findVertex(nameSecod);
		if (f != -1 || s != -1)
		{
			vertexInGraph[f].addEdge(s, weight);
		}
		else
		{
			std::cout << "Error!\n";
		}
	} 
	

	std::vector<vertex> vertexInGraph;
	std::vector<std::vector<bool>> matrix;

	

};
