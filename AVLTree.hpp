#pragma once

#ifndef AVLTREE_H
#define AVLTREE_H

/// @brief Узел АВЛ дерева.
struct AVLNode
{
	int Key;
	size_t Height	= 1;
	AVLNode* Left	= nullptr;
	AVLNode* Right	= nullptr;
};

/// @brief АВЛ дерево.
struct AVLtree
{
	AVLNode* RootNode;
};

/// @brief Инициализация дерева.
/// @param tree Дерево.
void InitializeTree(AVLtree*& tree);

/// @brief Получение высоты.
/// @param treeNode Узел.
/// @return			Высота.
size_t GetHeight(AVLNode* treeNode);

/// @brief Получение фактора баланса.
/// высота правого минус высота левого.
/// @param treeNode Узел.
/// @return			Фактор баланса.
int GetBalanceFactor(AVLNode* treeNode);

/// @brief Восстановление корректного значение высоты.
/// @param treeNode Узел.
void FixHeight(AVLNode* treeNode);

/// @brief Левый поворот вокруг treeNode.
/// @param treeNode Узел.
/// @return			Новый Корень.
AVLNode* RotateLeft(AVLNode* treeNode);

/// @brief Правый поворот вокруг treeNode.
/// @param treeNode Узел.
/// @return			Новый Корень.
AVLNode* RotateRight(AVLNode* treeNode);

/// @brief Балансировка 
/// @param treeNode Узел.
/// @return			Новый Корень.
AVLNode* Balance(AVLNode* treeNode);

/// @brief Вставка.
/// @param treeNode Узел. 
/// @param key		Значение.
/// @return			Новый Корень.
AVLNode* Insert(AVLNode* treeNode, int key);

/// @brief Поиск минимума.
/// @param treeNode Узел.
/// @return			Новый Корень.
AVLNode* FindMinimal(AVLNode* treeNode);

/// @brief Удаление минимального элемента.
/// @param treeNode Узел.
/// @return			Новый Корень.
AVLNode* RemoveMinimal(AVLNode* treeNode);

/// @brief Удаление.
/// @param treeNode Узел.
/// @param key		Значение.
/// @return			Новый Корень.
AVLNode* Remove(AVLNode* treeNode, int key);

/// @brief Поиск.
/// @param treeNode Узел. 
/// @param key		Значение.
/// @return			Узел со значением key.
AVLNode* Find(AVLNode* treeNode, int key);

/// @brief Удаление дерева.
/// @param treeNode Узел корня.
void FreeTree(AVLNode* treeNode);

#endif //AVLTREE_H
