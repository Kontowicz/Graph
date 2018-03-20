#include "graph.h"
#include <iostream>
#include <iomanip>
#include <list>


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
		std::cout << "Error!\n";
}

void graph::connect(std::string nameFirst, std::string nameSecod)
{
	uint64_t f = findVertex(nameFirst);
	uint64_t s = findVertex(nameSecod);
	if (f != -1 && s != -1) 
	{
		vertexInGraph[f].addEdge(s);
		//vertexInGraph[s].addEdge(f);
	}
	else
	{
		std::cout << "Error!\n";
	}
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

int graph::graphOrder()
{
	return  vertexInGraph.size();
}

int graph::graphSize()
{
	int toRet = 0;
	for (auto vertex : vertexInGraph)
	{
		toRet += vertex.edges.size();
	}
	return  toRet;
}

int graph::vertexDegree(std::string name)
{
	int pos = findVertex(name);
	if (pos != -1)
		return vertexInGraph[pos].edges.size();
	else
		std::cout << "Error!\n";
}

bool graph::isComplete()
{
	return graphSize() == ((vertexInGraph.size()*(vertexInGraph.size()-1))/(2));
}

void graph::DFS(std::string name)
{
	resetVisited();
	int pos = findVertex(name);
	if (pos != -1)
		depthFirstSearch(findVertex(name));
	else
		std::cout << "Error in DFS!\n";
}

void graph::BFS(std::string name)
{
	resetVisited();

}

void graph::transposition()
{
	saveAsMatrix();
	std::vector<std::vector<bool>> tr;
	tr.resize(matrix.size());
	for (int i =0; i<matrix.size(); i++)
	{
		tr[i].resize(matrix.size());
	}

	for(int i = 0; i<matrix.size(); i++)
	{
		for(int j=0; j<matrix.size(); j++)
		{
			tr[j][i] = matrix[i][j];
		}
	}
	matrix = tr;
	buildNewGraph();
}

void graph::graphSquare()
{
	saveAsMatrix();
	int r = matrix.size();
	std::vector<std::vector<bool>> matrixS;
	matrixS.resize(r);

	for (int i=0; i<r; i++)
		matrixS[i].resize(r);
	
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < r; j++) 
			matrixS[i][j] = matrix[i][j];

		for (int j = 0; j < r; j++) {
			if ((i != j) && matrix[i][j]) {
				for (int k = 0; k < r; k++)
					if (matrix[j][k]) matrixS[i][k] = 1;
			}
		}
	}

	matrix = matrixS;
	buildNewGraph();
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

void graph::depthFirstSearch(int v)
{
	vertexInGraph[v].visited = true; 
	std::cout << std::setw(3) << v;
	for (uint64_t i = 0; i < vertexInGraph[v].edges.size(); i++)
	{
		if (!vertexInGraph[vertexInGraph[v].edges[i]].visited)
			depthFirstSearch(vertexInGraph[v].edges[i]);
	}
}

void graph::breadthFirstSearch(int v)
{
	std::list<int> queue;
	vertexInGraph[v].visited = true;
	queue.push_back(v);
	while (!queue.empty())
	{
		v = queue.front();
		std::cout << v << " ";
		queue.pop_front();
		for (int i = 0; i != vertexInGraph[v].edges.size(); ++i)
		{
			if(!vertexInGraph[vertexInGraph[v].edges[i]].visited)
			{
				vertexInGraph[vertexInGraph[v].edges[i]].visited = true;
				queue.push_back(i);
			}
		}
	}
}

void graph::resetVisited()
{
	for (auto vertex : vertexInGraph)
	{
		vertex.visited = false;
	}
}

void graph::buildNewGraph()
{
	for(int i=0; i<matrix.size(); i++)
	{
		vertexInGraph[i].edges.clear();
		for(int j=0; j<matrix.size(); j++)
		{
			if(matrix[i][j])
			{
				vertexInGraph[i].edges.push_back(j);
			}
		}
	}
}
