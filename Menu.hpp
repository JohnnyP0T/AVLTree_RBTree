#pragma once

#ifndef MENU_H
#define MENU_H

#include "AVLTree.hpp"
#include "RBTree.hpp"

/// @brief ������������ ��� ����.
enum class MenuTreeOption
{
	Add		= 1,
	Remove	= 2,
	Find	= 3,
	Exit	= 4
};


/// @brief  ��������� �������������� �������� � �������.
/// @return ���������� �������.
int GetElementConsole();

/// @brief ������ ������.
/// @param node				������.
/// @param indent			������.
void PrintTree(AVLNode* node, int indent);

/// @brief ���� ��� ��� ������.
/// @param tree ������.
void Menu(AVLtree* tree);

/// @brief ���� ��� ������-������� ������.
/// @param tree ������.
void Menu(RBTree* tree);

/// @brief ������ �����.
/// @param text ����� �����.
void SetColor(int text);

#endif //MENU_H
