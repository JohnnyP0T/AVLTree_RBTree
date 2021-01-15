#pragma once

#ifndef MENUAVLTREE_H
#define MENUAVLTREE_H

#include "AVLTree.hpp"

/// @brief ������������ ��� ����.
enum class MenuAVLTreeOption
{
	Add		= 1,
	Remove	= 2,
	Find	= 3,
	Exit	= 4
};


/// @brief  ��������� �������������� �������� � �������.
/// @return ���������� �������.
int GetElementConsoleAVLTree();

/// @brief ������ ������.
/// @param node	  ������.
/// @param indent ������.
void PrintTree(AVLNode* node, int indent);

/// @brief ���� ��� ��� ������.
/// @param tree ������.
void Menu(AVLtree* tree);

/// @brief ������ �����.
/// @param text ����� �����.
void SetColor(int text);


#endif //MENUAVLTREE_H
