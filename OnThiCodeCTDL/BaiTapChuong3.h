#include "LinkedList.h"
#include <cmath>

LinkedList<bool>snt;

void sangsnt()
{
    for (size_t i = 0; i < 100; i++)
    {
        snt.addTail(true);
    }
    snt.getNodeAt(0)->setData(false);
    
    snt.getNodeAt(1)->setData(false);
    for (size_t i = 2; i < snt.getSize(); i++)
    {
        for (size_t j = i*i; j < snt.getSize(); j += i)
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
void Bai1_c(LinkedList<T> linked_list)
{
    sangsnt();
    for (size_t i = 0; i < linked_list.getSize(); i++)
    {
        if (snt.getNodeAt(linked_list.getNodeAt(i)->getData())->getData())
        {
            std::cout << linked_list.getNodeAt(i)->getData() << " ";
        }
    }
}

template <typename T>
void Bai1_d(LinkedList<T> ll)
{
    double sum = 0;
    for (size_t i = 0; i < ll.getSize(); i++)
    {
        sum += ll.getNodeAt(i)->getData();
    }
    std::cout << "Trung binh: " << sum / ll.getSize();

}

template <typename T>
void Bai1_e(LinkedList<T> ll)
{
    T a;
    std::cout << "Nhap so: ";
    std::cin >> a;
    unsigned int soLan = 0;
    for (size_t i = 0; i < ll.getSize(); i++)
    {
        if (ll.getNodeAt(i)->getData() == a)
        {
            soLan++;
        }
    }
    std::cout << "So lan xuat hien trong mang la: " << soLan;
}

template <typename T>
void Bai1_f(LinkedList<T> ll)
{
    for (size_t i = ll.getSize() - 1; i >= 0; --i)
    {
        int n = ll.getNodeAt(i)->getData();
        T k = sqrt(n);
        if (k * k == n)
        {
            std::cout << n;
            break;
        }   
    }
}

template <typename T>
void Bai1_g(LinkedList<T> ll)
{
    int k;
    std::cout << "Nhap phan tu thu K: ";
    std::cin >> k;
    std::cout << "Phan tu thu K trong list la: " << ll.getNodeAt(k)->getData();
}

template <typename T>
void Bai1_h(LinkedList<T> ll)
{
    Node<T>* pMin = ll.getHead();
    Node<T>* p;
    for (p = ll.getHead()->get_pNext(); p->get_pNext() != NULL; p = p->get_pNext())
    {
        if (p->getData() < pMin->getData())
        {
            pMin = p;
        }   
    }
    std::cout << "Phan tu nho nhat trong list: " << pMin->getData();
}

template <typename T>
void Bai1_i(LinkedList<T>& ll)
{
    std::cout << "Nhap vi tri phan tu q: ";
    int i; std::cin >> i;
    ll.addAfter(ll.getNodeAt(i), 1000);
    ll.display();
}

template <typename T>
void Bai1_j(LinkedList<T>& ll)
{
    while (true)
    {
        std::cout << "Nhap gia tri phan tu: ";
        T k; std::cin >> k;
        if (ll.search(k) == NULL)
        {
            ll.addTail(k);
            std::cout << "Them phan tu thanh cong" << '\n';
            break;
        }
        std::cout << "Phan tu da co trong list, vui long nhap lai";
    }
    ll.display();
}

template <typename T>
void Bai1_k(LinkedList<T>& ll)
{
    int k;
    while (true)
    {
        std::cout << "Nhap k phan tu de xoa: "; std::cin >> k;
        if (k <= ll.getSize())
        {
            break;
        }
        std::cout << "Ban da nhap qua so luong phan tu trong day" << std::endl;
    }
    for (size_t i = 0; i < k; i++)
    {
        ll.removeHead();
    }
    ll.display();
}

template <typename T>
void Bai1_l(LinkedList<T>& ll)
{
    std::cout << "Nhap phan tu co gia tri x de xoa: "; int x; std::cin >> x;
    ll.remove(x);
    ll.display();
}

template <typename T>
void Bai1_m(LinkedList<T>& ll)
{
    std::cout << "Nhap vi tri phan tu q: "; int k; std::cin >> k;
    ll.removeAfter(ll.getNodeAt(k));
    ll.display();
}

template <typename T>
void Bai1_n(LinkedList<T>& ll)
{
    Node<T>* p;
    Node<T>* q;
    for (q = ll.getHead(); q != NULL; q = q->get_pNext()) // ở đây phải là q != NULL mà không q->getpNext != NULL vì, chúng ta đang xoá phần tử, lỡ phần tử cuối mà bị xoá thì khi ta cập nhật pNext sang phần tử cuối và kiểm tra điều kiện phần tử null sẽ bị lỗi memory access
    {
        for (p = q->get_pNext(); p != NULL; p = p->get_pNext())
        {
            if (q->getData() == p->getData())
            {
                Node<T>* tmp = ll.searchPre(p);
                p = tmp;
                ll.removeAfter(tmp);
                ll.display(); std::cout << '\n';
            }
        }
    }
    ll.display();
}

template <typename T>
void Bai1_o(LinkedList<T>& ll)
{
    Node<T>* p;
    Node<T>* q;
    for (p = ll.getHead(); p->get_pNext() != NULL; p = p->get_pNext())
    {
        for (q = p->get_pNext(); q != NULL; q = q->get_pNext())
        {
            if (q->getData() < p->getData())
            {
                T tmp = p->getData();
                p->setData(q->getData());
                q->setData(tmp);
            }
        }
    }
    ll.display();
}

template <typename T>
void Bai1_p(LinkedList<T>& ll)
{
    Bai1_o(ll); std::cout << std::endl;
    Node<T>* p;
    Node<T>* q;
    T a; std::cout << "Nhap phan tu de them vao: ";
    std::cin >> a;
    for (p = ll.getHead(); p != NULL; p = p->get_pNext())
    {
        if (a < p->getData())
        {
           ll.addAfter(ll.searchPre(p), a);
           break;
        }   
    }
    ll.display();
}

template<typename T>
T pt(T n)
{
    T sum = 0;
    for (size_t i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
        }
    }
    return sum-n;
}

template <typename T>
void Bai1_q(LinkedList<T>& ll)
{
    Node<T>* p;
    for (p = ll.getHead(); p != NULL; p = p->get_pNext())
    {
        if (p->getData() == pt(p->getData()))
        {
            p->setData(0);
        }
    }
    ll.display();
}