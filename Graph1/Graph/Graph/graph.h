#pragma once
#include "edge.h"
#include "vertex.h"
#include <iostream>

class graph
{
public:
	graph()
	{
		isUnoriented = true;
	}
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
	

	void connectUnoriented(std::string nameFirst, std::string nameSecod) // Will create non-directional edge between vertex nameFirst and nameSecond.
	{
		uint64_t f = findVertex(nameFirst);
		uint64_t s = findVertex(nameSecod);
		if (f != -1 && s != -1)
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
		isUnoriented = false;
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
		isUnoriented = false;
	} 
	void removeEdge(std::string nameFirst, std::string nameSecond)
	{
		int f = findVertex(nameFirst);
		int pos = -1;
		int s = findVertex(nameSecond);
		for(int i=0; i<vertexInGraph[f].edges.size(); i++)
		{
			if(vertexInGraph[f].edges[i].number==s)
			{
				pos = i;
				break;
			}
		}
		if(s!=-1 && f!=-1 && pos!=-1)
		{
			vertexInGraph[f].removeEdge(pos);
//			vertexInGraph[s].removeEdge(f);
		}
	}

	int graphOrder()
	{
		return  vertexInGraph.size();
	}  // Return ammoun of vertex in graph.
	int graphSize()
	{
		int toRet = 0;

		for (auto vertex : vertexInGraph)
		{
			toRet += vertex.edges.size();
		}
		if (isUnoriented)
		{
			return toRet / 2;
		}
		else { return  toRet; }
	}
	int vertexDegree(std::string name)
	{
		int pos = findVertex(name);
		if (pos != -1)
		{
			return vertexInGraph[pos].edges.size();
		}
		else { throw std::exception("Vertex didn't exist"); }
	}
	bool isComplete()
	{
		return graphSize() == ((vertexInGraph.size()*(vertexInGraph.size() - 1)) / (2));
	}
	int graphDegree()
	{
		int toReturn = 0;
		for (auto vertex : vertexInGraph)
		{
			if (toReturn<vertex.edges.size())
			{
				toReturn = vertex.edges.size();
			}
		}
		return toReturn;
	}
	bool areConnected(std::string first, std::string second)
	{
		int f = findVertex(first);
		int s = findVertex(second);
		return areVertexConnected(f, s);
	}
	



#pragma region private
	std::vector<vertex> vertexInGraph;
	std::vector<std::vector<bool>> matrix;
	bool isUnoriented;

	bool areVertexConnected(int vertex, int vertex1)
	{
		for (int i = 0; i<vertexInGraph[vertex].edges.size(); i++)
		{
			if (vertexInGraph[vertex].edges[i].number == vertex1)
				return true;
		}
		return false;
	}
	void saveAsMarix()
	{
		matrix.clear();
		matrix.resize(vertexInGraph.size());
		for (uint64_t i = 0; i<vertexInGraph.size(); i++)
		{
			matrix[i].resize(vertexInGraph.size());
		}

		for (uint64_t i = 0; i<vertexInGraph.size(); i++)
		{
			for (uint64_t j = 0; j<vertexInGraph[i].edges.size(); j++)
			{
				matrix[i][vertexInGraph[i].edges[j].number] = true;
			}
		}
	} 
	void makeUnoriented()
	{
		for (int i = 0; i<vertexInGraph.size(); i++)
		{
			for (int j = 0; j<vertexInGraph[i].edges.size(); j++)
			{
				if (!areVertexConnected(vertexInGraph[i].edges[j].number, i))
				{
					vertexInGraph[vertexInGraph[i].edges[j].number].edges.push_back(i);
				}
			}
		}
	}
	void resetVisited()
	{
		for (int i = 0; i<vertexInGraph.size(); i++)
		{
			vertexInGraph[i].visited = false;
		}
	}
	int firstUnvisited()
	{
		for (int i = 0; i<vertexInGraph.size(); i++)
		{
			if (!vertexInGraph[i].visited)
				return i;
		}
		return -1;
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
#pragma endregion 
	
	
	

	
	

};
