#pragma once
#include "Node.h"

template <typename T>
class Stack_Node
{
    Node<T>* _pTop;
    int _iSize;
public:
    Stack_Node();
    ~Stack_Node();
    
    bool isEmpty();
    void push(T data);
    void pop(); // XOÁ VÀ TRẢ VỀ PHẦN TỬ TRÊN ĐỈNH Stack
    T peek();
    void display();
    void clear();
    int getSize();
};

