#include "LinkedList.h"

LinkedList<bool>snt;

void sangsnt()
{
    for (size_t i = 0; i < 10000001; i++)
    {
        snt.addTail(true);
    }
    snt.getNodeAt(0)->setData(false);
    snt.getNodeAt(1)->setData(false);
    for (size_t i = 2; i < snt.getSize(); i++)
    {
        for (size_t j = i*i; j < snt.getSize(); j++)
        {
            snt.getNodeAt(j)->setData(false);
        }
    }
}

template <typename T>
void Bai1_a(LinkedList<T>& linked_list)
{
    std::cout << "Nhap so luong phan tu: "; int n; std::cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        T a; std::cin >> a;
        linked_list.addTail(a);
    }
}

template <typename T>
void Bai1_b(LinkedList<T> linked_list)
{
    linked_list.display();
}

template <typename T>
void Bai2_b(LinkedList<T> linked_list)
{
    
}