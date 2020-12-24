#pragma once
#ifndef RBTREE_H
#define RBTREE_H

/// @brief ���� ����.
enum class Color 
{
	Red,
	Black,
	DoubleBlack
};

/// @brief ���� ������-������� ������.
struct Node
{
	int Data;
	Color Color		= Color::Red;
	Node* Left		= nullptr;
	Node* Right		= nullptr;
	Node* Parent	= nullptr;
};

/// @brief ������-������ ������.
struct RBTree
{
	Node* Root = nullptr;
};

/// @brief ����� �������.
/// @param root ������
/// @param node ������� ������ ����.
void RotateLeft(Node*& root, Node*& node);

/// @brief ������ �������.
/// @param root ������
/// @param node ������� ������ ����.
void RotateRight(Node*& root, Node*& node);

/// @brief ������������ �������.
/// @param root ������.
/// @param node ����������� ����.
void FixInsertRBTree(Node*& root, Node*& node);

/// @brief ������������ ��������.
/// @param root ������.
/// @param node ��������� ����.
void FixDeleteRBTree(Node*& root, Node*& node);

/// @brief �������� ����.
/// @param node ����.
/// @return		����.
Color GetColor(Node* node);

/// @brief ���������� ����.
/// @param node		����.
/// @param color	����.
void SetColor(Node*& node, Color color);

/// @brief ������� ��������.
/// @param root		������
/// @param value	��������.
void InsertValue(Node*& root, int value);

/// @brief �������.
/// @param root ������.
/// @param node ����.
/// @return		������.
Node* InsertNode(Node*& root, Node*& node);

/// @brief ��������.
/// @param root ������.
/// @param data ��������.
/// @return		������.
Node* DeleteNode(Node*& root, int data);

/// @brief �������� �� ��������.
/// @param root ������
/// @param data ��������.
void DeleteValue(Node*& root, int data);

/// @brief ����������� ��������.
/// @param node ����.
/// @return		���� � ����������� ���������.
Node* MinValueNode(Node*& node);

/// @brief �����.
/// @param node ����.
/// @param data ��������.
/// @return		���� � ��������� data.
Node* Find(Node* node, int data);

/// @brief �������� ������.
/// @param node ����.
void FreeTree(Node* node);

#endif //RBTREE_H