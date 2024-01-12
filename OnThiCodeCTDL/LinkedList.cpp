#include "LinkedList.h"
#include "BaiTapChuong3.h"
#include <iostream>

template<typename T>
LinkedList<T>::LinkedList()
{
    _pHead = NULL;
    _pTail = NULL;
    _iSize = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	
}

template <typename T>
Node<T>* LinkedList<T>::getNodeAt(unsigned int index)
{
    if (index > getSize() - 1 || index < 0)
    {
        return NULL;
    }
    Node<T>* pWalker = _pHead;
    unsigned int i = 0;
    while (pWalker->_pNext != NULL && i != index)
    {
        pWalker = pWalker->_pNext;
        ++i;
    }
    return pWalker;
}

template <typename T>
void LinkedList<T>::display()
{
    Node<T>* pWalker = _pHead;
    while (pWalker != NULL)
    {
        pWalker->display(); std::cout << " ";
        pWalker = pWalker->_pNext;
    }   
}

template <typename T>
void LinkedList<T>::addHead(T data)
{
    Node<T>* pAdd = new typename Node<T>::Node(data);
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
    Node<T>* pAdd = new typename Node<T>::Node(data);
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
        Node<T>* pAdd = new typename Node<T>::Node(data);
        pAdd->_pNext = pWalker->_pNext;
        pWalker->_pNext = pAdd;
        if (pAdd->_pNext == NULL)
        {
            _pTail = pAdd;
        }
        _iSize++;
    }
}


