#include <exception>


#include "RBTree.hpp"


Color GetColor(Node* node)
{
	if(node == nullptr)
	{
		return Color::Black;
	}
	return node->Color;
}


void SetColor(Node*& node, const Color color)
{
	if(node == nullptr)
	{
		return;
	}
	node->Color = color;
}


void InsertValue(Node*& root, const int value)
{
	Node* node = new Node;
	node->Data = value;
	root = InsertNode(root, node);
	FixInsertRBTree(root, node);
}


Node* InsertNode(Node*& root, Node*& node)
{
	if(root == nullptr)
	{
		return node;
	}

	if(node->Data < root->Data)
	{
		root->Left = InsertNode(root->Left, node);
		root->Left->Parent = root;
	}
	else 
	{
		root->Right = InsertNode(root->Right, node);
		root->Right->Parent = root;
	}

	return root;
}


void RotateLeft(Node*& root, Node*& node)
{
	Node* rightChild = node->Right;
	node->Right = rightChild->Left;

	if(node->Right != nullptr)
	{
		node->Right->Parent = node;
	}

	rightChild->Parent = node->Parent;

	if(node->Parent == nullptr)
	{
		root = rightChild;
	}
	else if(node == node->Parent->Left)
	{
		node->Parent->Left = rightChild;
	}
	else
	{
		node->Parent->Right = rightChild;
	}

	rightChild->Left = node;
	node->Parent = rightChild;
}


void RotateRight(Node*& root, Node*& node)
{
	Node* leftChild = node->Left;
	node->Left = leftChild->Right;

	if(node->Left != nullptr)
	{
		node->Left->Parent = node;
	}

	leftChild->Parent = node->Parent;

	if(node->Parent == nullptr)
	{
		root = leftChild;
	}
	else if(node == node->Parent->Left)
	{
		node->Parent->Left = leftChild;
	}
	else
	{
		node->Parent->Right = leftChild;
	}

	leftChild->Right = node;
	node->Parent = leftChild;
}

void FixInsertRBTree(Node*& root, Node*& node)
{
	Node* parent = nullptr;
	Node* grandParent = nullptr;
	while (node != root && 
		GetColor(node) == Color::Red && 
		GetColor(node->Parent) == Color::Red)
	{
		parent = node->Parent;
		grandParent = parent->Parent;
		if(parent == grandParent->Left)
		{
			Node* uncle = grandParent->Right;
			if(GetColor(uncle) == Color::Red)
			{
				SetColor(uncle, Color::Black);
				SetColor(parent, Color::Black);
				SetColor(grandParent, Color::Red);
				node = grandParent;
			}
			else
			{
				if(node == parent->Right)
				{
					RotateLeft(root, parent);
					node = parent;
					parent = node->Parent;
				}
				RotateRight(root, grandParent);
				const Color color = grandParent->Color;
				grandParent->Color = parent->Color;
				parent->Color = color;
				node = parent;
			}
		}
		else
		{
			Node* uncle = grandParent->Left;
			if(GetColor(uncle) == Color::Red)
			{
				SetColor(uncle, Color::Black);
				SetColor(parent, Color::Black);
				SetColor(grandParent, Color::Red);
				node = grandParent;
			}
			else
			{
				if(node == parent->Left)
				{
					RotateRight(root, parent);
					node = parent;
					parent = node->Parent;
				}
				RotateLeft(root, grandParent);
				const Color color = grandParent->Color;
				grandParent->Color = parent->Color;
				parent->Color = color;
				node = parent;
			}
		}
	}
	SetColor(root, Color::Black);
}


