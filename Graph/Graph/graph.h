#pragma once
#include <string>
#include <vector>

class graph
{
public:
	graph();
	~graph();

	void addVertex(std::string name); // Add new vertex to graph.
	void connect(std::string nameFirst, std::string nameSecod); // Will create directed edge between vertex nameFirst and nameSecond.
	void printMatrix(); // Print graph as matrix.
	int graphOrder(); // Return ammoun of vertex in graph.
	int graphSize(); // Return number of edges.
	int vertexDegree(std::string name); // Return degree of vertex with name=name.
	bool isComplete(); // Check graph complete.

	int graphDegree(); // Return max degree of vertex.

	std::vector<int> DFS(std::string name); // DFS algorith, starts fom vertex name.
	std::vector<int> BFS(std::string name); // BFS algorith, starts fom vertex name.
	std::vector<int> path(std::string nameStart, std::string nameEnd);
	void transposition(); // Make graph transposition.
	void graphSquare(); // Make square of graph.
	void lineGraph(); // Make new line graph.
private:
	struct vertex
	{
		std::string name; 
		std::vector<int> edges; // This vector stoarge positons of neighbor vertex.
		bool visited;

		vertex(std::string name);
		void addEdge(int num);
	};
	std::vector<vertex> vertexInGraph; // Countainer for graph.
	std::vector<std::vector<bool>> matrix; // Graph matrix.
	void saveAsMatrix(); 
	int findVertex(const std::string& name) // Return posistion of vertex with specific name in collection. When vertex is not found return -1.
	{
		for (uint64_t i = 0; i<vertexInGraph.size(); i++)
		{
			if(vertexInGraph[i].name.substr(0,name.length())==name)
			{
				return i;
			}
		}
		return -1;
	} // Retuns position of vertex in collection vertexInGraph.

	void depthFirstSearch(int v, std::vector<int> &wek); // Recursive algorithm.
	void breadthFirstSearch(int v, std::vector<int> &wek); // Recursive algorithm.
	void resetVisited(); // Set all vivted property of vertex to false.
	void buildNewGraph(); // Make new graph repesentation from matrix.
	void pathDFS(int start, int end, std::vector<int>&path);
};
