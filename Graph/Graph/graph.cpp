#include "graph.h"
#include <iostream>
#include <list>
#include <algorithm>


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
		std::cout << "Errorasasssssssssssssssssssssssssss!\n";
}

void graph::connectUnoriented(std::string nameFirst, std::string nameSecod)
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
		std::cout << "Errorcon!\n";
	}
}

void graph::connectOriented(std::string nameFirst, std::string nameSecod)
{
	uint64_t f = findVertex(nameFirst);
	uint64_t s = findVertex(nameSecod);
	if (f != -1 || s != -1) 
	{
		vertexInGraph[f].addEdge(s);
	}
	else
	{
		std::cout << "Errorcon!\n";
	}
}

void graph::connectOriented(std::string nameFirst, std::string nameSecod, int weight)
{
	uint64_t f = findVertex(nameFirst);
	uint64_t s = findVertex(nameSecod);
	if (f != -1 || s != -1)
	{
		vertexInGraph[f].addEdge(s, weight);
	}
	else
	{
		std::cout << "Errorcon!\n";
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

	std::cout << "Name:\n";
	int i = 0;
	for (auto value : vertexInGraph)
	{
		std::cout << i << "   " << value.name<<"\n";
		++i;
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
		std::cout << "Error assdaasdads!\n";
}

bool graph::isComplete()
{
	return graphSize() == ((vertexInGraph.size()*(vertexInGraph.size()-1))/(2));
}

int graph::graphDegree()
{
	int toReturn = 0;
	for (auto vertex : vertexInGraph)
	{
		if(toReturn<vertex.edges.size())
		{
			toReturn = vertex.edges.size();
		}

		return toReturn;
	}
}

std::vector<int> graph::DFS(std::string name)
{
	resetVisited();
	std::vector<int> toReturn;
	int pos = findVertex(name);
	if (pos != -1)
	{
		depthFirstSearch(findVertex(name), toReturn);
		return  toReturn;
	}		
	else
		std::cout << "Error in DFS!\n";
}

std::vector<int> graph::BFS(std::string name)
{
	resetVisited();
	std::vector<int> toReturn;
	int pos = findVertex(name);
	if (pos != -1)
	{
		breadthFirstSearch(findVertex(name), toReturn);
		return  toReturn;
	}
	else
		std::cout << "Error in DFS!\n";
}

std::vector<int> graph::path(std::string nameStart, std::string nameEnd)
{
	resetVisited();
	std::vector<int> toReturn;
	pathDFS(findVertex(nameStart), findVertex(nameEnd), toReturn);
	return toReturn;
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

void graph::lineGraph()
{	
	struct po // Struct for represent new vertex name.
	{
		int i;
		int j;

		po(int a, int b)
		{
			i = a;
			j = b;
		}
	};
	saveAsMatrix();
	std::vector<po> w;

	for(int i=0; i<matrix.size(); i++) // Looking for all connected vertex, edges with vertex are connected will be a new vertex.
	{
		for (int j = 0; j < i; j++)
		{
			if (matrix[i][j] == 1)
			{
				w.emplace_back(j, i);
			}
		}
	}

	std::vector<std::vector<po>> vertex; 
	vertex.resize(w.size());

	int i = 0;
	for (auto value : w) // Looking for new connections between vertex
	{
		for (auto edge : vertexInGraph[value.i].edges)
		{
			if (edge != value.j && value.i != edge)
			{
				if (edge>value.i)
				{
					vertex[i].emplace_back(value.i, edge);
				}
				else
				{
					vertex[i].emplace_back(edge, value.i);
				}
			}
		}
		for (auto edge : vertexInGraph[value.j].edges)
		{
			if(edge!=value.j && value.i!=edge)
			{
				if(edge>value.j)
				{
					vertex[i].emplace_back(value.j, edge);
				}
				else
				{
					vertex[i].emplace_back(edge, value.j);
				}
			}
				
		}
		i++;
	}

	vertexInGraph.clear();
	// Save new graph 
	for (auto value : w)
	{
		addVertex(std::to_string(value.i) + "-" + std::to_string(value.j));
	}

	for (int i = 0; i<w.size(); i++)
	{
		for (auto is : vertex[i])
		{
			connectOriented(vertexInGraph[i].name,std::to_string(is.i) + "-" +std::to_string(is.j));
		}	
	}
	saveAsMatrix();
}

bool graph::isConnectedGraph()
{
	if (!isOriented()) 
	{
		return isConnected();
	}
	else
	{
		std::vector<vertex> tmp = vertexInGraph;
		makeUnoriented();
		bool toReturn = isConnected();
		vertexInGraph = tmp;
		return toReturn;
	}
}

void graph::connectedComponent()
{
	std::vector<int> w;
	int all = 0;
	int i = 0;
	resetVisited();
	while (all<vertexInGraph.size())
	{
		w.clear();
		int p = firstUnvisited();
		depthFirstSearch(p, w);
		all += w.size();
		std::cout << i << ":  ";
		for (auto value : w)
		{
			std::cout << value << " ";
		}
		std::cout << "\n";
		i++;
	}
	
	
}

bool graph::isConnected()
{
	std::vector<int> w;
	breadthFirstSearch(0, w);
	return (w.size() == vertexInGraph.size()) ? true : false;
}

void graph::makeUnoriented()
{
	for(int i=0; i<vertexInGraph.size(); i++)
	{
		for (int j=0; j<vertexInGraph[i].edges.size(); i++)
		{
			if(!areVertexConnected(vertexInGraph[i].edges[j],i))
			{
				vertexInGraph[vertexInGraph[i].edges[j]].edges.push_back(i);
			}
		}
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
	weight.push_back(0);
}

void graph::vertex::addEdge(int num, int distance)
{
	edges.push_back(num);
	weight.push_back(distance);
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

bool graph::areVertexConnected(int vertex, int vertex1)
{
	for(int i=0; i<vertexInGraph[vertex].edges.size(); i++)
	{
		if(vertexInGraph[vertex].edges[i]==vertex1)
			return true;
	}
	return false;
}

void graph::depthFirstSearch(int v, std::vector<int> &wek)
{
	vertexInGraph[v].visited = true; 
	wek.push_back(v);
	for (uint64_t i = 0; i < vertexInGraph[v].edges.size(); i++)
	{
		if (!vertexInGraph[vertexInGraph[v].edges[i]].visited)
			depthFirstSearch(vertexInGraph[v].edges[i], wek);
	}
}

void graph::breadthFirstSearch(int v, std::vector<int> &wek)
{
	std::list<int> queue;
	vertexInGraph[v].visited = true;
	queue.push_back(v);
	while (!queue.empty())
	{
		v = queue.front();
		wek.push_back(v);
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

void graph::pathDFS(int start, int end, std::vector<int>& path)
{
	vertexInGraph[start].visited = true;
	path.push_back(start);
	for (uint64_t i = 0; i < vertexInGraph[start].edges.size(); i++)
	{
		if (start == end) {
			return;
		}
		if (!vertexInGraph[vertexInGraph[start].edges[i]].visited)
			pathDFS(vertexInGraph[start].edges[i], end, path);
	}
}

bool graph::isOriented()
{
	bool toReturn = false;
	for (int i=0; i<matrix.size(); i++)
	{
		for(int j=0; j<matrix.size(); j++)
		{
			if(matrix[i][j]!=matrix[j][i])
			{
				return true;
			}
		}
	}
	return false;
}

int graph::firstUnvisited()
{
	
	for(int i=0; i<vertexInGraph.size(); i++)
	{
		if (vertexInGraph[i].visited == false)
			return i;
	}
}
