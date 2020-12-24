#pragma once

#ifndef MENU_H
#define MENU_H

#include "AVLTree.hpp"
#include "RBTree.hpp"

/// @brief Перечисление для меню.
enum class MenuTreeOption
{
	Add		= 1,
	Remove	= 2,
	Find	= 3,
	Exit	= 4
};


/// @brief  Получение целочисленного элемента с консоли.
/// @return Полученный элемент.
int GetElementConsole();

/// @brief Печать дерева.
/// @param node				Корень.
/// @param indent			Отступ.
void PrintTree(AVLNode* node, int indent);

/// @brief Меню для АВЛ дерева.
/// @param tree Дерево.
void Menu(AVLtree* tree);

/// @brief Меню для Красно-черного дерева.
/// @param tree Дерево.
void Menu(RBTree* tree);

/// @brief Замена цвета.
/// @param text Номер цвета.
void SetColor(int text);

#endif //MENU_H
