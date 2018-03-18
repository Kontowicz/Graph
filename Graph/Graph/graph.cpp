#include "graph.h"
#include <iostream>


graph::graph()
{
}

graph::~graph()
{
}

void graph::addVertex(std::string name)
{
	if (findVertex(name) == -1)
		vertexInGraph.emplace_back(name);
	else
		std::cout << "Name in use, try other!\n";
}

void graph::connect(std::string nameFirst, std::string nameSecod)
{
	uint64_t f = findVertex(nameFirst);
	uint64_t s = findVertex(nameSecod);
	vertexInGraph[f].addEdge(s);
}

void graph::printMatrix()
{
	saveAsMatrix();

	std::cout << "\n  ";
	for(int i=0; i<matrix.size(); i++)
	{
		std::cout << i << " ";
	}
	std::cout << "\n";
	for(uint64_t i = 0; i<matrix.size(); i++)
	{
		std::cout << i;
		for (auto reference : matrix[i])
		{
			std::cout <<" "<< reference;
		}
		std::cout << "\n";
	}
}


graph::vertex::vertex(std::string name)
{
	this->name = name;
	visited = false;
}

void graph::vertex::addEdge(int num)
{
	edges.push_back(num);
}

void graph::saveAsMatrix()
{
	matrix.clear();
	matrix.resize(vertexInGraph.size());
	for (uint64_t i =0; i<vertexInGraph.size(); i++)
	{
		matrix[i].resize(vertexInGraph.size());
	}

	for(uint64_t i =0 ; i<vertexInGraph.size(); i++)
	{
		for (uint64_t j = 0; j<vertexInGraph[i].edges.size(); j++)
		{
			matrix[i][vertexInGraph[i].edges[j]] = true;
		}
	}
}
