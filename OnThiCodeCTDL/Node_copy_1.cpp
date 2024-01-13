#include "Node_copy_1.h"

template <typename T>
Node_copy_1<T>::Node_copy_1(T data)
{
    _data = data;
    _pNext = NULL;
}

template <typename T>
Node_copy_1<T>::Node_copy_1(const Node_copy_1 &node_copy_1)
{
    _data = node_copy_1._data;
    _pNext = node_copy_1._pNext;
}

template <typename T>
Node_copy_1<T>::~Node_copy_1()
{}

template <typename T>
T Node_copy_1<T>::getNodeData()
{
    return _data;
}

template <typename T>
void Node_copy_1<T>::setNodeData(T data)
{
    _data = data;
}

template <typename T>
Node_copy_1<T>* Node_copy_1<T>::get_pNext()
{
    return _pNext;
}

template <typename T>
void Node_copy_1<T>::setNextNode(Node_copy_1<T> *node)
{
    _pNext = node;
}