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
	g.connect("0", "2");
	g.connect("0", "3");

	g.connect("1", "0");
	g.connect("1", "4");

	g.connect("2", "0");
	g.connect("2", "3");
	g.connect("2", "5");

	g.connect("3", "0");
	g.connect("3", "2");
	g.connect("3", "4");
	g.connect("3", "5");


	g.connect("4", "1");
	g.connect("4", "3");
	g.connect("4", "5");

	g.connect("5", "2");
	g.connect("5", "3");
	g.connect("5", "4");
	g.lineGraph();
	g.printMatrix();
	return EXIT_SUCCESS;
}