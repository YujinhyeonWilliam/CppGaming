#include <iostream>
using namespace std;

class Node
{
public:
	Node(int data) : _data(data) {}

public:
	int _data;
	Node* _prev = nullptr;
	Node* _next = nullptr;
};

int main()
{
	Node* n1 = new Node(1);
	Node* n2 = new Node(2);
	Node* n3 = new Node(3);
	Node* n4 = new Node(4);
	Node* n5 = new Node(5);

	n1->_next = n2;
	n2->_prev = n1;
	n2->_next = n3;
	n3->_prev = n2;
	n3->_next = n4;
	n4->_prev = n3;
	n4->_next = n5;
	n5->_prev = n4;

	Node* head = n1;
	Node* tail = n5;
}