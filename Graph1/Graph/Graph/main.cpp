#include "graph.h"

std::string getDataString()
{
	std::string toReturn = "";
	bool isOk = false;
	do
	{
		if (std::cin >> toReturn)
		{
			isOk = true;
		}
		else
		{
			std::cout << "Error in input data!\nTry again: ";
			std::cin.clear();
		}
	} while (!isOk);

	return toReturn;
}

int getDataInt()
{
	int toReturn=0;
	bool isOk = false;
	do
	{
		if(std::cin>>toReturn)
		{
			isOk = true;
		}
		else
		{
			std::cout << "Error in input data!\nTry again: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (!isOk);

	return toReturn;
}

int getDataInt(int min, int max)
{
	int toReturn = 0;
	bool isOk = false;
	do
	{
		if (std::cin >> toReturn)
		{
			isOk = true;
			if (toReturn<0 || toReturn>max)
				isOk = false;
		}
		else
		{
			std::cout << "Error in input data!\nTry again: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (!isOk);

	return toReturn;
}

void printVector(std::vector<int>&wek)
{
	for (int i = 0; i < wek.size(); ++i)
	{
		if (i + 1 % 10 == 0)
			std::cout << "\n";

		std::cout << wek[i] << " ";
	}
}

void wait()
{
	std::cout << "\nPress enter to continue...";
	getchar();
	getchar();
}
int main()
{
	short s;
	graph graph;
	do
	{
#pragma region MENU
		std::cout << "***MENU***\n";
		std::cout << "1. Make new vertex\n";
		std::cout << "2. Remove vertex\n";
		std::cout << "3. Connect vertex unoriented\n";
		std::cout << "4. Connect veretex orinted\n";
		std::cout << "5. Remove edge\n";
		std::cout << "6. Vertex degree\n";
		std::cout << "7. Graph order\n";
		std::cout << "8. Graph size\n";
		std::cout << "9. Graph degree\n";
		std::cout << "10. Are connected\n";
		std::cout << "11. Is Complete\n";
		std::cout << "12. Print all vertex name\n";
		std::cout << "13. Graph transposition\n";
		std::cout << "14. Print matrix\n";
		std::cout << "15. DFS\n";
		std::cout << "16. Graph square\n";
		std::cout << "17. BFS\n";

#pragma endregion 
		s = getDataInt();
		switch (s)
		{
			case 1:
			{
				std::cout << "Enter vertex name: ";
				graph.addVertex(getDataString());
					if(graph.error)
					{
						std::cout << "Error";
					}
				break;
			}
			case 2:
			{

				std::cout << "Enter name: ";
				graph.removeVertex(getDataString());
				break;
			}
			case 3:
			{
				std::cout << "1. Edge with domain weight (0)\n";
				std::cout << "2. Edge with specific weight \n";
				switch (getDataInt()) {
					case 1: {
						std::cout << "Enter name, second name vertex, domain weight 0: ";
						graph.connectUnoriented(getDataString(), getDataString());
						break;
					}
					case 2: {
						std::cout << "Enter name, second name vertex, weight: ";
						graph.connectUnoriented(getDataString(), getDataString(), getDataInt());
						break;
					}
					default: {
						std::cout << "Error\n";
						break;
					}
				}
					break;
			}
			case 4:
			{
				std::cout << "1. Edge with domain weight (0)\n";
				std::cout << "2. Edge with specific weight \n";
				switch (getDataInt()) {
					case 1: {
						std::cout << "Enter name, second name vertex, domain weight 0: ";
						graph.connectOriented(getDataString(), getDataString());
						break;
					}
					case 2: {
						std::cout << "Enter name, second name vertex, weight: ";
						graph.connectOriented(getDataString(), getDataString(), getDataInt());
						break;
					}
					default: {
						std::cout << "Error\n";
						break;
					}
				}
				break;
			}
			case 5:
			{
				std::cout << "Enter name, second name of vertex: ";
				graph.removeEdge(getDataString(), getDataString());
				break;
			}
			case 6:
			{
				std::cout << "Enter vertex name: ";
				graph.vertexDegree(getDataString());
				break;
			}
			case 7:
			{
				std::cout<<"Vertex in graph: "<<graph.graphOrder()<<"\n";
				break;
			}
			case 8:
			{
				std::cout << "Graph size: " << graph.graphSize() << "\n";
				break;
			}
			case 9:
			{
				std::cout << "Graph degree: " << graph.graphDegree() << "\n";
				break;
			}
			case 10:
			{
				std::cout << "Enter name and second name of vertex: ";
				std::string result = graph.areConnected(getDataString(), getDataString()) ? "Yes" : "No";
				std::cout << result << "\n";
				break;		
			}
			case 11:
			{
				std::string result = graph.isComplete() ? "Yes" : "No";
				std::cout << result << "\n";
				break;
			}
			case 12:
			{
				std::cout << "Vertex name:\n";
				std::vector<std::string> result = graph.getName();
				int counter = 0;
					for (auto it = result.begin(); it!=result.end(); it++)
					{
						std::cout.fill('0');
						std::cout.width(std::to_string(result.size()).size());
						std::cout << counter++;
						std::cout << " " << *it << "\n";
					}
				break;
			}
			case 13:
			{
				graph.transposition();
				break;
			}
			case 14:
			{
				graph.saveAsMarix();
				auto m = graph.getMatrix();
				std::cout.width(3);
				std::cout.fill(' ');
				std::cout << std::left << "";
				for(int i=0; i<m.size(); i++)
				{
					std::cout.width(3);
					std::cout.fill(' ');
					std::cout << std::left<<i;
				}
				std::cout << "\n";
				for(int i=0; i<m.size(); i++)
				{
					std::cout.width(3);
					std::cout.fill(' ');
					std::cout << std::left << i;
					for(int j=0; j<m[i].size(); j++)
					{
						std::cout.width(3);
						std::cout.fill(' ');
						std::cout << std::left << m[i][j];
					}
					std::cout << "\n";
				}
				break;
			}
			case 15:
			{
				std::vector<int> tmp;
				graph.resetVisited();
				std::cout << "Enter start vertex name: ";
				int pos = graph.findVertex(getDataString());
				while (pos<0 || pos>graph.matrix.size())
				{
					pos = graph.findVertex(getDataString());
				}
				graph.depthFirstSearch(pos, tmp);
				std::cout << "DFS:\n";
				printVector(tmp);
				break;
			}
			case 16:
			{
				graph.graphSquare();
				break;
			}
			case 17:
			{
				std::cout << "Enter start vertex name: ";
				int pos = graph.findVertex(getDataString());
				while (pos<0 || pos>graph.vertexInGraph.size())
				{
					pos = graph.findVertex(getDataString());
				}
				std::vector<int> tmp;
				graph.breadthFirstSearch(pos, tmp);
				std::cout << "BFS:\n";
				printVector(tmp);
				break;
			}
			
			default:
			{
				std::cout << "Error";
			}
		}
		std::cin.clear();
		wait();
		system("cls");
	} while (s != 0);
}
