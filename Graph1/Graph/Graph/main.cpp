
#include "graph.h"
int main()
{
	short s;
	graph graph;
	do
	{
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
		if (std::cin >> s);
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		switch (s)
		{
		case 1:
		{
			std::string name;
			std::cout << "Enter vertex name: ";
			if (std::cin >> name)
			{
				graph.addVertex(name);
			}
			else
			{
				std::cin.clear();
				//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}

			break;
		}
		case 2:
		{
			std::string name;
			std::cout << "Enter name: ";
			if (std::cin >> name)
			{
				graph.removeVertex(name);
			}
			else
			{
				std::cin.clear();
				//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}

			break;
		}
		case 3:
		{
			std::cout << "1. Edge with domain weight (0)\n";
			std::cout << "2. Edge with specific weight \n";
			short in;
			if (std::cin >> in)
			{
#pragma region connect
				switch (in)
				{
					case 1:
						{
						std::string name;
						std::cout << "Enter name: ";
						if (std::cin >> name)
						{
							std::string name1;
							std::cout << "Enter name: ";
							if (std::cin >> name1)
							{
								graph.connectUnoriented(name,name1);
							}
							else
							{
								std::cin.clear();
							}
						}
						else
						{
							std::cin.clear();
						}
						break;
						}
					case 2:
						{
						std::string name;
						std::cout << "Enter name: ";
						if (std::cin >> name)
						{
							std::string name1;
							std::cout << " enter second name: ";
							if (std::cin >> name1)
							{
								int we;
								std::cout << " enter nweight: ";
								if (std::cin >> we)
								{
									graph.connectUnoriented(name, name1, we);
								}
								else
								{
									std::cin.clear();
									std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
								}
							}
							else
							{
								std::cin.clear();
							}
						}
						else
						{
							std::cin.clear();
						}
							break;
						}
				}
#pragma endregion 
			}

		}
		}
	} while (s != 0);
}
