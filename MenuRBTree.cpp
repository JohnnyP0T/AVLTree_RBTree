#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>
#include <vld.h>

#include "MenuRBTree.hpp"
constexpr int indentTerm = 4;


int GetElementConsoleRBTree()
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
	if (node->Color == Color::Black)
	{
		SetColor(0);
	}
	else SetColor(4);
	std::cout << node->Data << "\n ";
	SetColor(0);
	if (node->Left)
	{
		std::cout << std::setw(indent) << ' ' << " \\\n";
		PrintTree(node->Left, indent + indentTerm);
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
		int valueForMenu = GetElementConsoleRBTree();

		switch (static_cast<MenuRBTreeOption>(valueForMenu))
		{
			case MenuRBTreeOption::Add:
			{
				std::cout << "Enter value: ";
				valueForTree = GetElementConsoleRBTree();
				InsertValue(tree->Root, valueForTree);
				break;
			}
			case MenuRBTreeOption::Remove:
			{
				std::cout << "Enter value: ";
				valueForTree = GetElementConsoleRBTree();
				DeleteValue(tree->Root, valueForTree);
				break;
			}
			case MenuRBTreeOption::Find:
			{
				std::cout << "Enter value: ";
				valueForTree = GetElementConsoleRBTree();
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
			case MenuRBTreeOption::Exit:
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