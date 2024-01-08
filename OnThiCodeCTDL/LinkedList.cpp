#include "LinkedList.h"
#include <iostream>

template<typename T>
LinkedList<T>::LinkedList()
{
    _pHead = NULL;
    _pTail = NULL;
    _iSize = 0;
}

template <typename T>
void LinkedList<T>::display()
{
    Node<T>* pWalker = _pHead;
    while (pWalker != NULL)
    {
        pWalker->display();
        pWalker = pWalker->_pNext;
    }   
}

template <typename T>
void LinkedList<T>::addHead(T data)
{
    Node<T>* pAdd = new Node<T>::Node(data);
    if (_pHead == NULL)
    {
        _pHead = pAdd;
        _pTail = pAdd;
    }
    else
    {
        pAdd->_pNext = _pHead;
        _pHead = pAdd;
    }
    _iSize++;
}

template <typename T>
void LinkedList<T>::addTail(T data)
{
    Node<T>* pAdd = new Node<T>::Node(data);
    if (_pTail == NULL)
    {
        _pHead = pAdd;
        _pTail = pAdd;
    }
    else
    {
        _pTail->_pNext = pAdd;
        _pTail = pAdd;
    }
    _iSize++;
}

template <typename T>
void LinkedList<T>::addAfter(Node<T>* node, T data)
{
    if (_pHead != NULL)
    {
        Node<T>* pWalker = _pHead;
	    while (pWalker != node)
        {
            pWalker = pWalker->_pNext;
        }
        Node<T>* pAdd = new Node<T>::Node(data);
        pAdd->_pNext = pWalker->_pNext;
        pWalker->_pNext = pAdd;
        if (pAdd->_pNext == NULL)
        {
            _pTail = pAdd;
        }
    }
}


template <typename T>
Node<T>* LinkedList<T>::search(T data)
{
    Node<T>* pWalker = _pHead;
    while (pWalker->_data != data && pWalker != NULL) // ở đây phải duyệt pWalker != NULL vì nếu duyệt pWalker._pNext != NULL, thì nó sẽ đứng ở phần tử cuối mà không biết phần tử cuối có phải là phần tử cần tìm hay không
    {
        pWalker = pWalker->_pNext;
    }
    return pWalker;
}

template <typename T>
Node<T>* LinkedList<T>::searchPre(Node<T>* node)
{
    Node<T>* pWalker = _pHead;
    if (node == pWalker)
    {
        return NULL;
    }
    while (pWalker->_pNext != node && pWalker->_pNext != NULL)
    {
        pWalker = pWalker->_pNext;
    }
    return pWalker;
}

template <typename T>
void LinkedList<T>::removeHead()
{
    if (_pHead == NULL)
    {
        return;
    }
    Node<T>* pTmp = _pHead;
    _pHead = _pHead->_pNext;
    if (_pHead == NULL)
    {
        _pTail == NULL;
    }
    delete pTmp;
    _iSize--;
}

template <typename T>
void LinkedList<T>::removeTail()
{
    if (_pHead == NULL)
    {
        return;
    }
    Node<T>* pTmp = _pTail;
    _pTail = searchPre(_pTail);
    delete pTmp;
    if (_pTail == NULL)
    {
        _pHead = NULL;
    }
    else
    {
        _pTail->_pNext = NULL;
    }
}

template <typename T>
void LinkedList<T>::removeAfter(Node<T>* node)
{
    if (_pHead == NULL)
    {
        return;
    }
    if (node->_pNext != NULL)
    {
        Node<T>* pTmp = node->_pNext;
        node->_pNext = pTmp->_pNext;
        delete pTmp;
        if (node->_pNext == NULL)
        {
            _pTail = node;
        }
        --_iSize;
    }
}

template <typename T>
void LinkedList<T>::remove(T data)
{
    Node<T>* tmp = search(data);
    if (tmp != NULL)
    {
        if (tmp == _pHead)
        {
            removeHead();
        }
        else if (tmp == _pTail)
        {
            removeTail();
        }
        else
        {
            Node<T>* tmp1 = searchPre(tmp);
            removeAfter(tmp1);
        }
        _iSize--;
    }
}