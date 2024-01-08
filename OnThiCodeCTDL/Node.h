#pragma once
template <typename T>
class LinkedList;

template <typename T>
class Node
{
	friend LinkedList<T>;
private:
    T _data; //dữ liệu của Node
    Node* _pNext; // địa chỉ của Node kế tiếp
public:
    Node(T data); // khởi tạo node mới có dữ liệu là data
    void display();
};


