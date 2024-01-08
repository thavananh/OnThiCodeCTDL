#pragma once
#include "Node.h"

template <typename T>
class LinkedList
{
	Node<T>* _pHead;
	Node<T>* _pTail;
	int _iSize = 0;
public:
	LinkedList();
	~LinkedList();

	void addHead(T data);
	void addTail(T data);
	void addAfter(Node<T>* node, T data);
	Node<T>* search(T data);
	Node<T>* searchPre(Node<T>* node);
	void removeHead();
	void removeTail();
	void removeAfter(Node<T>* node);
	void remove(T data);

	void selectionSort();
	int getSize();
	void display();
	void clear();
};


