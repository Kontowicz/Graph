
#include "graph.h"
int main()
{
	graph g;
	g.addVertex("0");
	g.addVertex("1");
	g.addVertex("2");
	g.addVertex("3");
	g.addVertex("4");
	g.connectUnoriented("0", "1");
	g.connectUnoriented("1", "2");
	g.connectUnoriented("3", "4");
	g.saveAsMarix();
	for (int i = 0; i<g.matrix.size(); i++)
	{
		for (int j = 0; j<g.matrix[i].size(); j++)
		{
			std::cout<<g.matrix[i][j];
		}
		std::cout<<"\n";
	}
	g.vertexInGraph[0];
	int ks = 92;
}
