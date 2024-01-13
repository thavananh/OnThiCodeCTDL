#pragma once
#include "Node_copy_1.h"
#include <string>

template <typename T>
class LinkedList_copy_1
{
private:
    Node_copy_1<T>* _pHead;
    Node_copy_1<T>* _pTail;
    unsigned int _uiSize;
public:
    LinkedList_copy_1();
    LinkedList_copy_1(const LinkedList_copy_1& linkedlist_copy_1);
    ~LinkedList_copy_1();

    Node_copy_1<T>* getNodeHead();
    void setNodeHead(Node_copy_1<T>* node);
    Node_copy_1<T>* getNodeTail();
    void setNodeTail(Node_copy_1<T>* node);
    unsigned int getSize();

    
};

template class LinkedList_copy_1<int>;
template class LinkedList_copy_1<bool>;
template class LinkedList_copy_1<long int>;
template class LinkedList_copy_1<unsigned int>;
template class LinkedList_copy_1<std::string>;
template class LinkedList_copy_1<char>;
