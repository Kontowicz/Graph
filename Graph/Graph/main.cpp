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

	g.connectOriented("0", "1");

	g.connectOriented("1", "2");
	g.connectOriented("1", "3");

	g.connectOriented("2", "3");

	g.connectOriented("3", "4");
	g.connectOriented("3", "5");

	g.connectOriented("4", "5");

	g.connectOriented("5", "6");

	g.connectOriented("6", "7");

	g.connectOriented("7", "0");
	g.connectOriented("7", "4");

	g.path("0","6");
	g.printMatrix();
	return EXIT_SUCCESS;
}