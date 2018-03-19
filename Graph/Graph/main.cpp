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
	
	g.connect("0", "1");
	g.connect("0", "5");

	g.connect("2", "1");
	g.connect("2", "3");

	g.connect("3", "4");

	g.connect("4", "1");
	g.connect("4", "5");

	g.connect("5", "1");
	g.connect("5", "2");
	

	g.DFS("0");
	return EXIT_SUCCESS;
}