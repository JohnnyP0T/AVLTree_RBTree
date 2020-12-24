#include "iostream"

#include "Menu.hpp"


int main()
{
	SetColor(0);
	int valueForMenu;
	for (;;)
	{
		std::cout << "1 - AVLTree\n"
			<< "2 - RBTree\n"
			<< "0 - Exit\n";
		valueForMenu = GetElementConsole();
		switch (valueForMenu)
		{
			case 1:
			{
				AVLtree* tree = new AVLtree;
				Menu(tree);
				delete tree;
				break;
			}
			case 2:
			{
				RBTree* tree = new RBTree;
				Menu(tree);
				delete tree;
				break;
			}
			case 0:
			{
				return 0;
			}
				
			default:
			{
				std::cout << "Invalid value\n";
				system("pause");
				break;
			}
		}
	}
}