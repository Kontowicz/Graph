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

	g.connectUnoriented("1", "0");
	g.connectUnoriented("1", "2");
	g.connectUnoriented("1", "9");
	g.connectUnoriented("1", "14");

	g.connectUnoriented("2", "0");
	g.connectUnoriented("2", "1");
	g.connectUnoriented("2", "6");

	g.connectUnoriented("3", "0");
	g.connectUnoriented("3", "4");
	g.connectUnoriented("3", "6");

	g.connectUnoriented("4", "3");
	g.connectUnoriented("4", "12");
	g.connectUnoriented("4", "13");

	g.connectUnoriented("5", "6");
	g.connectUnoriented("5", "9");

	g.connectUnoriented("6", "2");
	g.connectUnoriented("6", "3");
	g.connectUnoriented("6", "7");
	g.connectUnoriented("6", "12");
	g.connectUnoriented("6", "8");
	g.connectUnoriented("6", "5");

	g.connectUnoriented("7", "13");
	g.connectUnoriented("7", "6");

	g.connectUnoriented("10", "11");
	g.connectUnoriented("10", "14");
	g.connectUnoriented("10", "15");

	g.connectUnoriented("11", "10");
	g.connectUnoriented("11", "16");

	g.connectUnoriented("12", "6");
	g.connectUnoriented("12", "4");
	g.connectUnoriented("12", "16");

	g.connectUnoriented("14", "1");
	g.connectUnoriented("14", "10");
	g.connectUnoriented("14", "15");

	g.connectUnoriented("15", "14");
	g.connectUnoriented("15", "10");

	g.connectUnoriented("16", "11");
	g.connectUnoriented("16", "12");
	g.connectUnoriented("16", "13");

	g.depthFirstSpanningTree();

	//g.printMatrix();
	return EXIT_SUCCESS;
}