void FixDeleteRBTree(Node*& root, Node*& node)
{
	if(node == nullptr)
	{
		return;
	}

	if(node == root)
	{
		Node* current = root;
		root = root->Left ? root->Left : root->Right;
		SetColor(root, Color::Black);
		root->Parent = nullptr;
		delete current;
		return;
	}

	if (GetColor(node) == Color::Red ||
		GetColor(node->Left) == Color::Red ||
		GetColor(node->Right) == Color::Red)
	{
		Node* child = node->Left != nullptr ? node->Left : node->Right;

		if(node == node->Parent->Left)
		{
			node->Parent->Left = child;
			if(child != nullptr)
			{
				child->Parent = node->Parent;
			}
			SetColor(child, Color::Black);
			delete node;
		}
		else
		{
			node->Parent->Right = child;
			if(child != nullptr)
			{
				child->Parent = node->Parent;
			}
			SetColor(child, Color::Black);
			delete node;
		}
	}
	else
	{
		Node* sibling = nullptr;
		Node* parent = nullptr;
		Node* pointer = node;
		SetColor(pointer, Color::DoubleBlack);
		while(pointer != root && GetColor(pointer) == Color::DoubleBlack)
		{
			parent = pointer->Parent;
			if(pointer == parent->Left)
			{
				sibling = parent->Right;
				if(GetColor(sibling) == Color::Red)
				{
					SetColor(sibling, Color::Black);
					SetColor(parent, Color::Red);
					RotateLeft(root,parent);
				}
				else
				{
					if(GetColor(sibling->Left) == Color::Black && 
						GetColor(sibling->Right) == Color::Black)
					{
						SetColor(sibling, Color::Red);
						if(GetColor(parent) == Color::Red)
						{
							SetColor(parent, Color::Black);
						}
						else
						{
							SetColor(parent, Color::DoubleBlack);
						}
						pointer = parent;
					}
					else
					{
						if(GetColor(sibling->Right) == Color::Black)
						{
							SetColor(sibling->Left, Color::Black);
							SetColor(sibling, Color::Red);
							RotateRight(root, sibling);
							sibling = parent->Right;
						}
						SetColor(sibling, parent->Color);
						SetColor(parent, Color::Black);
						SetColor(sibling->Right, Color::Black);
						RotateLeft(root, parent);
						break;
					}
				}
			}
			else
			{
				sibling = parent->Left;
				if(GetColor(sibling) == Color::Red)
				{
					SetColor(sibling, Color::Black);
					SetColor(parent, Color::Red);
					RotateRight(root, parent);
				}
				else
				{
					if (GetColor(sibling->Left) == Color::Black && 
						GetColor(sibling->Right) == Color::Black)
					{
						SetColor(sibling, Color::Red);
						if(GetColor(parent) == Color::Red)
						{
							SetColor(parent, Color::Black);
						}
						else
						{
							SetColor(parent, Color::Black);
						}
						pointer = parent;
					}
					else
					{
						if(GetColor(sibling->Left) == Color::Black)
						{
							SetColor(sibling->Right, Color::Black);
							SetColor(sibling, Color::Red);
							RotateLeft(root, sibling);
							sibling = parent->Left;
						}
						SetColor(sibling, parent->Color);
						SetColor(parent, Color::Black);
						SetColor(sibling->Left, Color::Black);
						RotateRight(root, parent);
						break;
					}
				}
			}
		}
		if(node == node->Parent->Left)
		{
			node->Parent->Left = nullptr;
		}
		else
		{
			node->Parent->Right = nullptr;
		}
		delete node;
		SetColor(root, Color::Black);
	}
}


Node* DeleteNode(Node*& root, const int data)
{
	if(root == nullptr)
	{
		return root;
	}

	if(data < root->Data)
	{
		return DeleteNode(root->Left, data);
	}

	if(data > root->Data)
	{
		return DeleteNode(root->Right, data);
	}

	if(root->Left == nullptr || root->Right == nullptr)
	{
		return root;
	}

	Node* temp = MinValueNode(root->Right);
	root->Data = temp->Data;
	return DeleteNode(root->Right, temp->Data);
}


void DeleteValue(Node*& root, const int data)
{
	Node* node = DeleteNode(root, data);
	FixDeleteRBTree(root, node);
}


Node* MinValueNode(Node*& node)
{
	Node* pointer = node;

	while(pointer->Left != nullptr)
	{
		pointer = pointer->Left;
	}

	return pointer;
}


Node* Find(Node* node, const int data)
{
	if (node == nullptr)
	{
		throw std::exception("Does not exist\n");
	}

	if (node->Data == data)
	{
		return node;
	}

	if (node->Data > data)
	{
		return Find(node->Left, data);
	}

	return Find(node->Right, data);
}


void FreeTree(Node* node)
{
	if (node == nullptr)
	{
		return;
	}

	FreeTree(node->Left);
	FreeTree(node->Right);
	delete node;
}
