#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>
#include <vld.h>

#include "MenuAVLTree.hpp"
constexpr int indentTerm = 4;


int GetElementConsoleAVLTree()
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
		//TODO: Const
		PrintTree(node->Right, indent + indentTerm);
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
		PrintTree(node->Left, indent + indentTerm);
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
		int valueForMenu = GetElementConsoleAVLTree();
		
		switch (static_cast<MenuAVLTreeOption>(valueForMenu))
		{
			case MenuAVLTreeOption::Add:
			{
				std::cout << "Enter value: ";
				valueForTree = GetElementConsoleAVLTree();
				tree->RootNode = Insert(tree->RootNode, valueForTree);
				break;
			}
			case MenuAVLTreeOption::Remove:
			{
				std::cout << "Enter value: ";
				valueForTree = GetElementConsoleAVLTree();
				tree->RootNode = Remove(tree->RootNode, valueForTree);
				break;
			}
			case MenuAVLTreeOption::Find:
			{
				std::cout << "Enter value: ";
				valueForTree = GetElementConsoleAVLTree();
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
			case MenuAVLTreeOption::Exit:
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
