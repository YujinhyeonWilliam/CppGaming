#pragma once

struct Node
{
	Node*	parent = nullptr;
	Node*	right = nullptr;
	Node*	left = nullptr;
	int		key = 0;
};

class BinarySearchTree
{
public:
	void	Print() { Print(_root, 10, 0); }
	void	Print(Node* node, int x, int y);
	void	Insert(int key);
	void	Replace(Node* u, Node* v);
	void	Delete(int key);
	void	Delete(Node* node);

	Node*	Search(Node* node, int key);
	Node*	Min(Node* node);
	Node*	Max(Node* node);
	Node*	Next(Node* node);

private:
	Node* _root = nullptr;
};

