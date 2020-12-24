#pragma once

#ifndef AVLTREE_H
#define AVLTREE_H

/// @brief ���� ��� ������.
struct AVLNode
{
	int Key;
	size_t Height	= 1;
	AVLNode* Left	= nullptr;
	AVLNode* Right	= nullptr;
};

/// @brief ��� ������.
struct AVLtree
{
	AVLNode* RootNode;
};

/// @brief ������������� ������.
/// @param tree ������.
void InitializeTree(AVLtree*& tree);

/// @brief ��������� ������.
/// @param treeNode ����.
/// @return			������.
size_t GetHeight(AVLNode* treeNode);

/// @brief ��������� ������� �������.
/// ������ ������� ����� ������ ������.
/// @param treeNode ����.
/// @return			������ �������.
int GetBalanceFactor(AVLNode* treeNode);

/// @brief �������������� ����������� �������� ������.
/// @param treeNode ����.
void FixHeight(AVLNode* treeNode);

/// @brief ����� �������.
/// @param treeNode ����.
/// @return			������.
AVLNode* RotateLeft(AVLNode* treeNode);

/// @brief ������ �������.
/// @param treeNode ����.
/// @return			������.
AVLNode* RotateRight(AVLNode* treeNode);

/// @brief ������������ 
/// @param treeNode ����.
/// @return			������.
AVLNode* Balance(AVLNode* treeNode);

/// @brief �������.
/// @param treeNode ����. 
/// @param key		��������.
/// @return			������.
AVLNode* Insert(AVLNode* treeNode, int key);

/// @brief ����� ��������.
/// @param treeNode ����.
/// @return			������.
AVLNode* FindMinimal(AVLNode* treeNode);

/// @brief �������� ������������ ��������.
/// @param treeNode ����.
/// @return			������.
AVLNode* RemoveMinimal(AVLNode* treeNode);

/// @brief ��������.
/// @param treeNode ����.
/// @param key		��������.
/// @return			������.
AVLNode* Remove(AVLNode* treeNode, int key);

/// @brief �����.
/// @param treeNode ����. 
/// @param key		��������.
/// @return			���� �� ��������� key.
AVLNode* Find(AVLNode* treeNode, int key);

//TODO �������� ������ � �� ����.
/// @brief �������� ������.
/// @param treeNode ����.
void FreeTree(AVLNode* treeNode);

#endif //AVLTREE_H
