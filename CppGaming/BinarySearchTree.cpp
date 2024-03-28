#include "BinarySearchTree.h"
#include <iostream>
#include <windows.h>
using namespace std;

void SetCursorPosition(int x, int y)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
	::SetConsoleCursorPosition(output, pos);
}

void BinarySearchTree::Print(Node* node, int x, int y)
{
	if (node == nullptr)
		return;

	SetCursorPosition(x, y);
	cout << node->key;
	Print(node->left, x - (5 / (y + 1)), y + 1);
	Print(node->right, x + (5 / (y + 1)), y + 1);

	if(node->left == nullptr && node->right == nullptr)
		SetCursorPosition(0, y + 1);
}

void BinarySearchTree::Insert(int key)
{
	Node* newNode = new Node();
	newNode->key = key;

	if (_root == nullptr)
	{
		_root = newNode;
		return;
	}
	else
	{
		// 추가할 위치 찾기 
		Node* node = _root;
		Node* parent = nullptr;
		bool isLeft = false;

		while (node != nullptr)
		{
			parent = node;
			if (key < node->key)
			{
				node = node->left;
				isLeft = true;
			}
			else
			{
				node = node->right;
				isLeft = false;
			}
			
		}

		newNode->parent = parent;

		if (isLeft)
			parent->left = newNode;
		else
			parent->right = newNode;
	}
	
}

void BinarySearchTree::Replace(Node* u, Node* v)
{
	if (u->parent == nullptr)
		_root = v;
	else if (u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;

	if (v != nullptr)
		v->parent = u->parent;

	//delete u;
}

void BinarySearchTree::Delete(int key)
{
	Node* deleteNode = Search(_root, key);
	Delete(deleteNode);
}

void BinarySearchTree::Delete(Node* node)
{
	if (node == nullptr)
		return;

	if (node->left == nullptr)
	{
		Replace(node, node->right);
		delete node;
	}
	else if (node->right == nullptr)
	{
		Replace(node, node->left);
		delete node;
	}
	else
	{
		// 양쪽 다 자식이 있을 경우
		Node* next = Next(node);
		node->key = next->key;
		Delete(next);
	}
}

Node* BinarySearchTree::Search(Node* node, int key)
{
	if (node == nullptr || key == node->key)
		return node;

	if (key < node->key)
		return Search(node->left, key);
	else
		return Search(node->right, key);
}

Node* BinarySearchTree::Min(Node* node)
{
	if (node == nullptr)
		return nullptr;

	while (node->left)
		node = node->left;

	return node;
}

Node* BinarySearchTree::Max(Node* node)
{
	if (node == nullptr)
		return nullptr;

	while (node->right)
		node = node->right;

	return node;
}

Node* BinarySearchTree::Next(Node* node)
{
	if (node->right)
		return Min(node->right);

	Node* parent = node->parent;

	while (parent && node == parent->right)
	{
		node = parent;
		parent = parent->parent;
	}

	return parent;
}
