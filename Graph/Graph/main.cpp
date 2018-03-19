#include "graph.h"

int main()
{
	graph g;
	g.addVertex("1");
	g.addVertex("2");
	g.addVertex("3");
	g.addVertex("4");

	g.connect("1", "2");
	g.connect("1", "4");

	g.connect("2", "1");
	g.connect("4", "1");

	g.connect("3", "2");
	g.connect("2", "3");


	g.DFS("1");
	return EXIT_SUCCESS;
}