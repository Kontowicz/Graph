#include "graph.h"

int main()
{
	graph g;
	for(int i=0; i<17; i++)
	{
		g.addVertex(std::to_string(i));
	}
	g.connectUnoriented("0", "1");
	g.connectUnoriented("0", "2");
	g.connectUnoriented("0", "3");

	g.connectUnoriented("1", "2");
	g.connectUnoriented("1", "14");

	g.connectUnoriented("14", "13");
	g.connectUnoriented("14", "16");
	g.connectUnoriented("13", "16");

	g.connectUnoriented("7", "6");
	g.connectUnoriented("6", "8");
	g.connectUnoriented("6", "5");
	g.connectUnoriented("9", "5");

	g.connectUnoriented("10", "15");
	g.connectUnoriented("15", "11");
	g.connectUnoriented("15", "12");
	g.connectUnoriented("11", "4");
	g.connectUnoriented("12", "4");

	g.connectedComponent();

	g.printMatrix();
	return EXIT_SUCCESS;
}