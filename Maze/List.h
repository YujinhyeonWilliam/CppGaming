#pragma once
#include <iostream>
using namespace std;

template<typename T>
class Node
{
public:
	Node(int data) : data(data), prev(nullptr), next(nullptr) {}
public:
	T data;
	Node<T>* prev;
	Node<T>* next;
};

template<typename T>
class List
{
public:

	List()
	{
		_head = new Node<T>(0);
		_tail = new Node<T>(0);
		_head->next = _tail;
		_tail->prev = _head;
	}

	~List()
	{
		Node<T>* node = _head;
		while (node != nullptr)
		{
			Node<T>* deleteNode = node;
			node = node->next;
			delete deleteNode;
		}
	}

	Node<T>* AddAtHead(int data)
	{
		Node<T>* node = new Node<T>(data);
		Node<T>* nextNode = _head->next;

		node->next = nextNode;
		nextNode->prev = node;
		_head->next = node;
		node->prev = _head;

		return node;
	}

	Node<T>* AddAtTail(int data)
	{
		Node<T>* node = new Node<T>(data);
		Node<T>* prevNode = _tail->prev;

		node->prev = prevNode;
		prevNode->next = node;
		_tail->prev = node;
		node->next = _tail;

		return node;
	}

	void Print()
	{
		Node<T>* node = _head->next;
		while (node != _tail)
		{
			cout << node->data << " ";
			node = node->next;
		}
		cout << endl;
	}

	Node<T>* GetNode(int index)
	{
		Node<T>* node = _head->next;

		if (node == _tail)
			return nullptr;

		for (int i = 0; i < index; i++)
		{
			if (node == _tail->prev)
			{
				if (i == index - 1)
					break;
				else
					return nullptr;
			}

			node = node->next;
		}
		return node;
	}

	void Insert(Node<T>* posNode, int data)
	{
		Node<T>* node = new Node<T>(data);
		Node<T>* prevNode = posNode->prev;
		
		prevNode->next = node;
		node->prev = prevNode;
		node->next = posNode;
		posNode->prev = node;
	}

	/// <summary>
	/// Return Next Node
	/// </summary>
	/// <param name="node">: Target to delete</param>
	/// <returns></returns>
	Node<T>* Remove(Node<T>* node)
	{
		Node<T>* prevNode = node->prev;
		Node<T>* nextNode = node->next;
		prevNode->next = nextNode;
		nextNode->prev = prevNode;

		delete node;
		return nextNode;
	}

private:
	Node<T>* _head = nullptr;
	Node<T>* _tail = nullptr;
	
};

