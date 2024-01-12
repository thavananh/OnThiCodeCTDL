#pragma once
#include "Node.h"

template <typename T>
class LinkedList
{
	Node<T>* _pHead;
	Node<T>* _pTail;
	unsigned int _iSize = 0;
public:
	LinkedList();
	~LinkedList();

	void addHead(T data);
	void addTail(T data);
	void addAfter(Node<T>* node, T data);
	Node<T>* search(T data);
	Node<T>* searchPre(Node<T>* node);
	Node<T>* getNodeAt(unsigned int index);
	void removeHead();
	void removeTail();
	void removeAfter(Node<T>* node);
	void remove(T data);	
	void removeAtNode(Node<T>* node);
	void selectionSort();
	int getSize();
	void display();
	void clear();
	Node<T>* getHead();
	Node<T>* getTail();
	bool isContain(T data);
	void interchangeSort_doichotructiep(char option);
	void selectionSort_sapxepchon(char option);
	void insertionSort_sapxepchen(char option);
	void bubbleSort_sapxepnoibot(char option);
	void shift_maxheap(long int left, long int right);
	void shift_minheap(long int left, long int right);
	void createMaxHeap();
	void createMinHeap();
	void heapify_maxheap_28tech(long int index, long int N);
	void heapify_minheap_28tech(long int index, long int N);
	void createMaxHeap_28tech();
	void createMinHeap_28tech();
	void heapSort_28tech(char option);
	void heapSort_sapxepvundong(char option);
	void mergeSort_sapxeptron(char option);
	void quicksort_sapxepnhanh(char option);
	void swapNodeData(Node<T>* node1, Node<T>* node2);
	void swapNodeData_index(unsigned int index1, unsigned int index2);
};


