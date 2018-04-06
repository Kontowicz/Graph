
#include "graph.h"
int main()
{
	graph g;
	g.addVertex("0");
	g.addVertex("1");
	g.addVertex("2");
	g.addVertex("3");
	g.addVertex("4");
	g.addVertex("5");
	g.connectUnoriented("0", "1");
	g.connectUnoriented("0", "2");
	g.connectUnoriented("0", "3");
	g.connectUnoriented("0", "4");
	g.connectUnoriented("0", "5");

	g.removeEdge("0", "1");
	g.removeEdge("0", "4");

	g.vertexInGraph[0];
	int ks = 92;
}
