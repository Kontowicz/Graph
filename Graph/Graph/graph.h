#pragma once
#include <string>
#include <vector>

class graph
{
public:
	graph();
	~graph();

	void addVertex(std::string name);
	void connect(std::string nameFirst, std::string nameSecod); // Will create edge between vertex nameFirst and nameSecond, but nameSecond to nameFirst will be not connected.
	void printMatrix();

private:
	struct vertex
	{
		std::string name; 
		std::vector<int> edges; // This vector stoarge positons of neighbor vertex.
		bool visited;

		vertex(std::string name);
		void addEdge(int num);
	};
	std::vector<vertex> vertexInGraph;
	std::vector<std::vector<bool>> matrix;
	void saveAsMatrix();
	int findVertex(std::string name) // Return posistion of vertex with specific name in collection. When vertex is not found return -1.
	{
		for (uint64_t i = 0; i<vertexInGraph.size(); i++)
		{
			if(vertexInGraph[i].name.substr(0,name.length())==name)
			{
				return i;
			}
		}
		return -1;
	}
};
