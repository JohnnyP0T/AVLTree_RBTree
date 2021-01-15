#pragma once

#ifndef MENURBTREE_H
#define MENURBTREE_H

#include "RBTree.hpp"

/// @brief Перечисление для меню.
enum class MenuRBTreeOption
{
	Add		= 1,
	Remove	= 2,
	Find	= 3,
	Exit	= 4
};


/// @brief  Получение целочисленного элемента с консоли.
/// @return Полученный элемент.
int GetElementConsoleRBTree();

/// @brief Печать дерева.
/// @param node	  Корень.
/// @param indent Отступ.
void PrintTree(Node* node, int indent);

/// @brief Меню для Красно-черного дерева.
/// @param tree Дерево.
void Menu(RBTree* tree);

/// @brief Замена цвета.
/// @param text Номер цвета.
void SetColor(int text);


#endif //MENURBTREE_H