template <typename T>
Node<T>* LinkedList<T>::search(T data)
{
    Node<T>* pWalker = _pHead;
    while (pWalker != NULL && pWalker->_data != data) // ở đây phải duyệt pWalker != NULL vì nếu duyệt pWalker._pNext != NULL, thì nó sẽ đứng ở phần tử cuối mà không biết phần tử cuối có phải là phần tử cần tìm hay không
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
    while (pWalker->_pNext != node && pWalker != NULL)
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
        _pTail = NULL;
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
void LinkedList<T>::removeAtNode(Node<T>* node)
{
    if (_pHead == NULL)
    {
        return;
    }
    removeAfter(searchPre(node));
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

template <typename T>
void LinkedList<T>::selectionSort()
{
    Node<T>* pMin;
    Node<T>* p;
    Node<T>* q;
    for (p = _pHead; p->_pNext != NULL; p = p->_pNext)
    {
        pMin = p;
        for (q = p->_pNext; q->_pNext != NULL; q = q->_pNext)
        {
            if (q->_data < pMin->_data)
            {
                pMin = q;
            }
        }
        if (pMin != p)
        {
            std::swap(pMin->_data,  p->_data);
        }   
    }
}

template <typename T>
bool LinkedList<T>::isContain(T data)
{
    for (Node<T>* pWalker = _pHead; pWalker != NULL; pWalker = pWalker->_pNext)
    {
        if (pWalker->_data == data)
        {
            return true;
        }
    }
    return false;
}

template <typename T>
int LinkedList<T>::getSize()
{
    return _iSize;
}

template <typename T>
void LinkedList<T>::clear()
{
	while (_pHead != NULL)
	{
        removeHead();
	}
}

template <typename T>
Node<T>* LinkedList<T>::getHead()
{
    return _pHead;
}

template <typename T>
Node<T>* LinkedList<T>::getTail()
{
    return _pTail;
}

template <typename T>
void LinkedList<T>::swapNodeData(Node<T>* node1, Node<T>* node2)
{
    T tmp = node1->_data;
    node1->setData(node2->_data);
    node2->setData(tmp);
}

template <typename T>
void LinkedList<T>::swapNodeData_index(unsigned int index1, unsigned int index2)
{
    Node<T>* node1 = getNodeAt(index1);
    Node<T>* node2 = getNodeAt(index2);
    T tmp = node1->_data;
    node1->setData(node2->_data);
    node2->setData(tmp);
}

template <typename T>
void LinkedList<T>::interchangeSort_doichotructiep(char option)
{
    Node<T>* p;
    Node<T>* q;
    if (option == '<')
    {
        for (p = _pHead; p->_pNext != NULL; p = p->get_pNext())
        {
            for (q = p->get_pNext(); q != NULL; q = q->get_pNext())
            {
                if (q->getData() < p->getData())
                {
                    T data = p->getData();
                    p->setData(q->getData());
                    q->setData(data);
                }
                
            }
        }
    }
    else
    {
        for (p = _pHead; p->_pNext != NULL; p = p->get_pNext())
        {
            for (q = p->get_pNext(); q != NULL; q = q->get_pNext())
            {
                if (q->getData() > p->getData())
                {
                    T data = p->getData();
                    p->setData(q->getData());
                    q->setData(data);
                }
                
            }
        }
    }
}

template <typename T>
void LinkedList<T>::selectionSort_sapxepchon(char option)
{
    Node<T>* p;
    Node<T>* q;
    if (option == '<')
    {
        for (p = _pHead; p->_pNext != NULL; p = p->_pNext)
        {
            Node<T>* tmp = p;
            for (q = p->_pNext; q != NULL; q = q->_pNext)
            {
                if (q->_data < tmp->_data)
                {
                    tmp = q;
                }
            }
            if (tmp != p)
            {
                Node<T>* tmp1 = p;
                p->setData(tmp->_data);
                tmp->_data = tmp1->_data;
            }
        }
    }
    else
    {
        for (p = _pHead; p->_pNext != NULL; p = p->_pNext)
        {
            Node<T>* tmp = p;
            for (q = p->_pNext; q != NULL; q = q->_pNext)
            {
                if (q->_data > tmp->_data)
                {
                    tmp = q;
                }
            }
            if (tmp != p)
            {
                Node<T>* tmp1 = p;
                p->_data = tmp->_data;
                tmp->_data = tmp1->_data;
            }
        }
    }
}

template <typename T>
void LinkedList<T>::insertionSort_sapxepchen(char option)
{
    Node<T>* p;
    Node<T>* q;
    if (option == '<')
    {
        for (p = _pHead->_pNext; p->_pNext != NULL; p = p->_pNext)
        {
            T data = p->_data;
            for (q = p; q != _pHead && q->_data > data; q = searchPre(q))
            {
                q->_data = searchPre(q)->_data;
            }
            q->_data = data;
        }
    }
    else
    {
        for (p = _pHead->_pNext; p->_pNext != NULL; p = p->_pNext)
        {
            T data = p->_data;
            for (q = p; q != _pHead && q->_data < data; q = searchPre(q))
            {
                q->_data = searchPre(q)->_data;
            }
            q->_data = data;
        }
    }
}

template <typename T>
void LinkedList<T>::bubbleSort_sapxepnoibot(char option)
{
    Node<T>* p;
    Node<T>* q;
    if (option == '<')
    {
        for (p = _pHead; p->_pNext != NULL; p = p->_pNext)
        {
            for (q = _pTail; q != p->_pNext; q = searchPre(q))
            {
                Node<T>* tmp = searchPre(q);
                if (q->_data < tmp->_data)
                {
                    Node<T>* tmp1 = q;
                    q->_data = tmp->_data;
                    tmp->_data = tmp1->_data;
                }
            }
        }
    }
    else
    {
        for (p = _pHead; p->_pNext != NULL; p = p->_pNext)
        {
            for (q = _pTail; q != p->_pNext; q = searchPre(q))
            {
                Node<T>* tmp = searchPre(q);
                if (q->_data > tmp->_data)
                {
                    Node<T>* tmp1 = q;
                    q->_data = tmp->_data;
                    tmp->_data = tmp1->_data;
                }
            }
        }
    }
}

template <typename T>
void LinkedList<T>::shift_maxheap(long int left, long int right)
{
    T x;
    long int curr, joint;
    curr = left; joint = 2*curr+1;
    x = getNodeAt(curr)->_data;
    while (joint <= right)
    {
        if (joint < right)
        {
            if (getNodeAt(joint)->_data < getNodeAt(joint + 1)->_data)
            {
                joint = joint + 1;
            }
        }
        if (getNodeAt(joint)->_data < x)
        {
            break;
        }
        getNodeAt(curr)->setData(getNodeAt(joint)->_data);
        curr = joint;
        joint = 2*curr+1;
    }
    getNodeAt(curr)->setData(x);
}

template <typename T>
void LinkedList<T>::shift_minheap(long int left, long int right)
{
    T x;
    long int curr, joint;
    curr = left; joint = 2*curr+1;
    x = getNodeAt(curr)->_data;
    while (joint <= right)
    {
        if (getNodeAt(joint)->_data < getNodeAt(joint + 1)->_data)
        {
            joint = joint + 1;
        }
        if (getNodeAt(joint)->_data > x)
        {
            break;
        }
        getNodeAt(curr)->setData(getNodeAt(joint)->_data);
        curr = joint;
        joint = 2*curr+1;
    }
    getNodeAt(curr)->setData(x);
}

template <typename T>
void LinkedList<T>::createMaxHeap()
{
    long int left; // lấy tầng gần cuối
    for (left = (_iSize - 1)/2; left >= 0; left--)
    {
        shift_maxheap(left, _iSize - 1);
    }
}

template <typename T>
void LinkedList<T>::createMinHeap()
{
    long int left;
    for (left = (_iSize-1)/2; left >= 0; left--)
    {
        shift_minheap(left, _iSize - 1);
    }
}

template <typename T>
void LinkedList<T>::heapSort_sapxepvundong(char option)
{
    if (option == '<')
    {
        createMaxHeap();
        long int right = _iSize - 1;
        while (right > 0)
        {
            swapNodeData_index(0, right);
            right--;
            shift_maxheap(0, right);
        }
        
    }
    else
    {
        createMinHeap();
        long int right = _iSize - 1;
        while (right > 0)
        {
            swapNodeData_index(0, right);
            right--;
            shift_minheap(0, right);
        }
    }
}

template <typename T>
void LinkedList<T>::heapify_maxheap_28tech(long int index, long int N)
{
    long int largest = index;
    long int left = index*2 + 1;
    long int right = index * 2 + 2;
    if (left < N && getNodeAt(left)->_data > getNodeAt(largest)->_data)
    {
        largest = left;
    }
    if (right < N && getNodeAt(right)->_data > getNodeAt(largest)->_data )
    {
        largest = right;
    }
    if (largest != index)
    {
        swapNodeData_index(index, largest);
        heapify_minheap_28tech(largest, N);
    }
}

template <typename T>
void LinkedList<T>::heapify_minheap_28tech(long int index, long int N)
{
    long int smallest = index;
    long int left = index*2 + 1;
    long int right = index * 2 + 2;
    if (left < N && getNodeAt(left)->_data < getNodeAt(smallest)->_data)
    {
        smallest = left;
    }
    if (right < N && getNodeAt(right)->_data < getNodeAt(smallest)->_data )
    {
        smallest = right;
    }
    if (smallest != index)
    {
        swapNodeData_index(index, smallest);
        heapify_minheap_28tech(smallest, N);
    }
}

template <typename T>
void LinkedList<T>::createMaxHeap_28tech()
{
    for (long int i = _iSize/ 2 -1; i >= 0; i--)
    {
        heapify_maxheap_28tech(i, _iSize);
    }
}

template <typename T>
void LinkedList<T>::createMinHeap_28tech()
{
    for (long int i = _iSize/ 2 -1; i >= 0; i--)
    {
        heapify_minheap_28tech(i, _iSize);
    }
}

template <typename T>
void LinkedList<T>::heapSort_28tech(char option)
{
    if (option == '<')
    {
        for (long int i = _iSize - 1; i > 0; i--)
        {
            swapNodeData_index(0, i);
            heapify_maxheap_28tech(0, i);
        }
        
    }
    
}

template class LinkedList<int>;
template class LinkedList<double>;
template class LinkedList<std::string>;
template class LinkedList<long>;
template class LinkedList<bool>;
template class LinkedList<SinhVien_Bai5>;