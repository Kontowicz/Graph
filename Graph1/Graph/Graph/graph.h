#pragma once
#include "edge.h"
#include "vertex.h"
#include <iostream>
#include <list>

class graph
{
public:
	graph()
	{
		isUnoriented = true;
	}
	bool error = false;
#pragma region vertex/edge operations
	void addVertex(std::string name) // Func add new vertex to collection.
	{
		if (findVertex(name) == -1)
			vertexInGraph.emplace_back(name);
		else
			error = true;
	} 
	void removeVertex(std::string name) // This func remove specific vertex from collection.
	{
		int pos = findVertex(name);
		if(pos!=-1)
		{
			auto it = vertexInGraph.begin() + pos;
			vertexInGraph.erase(it);
		}
		else { error = true; }
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
			error = true;
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
			error = true;
		}
	}
	void connectOriented(std::string nameFirst, std::string nameSecod) // Will create directional edge between vertex nameFirst and nameSecond.
	{
		uint64_t f = findVertex(nameFirst);
		uint64_t s = findVertex(nameSecod);
		if (f != -1 || s != -1)
		{
			vertexInGraph[s].addEdge(f);
		}
		else
		{
			error = true;
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
			error = true;
		}
		isUnoriented = false;
	} 
	void removeEdge(std::string nameFirst, std::string nameSecond)
	{
		int f = findVertex(nameFirst);
		int pos = -1;
		int s = findVertex(nameSecond);
		if(s==-1 || f==-1)
		{
			error = true;
			return;
		}
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
		}
	}
#pragma endregion 

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
		else { error = true; }
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
	std::vector<std::string> getName()
	{
		std::vector<std::string> toReturn;
		for(auto it = vertexInGraph.begin(); it!= vertexInGraph.end(); it++)
		{
			toReturn.push_back(it->name);
		}
		return toReturn;
	}

	void transposition()
	{
		saveAsMarix();
		std::vector<std::vector<bool>> tmp;
		tmp.resize(matrix.size());
		for(int i=0; i<matrix.size(); i++)
		{
			tmp[i].resize(matrix.size());
		}

		for(int i=0; i<matrix.size(); i++)
		{
			for(int j=0; j<matrix.size(); j++)
			{
				tmp[j][i] = matrix[i][j];
			}
		}
		matrix = tmp;
		save(); // Save new graph from matrix
	} 
	const std::vector<std::vector<bool>> getMatrix()
	{
		return matrix;
	}

	void graphSquare()
	{
		saveAsMarix();
		int r = matrix.size();
		std::vector<std::vector<bool>> tmp;
		tmp.resize(r);

		for (int i = 0; i<r; i++)
			tmp[i].resize(r);

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < r; j++)
				tmp[i][j] = matrix[i][j];

			for (int j = 0; j < r; j++) {
				if ((i != j) && matrix[i][j]) {
					for (int k = 0; k < r; k++)
						if (matrix[j][k]) tmp[i][k] = 1;
				}
			}
		}

		matrix = tmp;
		save();
	}
	void depthFirstSearch(int v, std::vector<int> &wek)
	{
		vertexInGraph[v].visited = true;
		wek.push_back(v);
		for (uint64_t i = 0; i < vertexInGraph[v].edges.size(); i++)
		{
			if (!vertexInGraph[vertexInGraph[v].edges[i].number].visited)
				depthFirstSearch(vertexInGraph[v].edges[i].number, wek);
		}
	}
	void breadthFirstSearch(int v, std::vector<int> &wek)
	{
		resetVisited();
		std::list<int> list;
		vertexInGraph[v].visited = true;
		list.push_back(v);

		while (!list.empty())
		{
			v = list.front();
			wek.push_back(v);
			list.pop_front();
			for(int i=0; i<vertexInGraph[v].edges.size();i++)
			{
				if(!vertexInGraph[vertexInGraph[v].edges[i].number].visited)
				{
					vertexInGraph[vertexInGraph[v].edges[i].number].visited = true;
					list.push_back(findVertex(vertexInGraph[vertexInGraph[v].edges[i].number].name));
				}
			}
		}
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
	void save() 
	{
		for(int i=0; i<matrix.size(); i++)
		{
			vertexInGraph[i].edges.clear();
			for(int j=0; j<matrix.size(); j++)
			{
				if(matrix[i][j])
				{
					vertexInGraph[i].addEdge(j);
				}
			}
		}
	}//Make new graph representation from matrix
#pragma endregion 
	
	
	

	
	

};
