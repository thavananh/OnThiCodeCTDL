#include "Node.h"
#include <iostream>

template <typename T>
Node<T>::Node(T data)
{
    _data = data;
    _pNext = NULL;
}

template <typename T>
void Node<T>::display()
{
    std::cout << _data;
}
