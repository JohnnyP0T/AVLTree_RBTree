#pragma once
#ifndef RBTREE_H
#define RBTREE_H

/// @brief Цвет узла.
enum class Color 
{
	Red,
	Black,
	DoubleBlack
};

/// @brief Узел Красно-черного дерева.
struct Node
{
	int Data;
	Color Color		= Color::Red;
	Node* Left		= nullptr;
	Node* Right		= nullptr;
	Node* Parent	= nullptr;
};

/// @brief Красно-черное дерево.
struct RBTree
{
	Node* Root = nullptr;
};

/// @brief Левый поворот.
/// @param root Корень
/// @param node Повторт вокруг узла.
void RotateLeft(Node*& root, Node*& node);

/// @brief Правый поворот.
/// @param root Корень
/// @param node Повторт вокруг узла.
void RotateRight(Node*& root, Node*& node);

/// @brief Балансировка вставки.
/// @param root Корень.
/// @param node Вставляемый узел.
void FixInsertRBTree(Node*& root, Node*& node);

/// @brief Балансировка удаления.
/// @param root Корень.
/// @param node Удаляемый узел.
void FixDeleteRBTree(Node*& root, Node*& node);

/// @brief Получить цвет.
/// @param node Узел.
/// @return		Цвет.
Color GetColor(Node* node);

/// @brief Установить Цвет.
/// @param node		Узел.
/// @param color	Цвет.
void SetColor(Node*& node, Color color);

/// @brief Вставка значения.
/// @param root		Корень
/// @param value	Значение.
void InsertValue(Node*& root, int value);

/// @brief Вставка.
/// @param root Корень.
/// @param node Узел.
/// @return		Корень.
Node* InsertNode(Node*& root, Node*& node);

/// @brief Удаление.
/// @param root Корень.
/// @param data Значение.
/// @return		Корень.
Node* DeleteNode(Node*& root, int data);

/// @brief Удаление по значению.
/// @param root Корень
/// @param data Значение.
void DeleteValue(Node*& root, int data);

/// @brief Минимальное значение.
/// @param node Узел.
/// @return		Узел с минимальным значением.
Node* MinValueNode(Node*& node);

/// @brief Поиск.
/// @param node Узел.
/// @param data Значение.
/// @return		Узел с значением data.
Node* Find(Node* node, int data);

/// @brief Удаление дерева.
/// @param node Узел.
void FreeTree(Node* node);

#endif //RBTREE_H