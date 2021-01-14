#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>
#include <vld.h>

#include "Menu.hpp"


int GetElementConsole()
{
	while (true)
	{
		std::string inputValue;
		std::cout << "Enter menu Value: ";
		std::getline(std::cin, inputValue);

		try
		{
			size_t length;
			const int number = stoi(inputValue, &length);
			if (length == inputValue.length())
			{
				return number;
			}
		}
		catch (std::exception& e)
		{
			std::cout << inputValue << " is not a number! " << e.what() << std::endl;
		}
	}
}


void PrintTree(AVLNode* node, const int indent)
{
	if (node == nullptr)
	{
		return;
	}

	if (node->Right)
	{
		PrintTree(node->Right, indent + 4);
	}

	if (indent)
	{
		std::cout << std::setw(indent) << ' ';
	}

	if (node->Right)
	{
		std::cout << " /\n" << std::setw(indent) << ' ';
	}

	std::cout << node->Key << "\n ";
	if (node->Left)
	{
		std::cout << std::setw(indent) << ' ' << " \\\n";
		PrintTree(node->Left, indent + 4);
	}
}


void SetColor(const int text)
{
	const int background = 7;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
void PrintTree(Node* node, const int indent)
{
	if (node == nullptr)
	{
		return;
	}

	if (node->Right)
	{
		PrintTree(node->Right, indent + 4);
	}

	if (indent)
	{
		std::cout << std::setw(indent) << ' ';
	}

	if (node->Right)
	{
		std::cout << " /\n" << std::setw(indent) << ' ';
	}
	if(node->Color == Color::Black)
	{
		SetColor(0);
	}
	else SetColor(4);
	std::cout << node->Data << "\n ";
	SetColor(0);
	if (node->Left)
	{
		std::cout << std::setw(indent) << ' ' << " \\\n";
		PrintTree(node->Left, indent + 4);
	}
}



void Menu(AVLtree* tree)
{
	InitializeTree(tree);
	int valueForTree;
	for (;;)
	{
		PrintTree(tree->RootNode, 3);
		std::cout << "\n+===============================AVLTree===============================+\n"
			<< "1 - Add\n"
			<< "2 - Remove\n"
			<< "3 - Find\n"
			<< "4 - Exit\n";
		int valueForMenu = GetElementConsole();
		
		switch (static_cast<MenuTreeOption>(valueForMenu))
		{
			case MenuTreeOption::Add:
			{
				std::cout << "Enter value: ";
				valueForTree = GetElementConsole();
				tree->RootNode = Insert(tree->RootNode, valueForTree);
				break;
			}
			case MenuTreeOption::Remove:
			{
				std::cout << "Enter value: ";
				valueForTree = GetElementConsole();
				tree->RootNode = Remove(tree->RootNode, valueForTree);
				break;
			}
			case MenuTreeOption::Find:
			{
				std::cout << "Enter value: ";
				valueForTree = GetElementConsole();
				try
				{
					std::cout << Find(tree->RootNode, valueForTree)->Key << std::endl;
				}
				catch (std::exception& exceptionFind)
				{
					std::cout << exceptionFind.what();
				}
				system("pause");
				break;
			}
			case MenuTreeOption::Exit:
			{
				system("cls");
				FreeTree(tree->RootNode);
				return;
			}
			
			default:
			{
				std::cout << "Invalid Value\n";
				system("pause");
				break;
			}
		}
		system("cls");
	}
}


void Menu(RBTree* tree)
{
	int valueForTree;
	for (;;)
	{
		PrintTree(tree->Root, 3);
		std::cout << "\n+===============================RBTree===============================+\n"
			<< "1 - Add\n"
			<< "2 - Remove\n"
			<< "3 - Find\n"
			<< "4 - Exit\n";
		int valueForMenu = GetElementConsole();

		switch (static_cast<MenuTreeOption>(valueForMenu))
		{
			case MenuTreeOption::Add:
			{
				std::cout << "Enter value: ";
				valueForTree = GetElementConsole();
				InsertValue(tree->Root, valueForTree);
				break;
			}
			case MenuTreeOption::Remove:
			{
				std::cout << "Enter value: ";
				valueForTree = GetElementConsole();
				DeleteValue(tree->Root, valueForTree);
				break;
			}
			case MenuTreeOption::Find:
			{
				std::cout << "Enter value: ";
				valueForTree = GetElementConsole();
				try
				{
					std::cout << Find(tree->Root, valueForTree)->Data << std::endl;
				}
				catch (std::exception& exceptionFind)
				{
					std::cout << exceptionFind.what();
				}
				system("pause");
				break;
			}
			case MenuTreeOption::Exit:
			{
				system("cls");
				FreeTree(tree->Root);
				return;
			}

			default:
			{
				std::cout << "Invalid Value\n";
				system("pause");
				break;
			}
		}
		system("cls");
	}
}