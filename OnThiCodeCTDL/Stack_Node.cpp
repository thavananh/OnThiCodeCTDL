#include "Stack_Node.h"
#include <typeinfo>
#include <stdexcept>
#include <iostream>
using namespace std;

template <typename T>
Stack_Node<T>::Stack_Node()
{
    _pTop = NULL;
    _iSize = 0;
}

template <typename T>
Stack_Node<T>::~Stack_Node()
{
    clear();
}

template <typename T>
bool Stack_Node<T>::isEmpty()
{
    return (_pTop == NULL);
}

template <typename T>
void Stack_Node<T>::push(T data)
{
    Node<T>* pAdd = new typename Node<T>::Node(data);
    pAdd->set_pNext(_pTop);
    _pTop = pAdd;
    _iSize++;
}

template <typename T>
void Stack_Node<T>::pop()
{
    if (isEmpty())
    {
        return;
    }
    Node<T>* pTmp = _pTop;
    _pTop = pTmp->get_pNext();
    delete pTmp;
    _iSize--;
}

template <typename T>
T Stack_Node<T>::peek()
{
    if (isEmpty())
    {
        throw std::runtime_error("Stack is empty");   
    }
    return _pTop->getData();
}

template <typename T>
void Stack_Node<T>::display()
{
    if (isEmpty())
    {
        throw std::runtime_error("Stack is empty");   
    }
    for (Node<T>* pWalker = _pTop; pWalker != NULL; pWalker = pWalker->get_pNext())
    {
        cout << pWalker->getData() << " ";
    }
}

template <typename T>
void Stack_Node<T>::clear()
{
    Node<T>* pTmp;
    while (_pTop != NULL)
    {
        pTmp = _pTop;
        _pTop = _pTop->get_pNext();
        delete pTmp;
    }
    _iSize = 0;
}

template <typename T>
int Stack_Node<T>::getSize()
{
    return _iSize;
}


template class Stack_Node<int>;
template class Stack_Node<double>;
template class Stack_Node<std::string>;
template class Stack_Node<long>;
template class Stack_Node<bool>;
