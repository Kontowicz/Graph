#include "graph.h"

int main()
{
	graph g;
	for(int i=0; i<17; i++)
	{
		g.addVertex(std::to_string(i));
	}
	

	//g.connectOriented("0", "1");
	//g.connectOriented("0", "2");
	//g.connectOriented("0", "3");

	//g.connectOriented("1", "0");
	//g.connectOriented("1", "2");
	//g.connectOriented("1", "14");

	//g.connectOriented("2", "0");
	//g.connectOriented("2", "1");


	//g.connectOriented("3", "0");



	//g.connectOriented("4", "12");
	//g.connectOriented("4", "11");

	//g.connectOriented("5", "6");
	//g.connectOriented("5", "9");


	//g.connectOriented("6", "7");
	//g.connectOriented("6", "8");
	//g.connectOriented("6", "5");

	//g.connectOriented("7", "6");

	//g.connectOriented("8", "6");

	//g.connectOriented("9", "5");

	//g.connectOriented("10", "15");

	//g.connectOriented("11", "4");
	//g.connectOriented("11", "15");

	//g.connectOriented("12", "4");
	//g.connectOriented("12", "15");

	//g.connectOriented("13", "14");
	//g.connectOriented("13", "16");

	//g.connectOriented("14", "1");
	//g.connectOriented("14", "16");
	//g.connectOriented("14", "13");

	//g.connectOriented("15", "10");
	//g.connectOriented("15", "11");
	//g.connectOriented("15", "12");

	//g.connectOriented("16", "14");
	//g.connectOriented("16", "13");



	//g.bridge();

	g.connectOriented("1", "2");
	g.connectOriented("1", "3");
	g.connectOriented("2", "1");
	g.connectOriented("3", "1");
	g.removeEdge(1, 2);

	//g.printMatrix();
	return EXIT_SUCCESS;
}