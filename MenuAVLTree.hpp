#pragma once

#ifndef MENUAVLTREE_H
#define MENUAVLTREE_H

#include "AVLTree.hpp"

/// @brief Перечисление для меню.
enum class MenuAVLTreeOption
{
	Add		= 1,
	Remove	= 2,
	Find	= 3,
	Exit	= 4
};


/// @brief  Получение целочисленного элемента с консоли.
/// @return Полученный элемент.
int GetElementConsoleAVLTree();

/// @brief Печать дерева.
/// @param node	  Корень.
/// @param indent Отступ.
void PrintTree(AVLNode* node, int indent);

/// @brief Меню для АВЛ дерева.
/// @param tree Дерево.
void Menu(AVLtree* tree);

/// @brief Замена цвета.
/// @param text Номер цвета.
void SetColor(int text);


#endif //MENUAVLTREE_H
