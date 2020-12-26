#include <exception>

#include "AVLTree.hpp"


void InitializeTree(AVLtree*& tree)
{
	tree->RootNode = nullptr;
}


size_t GetHeight(AVLNode* treeNode)
{
	return treeNode ? treeNode->Height : 0;
}


int GetBalanceFactor(AVLNode* treeNode)
{
	return static_cast<int>(GetHeight(treeNode->Right) - GetHeight(treeNode->Left));
}


void FixHeight(AVLNode* treeNode)
{
	size_t heightLeft = GetHeight(treeNode->Left);
	size_t heightRight = GetHeight(treeNode->Right);
	treeNode->Height = (heightLeft > heightRight ? heightLeft : heightRight) + 1;
}


AVLNode* RotateLeft(AVLNode* treeNode)
{
	AVLNode* current = treeNode->Right;
	
	//Выполняем вращение.
	treeNode->Right = current->Left;
	current->Left = treeNode;
	
	//Обновляем веса.
	FixHeight(treeNode);
	FixHeight(current);
	
	//Возвращаем новый корень.
	return current;
}


AVLNode* RotateRight(AVLNode* treeNode)
{
	AVLNode* current = treeNode->Left;
	
	//Выполняем вращение.
	treeNode->Left = current->Right;
	current->Right = treeNode;

	//Обновляем веса.
	FixHeight(treeNode);
	FixHeight(current);

	//Возвращаем новый корень.
	return current;
}


AVLNode* Balance(AVLNode* treeNode)
{
	FixHeight(treeNode);
	if(GetBalanceFactor(treeNode) == 2)
	{
		if(GetBalanceFactor(treeNode->Right) < 0)
		{
			treeNode->Right = RotateRight(treeNode->Right);
		}
		return RotateLeft(treeNode);
	}

	if(GetBalanceFactor(treeNode) == -2)
	{
		if(GetBalanceFactor(treeNode->Left) >  0)
		{
			treeNode->Left = RotateLeft(treeNode->Left);
		}
		return RotateRight(treeNode);
	}
	
	// Балансировка не нужна.
	return treeNode; 
}


AVLNode* Insert(AVLNode* treeNode, const int key)
{
	if(!treeNode)
	{
		treeNode = new AVLNode;
		treeNode->Key = key;
		return treeNode;
	}

	if(key < treeNode->Key)
	{
		treeNode->Left = Insert(treeNode->Left, key);
	}
	else
	{
		treeNode->Right = Insert(treeNode->Right, key);
	}

	return Balance(treeNode);
}


AVLNode* FindMinimal(AVLNode* treeNode)
{
	return treeNode->Left ? FindMinimal(treeNode->Left) : treeNode;
}


AVLNode* RemoveMinimal(AVLNode* treeNode)
{
	if(treeNode->Left == nullptr)
	{
		return treeNode->Right;
	}

	treeNode->Left = RemoveMinimal(treeNode->Left);

	return Balance(treeNode);
}


AVLNode* Remove(AVLNode* treeNode, const int key)
{
	if(!treeNode)
	{
		return nullptr;
	}

	if (key < treeNode->Key)
	{
		treeNode->Left = Remove(treeNode->Left, key);
	}
	else if (key > treeNode->Key)
	{
		treeNode->Right = Remove(treeNode->Right, key);
	}
	else //  k == p->key 
	{
		AVLNode* leftPoint = treeNode->Left;
		AVLNode* rightPoint = treeNode->Right;
		delete treeNode;
		if(!rightPoint)
		{
			return leftPoint;
		}

		AVLNode* minimal = FindMinimal(rightPoint);
		minimal->Right = RemoveMinimal(rightPoint);
		minimal->Left = leftPoint;

		return Balance(minimal);
	}

	return Balance(treeNode);
}


AVLNode* Find(AVLNode* treeNode, const int key)
{
	if(treeNode == nullptr)
	{
		throw std::exception("Does not exist\n");
	}

	if(treeNode->Key == key)
	{
		return treeNode;
	}

	if(treeNode->Key > key)
	{
		return Find(treeNode->Left, key);
	}

	return Find(treeNode->Right, key);
}


void FreeTree(AVLNode* treeNode)
{
	if(treeNode == nullptr)
	{
		return;
	}

	FreeTree(treeNode->Left);
	FreeTree(treeNode->Right);
	delete treeNode;
}
