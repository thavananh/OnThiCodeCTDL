#pragma once
#include <string>

template <typename T>
class Node_copy_1
{
private:
    T _data;
    Node_copy_1<T>* _pNext;
public:
    Node_copy_1(T data);
    Node_copy_1(const Node_copy_1 &node_copy_1);
    ~Node_copy_1();
    T getNodeData();
    void setNodeData(T data);
    Node_copy_1<T>* get_pNext();
    void setNextNode(Node_copy_1<T>* node);
};

template class Node_copy_1<int>;
template class Node_copy_1<bool>;
template class Node_copy_1<long int>;
template class Node_copy_1<unsigned int>;
template class Node_copy_1<std::string>;
template class Node_copy_1<char>;
