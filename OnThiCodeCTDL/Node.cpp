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

template <typename T>
void Node<T>::setData(T data)
{
    _data = data;
}

template <typename T>
T Node<T>::getData()
{
    return _data;
}

template class Node<int>;
template class Node<double>;
template class Node<std::string>;
template class Node<long>;
template class Node<bool>;