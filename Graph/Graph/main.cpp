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
	g.addVertex("6");

	g.connect("0", "3");

	g.connect("1", "0");
	g.connect("1", "5");

	g.connect("5", "4");
	g.connect("5", "2");
	g.connect("5", "6");

	g.connect("6", "0");

	g.graphSquare();
	g.printMatrix();
	return EXIT_SUCCESS;
}