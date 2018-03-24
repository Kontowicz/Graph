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
	g.addVertex("7");

	g.connect("0", "1");

	g.connect("1", "2");
	g.connect("1", "3");

	g.connect("2", "3");

	g.connect("3", "4");
	g.connect("3", "5");

	g.connect("4", "5");

	g.connect("5", "6");

	g.connect("6", "7");

	g.connect("7", "0");
	g.connect("7", "4");

	g.path("0","6");
	g.printMatrix();
	return EXIT_SUCCESS;
}