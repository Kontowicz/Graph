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
		std::cout << "13. Get all edges of vertex\n";
#pragma endregion 
		s = getDataInt();
		switch (s)
		{
			case 1:
			{
				std::cout << "Enter vertex name: ";
				graph.addVertex(getDataString());
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
			}
		}
	} while (s != 0);
}
