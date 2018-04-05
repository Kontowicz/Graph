#include "vertex.h"

vertex::vertex(std::string name)
{
	this->name = name;
	this->edges.clear();
	this->visited = false;
}

void vertex::addEdge(int number)
{
	edges.emplace_back(number);
}

void vertex::addEdge(int number, int distance)
{
	edges.emplace_back(number, distance);
}
