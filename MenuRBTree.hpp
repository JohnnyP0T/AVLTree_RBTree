#pragma once

#ifndef MENURBTREE_H
#define MENURBTREE_H

#include "RBTree.hpp"

/// @brief ������������ ��� ����.
enum class MenuRBTreeOption
{
	Add		= 1,
	Remove	= 2,
	Find	= 3,
	Exit	= 4
};


/// @brief  ��������� �������������� �������� � �������.
/// @return ���������� �������.
int GetElementConsoleRBTree();

/// @brief ������ ������.
/// @param node	  ������.
/// @param indent ������.
void PrintTree(Node* node, int indent);

/// @brief ���� ��� ������-������� ������.
/// @param tree ������.
void Menu(RBTree* tree);

/// @brief ������ �����.
/// @param text ����� �����.
void SetColor(int text);


#endif //MENURBTREE_H
