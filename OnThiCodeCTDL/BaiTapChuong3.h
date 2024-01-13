#pragma once
#include "LinkedList.h"
#include <cmath>
#include <string>
#include <iostream>
//#include "Node.h"

using namespace std;

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

template <typename T>
void Bai2_a()
{
	LinkedList<T> l1;
    LinkedList<T> l2;
    LinkedList<T> l3;
    std::cout << "Nhap so phan tu cho l1: "; int n1; std::cin >> n1;
    std::cout << "Nhap so phan tu cho l2: "; int n2; std::cin >> n2;
    for (size_t i = 0; i < n1; i++)
    {
        T a; std::cin >> a;
        l1.addTail(a);
    }
    for (size_t i = 0; i < n2; i++)
    {
        T a; std::cin >> a;
        l2.addTail(a);
    }
    for (Node<T>* p = l1.getHead(); p != NULL; p = p->get_pNext())
    {
        l3.addTail(p->getData());
    }
    for (Node<T>* p = l2.getHead(); p != NULL; p = p->get_pNext())
    {
        l3.addTail(p->getData());
    }
    l3.display();
}

template <typename T>
void Bai2_b()
{
    LinkedList<T> l1;
    LinkedList<T> l2;
    LinkedList<T> l3;
    std::cout << "Nhap so phan tu cho l1: "; int n1; std::cin >> n1;
    std::cout << "Nhap so phan tu cho l2: "; int n2; std::cin >> n2;
    for (size_t i = 0; i < n1; i++)
    {
        T a; std::cin >> a;
        l1.addTail(a);
    }
    for (size_t i = 0; i < n2; i++)
    {
        T a; std::cin >> a;
        l2.addTail(a);
    }
    for (Node<T>* p = l1.getHead(); p != NULL; p = p->get_pNext())
    {
        if (!l2.isContain(p->getData()))
        {
            l3.addTail(p->getData());   
        }
    }
    l3.display();
}

template <typename T>
void Bai2_c()
{
    LinkedList<T> l1;
    LinkedList<T> l2;
    LinkedList<T> l3;
    std::cout << "Nhap so phan tu cho l1: "; int n1; std::cin >> n1;
    for (size_t i = 0; i < n1; i++)
    {
        T a; std::cin >> a;
        l1.addTail(a);
    }
    std::cout << "Nhap so phan tu cho l2: "; int n2; std::cin >> n2;
    for (size_t i = 0; i < n2; i++)
    {
        T a; std::cin >> a;
        l2.addTail(a);
    }
    for (Node<T>* pWalker = l1.getHead(); pWalker != NULL; pWalker = pWalker->get_pNext())
    {
        if (l2.isContain(pWalker->getData()))
        {
            l3.addTail(pWalker->getData());
        }   
    }
    l3.display();
}

template <typename T>
void Bai2_d()
{
    LinkedList<T> l1;
    LinkedList<T> l2;
    LinkedList<T> l3;
    std::cout << "Nhap so phan tu cho l1: "; int n1; std::cin >> n1;
    for (size_t i = 0; i < n1; i++)
    {
        T a; std::cin >> a;
        l1.addTail(a);
        l3.addTail(a);
    }
    std::cout << "Nhap so phan tu cho l2: "; int n2; std::cin >> n2;
    for (size_t i = 0; i < n2; i++)
    {
        T a; std::cin >> a;
        l2.addTail(a);
    }
    for (Node<T>* p = l1.getHead(); p != NULL; p = p->get_pNext())
    {
        if (!l3.isContain(p->getData()))
        {
            l3.addTail(p->getData());   
        }
    }
    for (Node<T>* p = l2.getHead(); p != NULL; p = p->get_pNext())
    {
        if (!l3.isContain(p->getData()))
        {
            l3.addTail(p->getData());   
        }
    }
    l3.display();
}

template <typename T>
void Bai2_e()
{
    LinkedList<T> l1;
    LinkedList<T> l2;
    LinkedList<T> l3;
    std::cout << "Nhap so phan tu cho l1: "; int n1; std::cin >> n1;
    for (size_t i = 0; i < n1; i++)
    {
        T a; std::cin >> a;
        l1.addTail(a);
    }
    std::cout << "Nhap so phan tu cho l2: "; int n2; std::cin >> n2;
    for (size_t i = 0; i < n2; i++)
    {
        T a; std::cin >> a;
        l2.addTail(a);
    }
    Node<T>* p = l1.getHead();
    Node<T>* q = l2.getHead();
    while (p != NULL && q != NULL)
    {
        l3.addTail(p->getData() + q->getData());
        p = p->get_pNext();
        q = q->get_pNext();
    }
    while (q != NULL)
    {
        l3.addTail(q->getData());
        q = q->get_pNext();
        
    }
    while (p != NULL)
    {
        l3.addTail(p->getData());
        p = p->get_pNext();
    }
    l3.display();
    
}

template <typename T>
void Bai2_f()
{
    LinkedList<T> l1;
    LinkedList<T> l2;
    std::cout << "Nhap so phan tu cho l1: "; int n1; std::cin >> n1;
    for (size_t i = 0; i < n1; i++)
    {
        T a; std::cin >> a;
        l1.addTail(a);
    }
    std::cout << "Nhap so phan tu cho l2: "; int n2; std::cin >> n2;
    for (size_t i = 0; i < n2; i++)
    {
        T a; std::cin >> a;
        l2.addTail(a);
    }
    Node<T>* p = l1.getHead();
    Node<T>* q = l2.getHead();
    while (p != NULL && q != NULL)
    {
        if (l1.isContain(q->getData()) || l2.isContain(p->getData()))
        {
            std::cout << "Co trung lap";
            return;
        }
        p = p->get_pNext();
        q = q->get_pNext();
    }
    while (q != NULL)
    {
        if (l1.isContain(q->getData()))
        {
            std::cout << "Co trung lap";
            return;
        }
        q = q->get_pNext();
        
    }
    while (p != NULL)
    {
        if (l2.isContain(p->getData()))
        {
            std::cout << "Co trung lap";
            return;
        }
        p = p->get_pNext();
    }
    std::cout << "Khong tim thay trung lap";
}

template <typename T>
void Bai2_g()
{
    LinkedList<T> l1;
    LinkedList<T> l2;
    std::cout << "Nhap so phan tu cho l1: "; int n1; std::cin >> n1;
    for (size_t i = 0; i < n1; i++)
    {
        T a; std::cin >> a;
        l1.addTail(a);
    }
    std::cout << "Nhap so phan tu cho l2: "; int n2; std::cin >> n2;
    for (size_t i = 0; i < n2; i++)
    {
        T a; std::cin >> a;
        l2.addTail(a);
    }
    T sum = 0;
    for (Node<T>* p = l2.getHead(); p != NULL; p = p->get_pNext())
    {
        sum += p->getData();
    }
    for (Node<T>* p = l1.getHead(); p != NULL; p = p->get_pNext())
    {
        if (p->getData() > sum)
        {
            l1.removeAtNode(p);
            std::cout << "Da xoa phan tu thoa dieu kien" << '\n';
            break;
        }
    }
    l1.display();   
}

template <typename T>
void Bai2_h()
{
    LinkedList<T> l1;
    LinkedList<T> l2;
    std::cout << "Nhap so phan tu cho l1: "; int n1; std::cin >> n1;
    for (size_t i = 0; i < n1; i++)
    {
        T a; std::cin >> a;
        l1.addTail(a);
    }
    std::cout << "Nhap so phan tu cho l2: "; int n2; std::cin >> n2;
    for (size_t i = 0; i < n2; i++)
    {
        T a; std::cin >> a;
        l2.addTail(a);
    }
    T max = l2.getHead()->getData();
    for (Node<T>* p = l2.getHead()->get_pNext(); p != NULL; p = p->get_pNext())
    {
        if (p->getData() > max)
        {
            max = p->getData();
        }
    }
    for (Node<T>* p = l1.getHead(); p != NULL;)
    {
        if (p->getData() == max)
        {
            Node<T>* tmp = p;
            p = p->get_pNext();
            if (tmp == l1.getHead())
            {
                l1.removeHead();
            }
            else
            { 
                l1.removeAtNode(tmp);
            }
            std::cout << "Da xoa phan tu thoa dieu kien" << '\n';
            continue;
        }
        p = p->get_pNext();
    }
}

template <typename T>
void Bai3()
{
    LinkedList<T> l1;
    LinkedList<T> l2;
    std::cout << "Nhap so phan tu cho l1: "; int n1; std::cin >> n1;
    for (size_t i = 0; i < n1; i++)
    {
        T a; std::cin >> a;
        l1.addTail(a);
    }
    std::cout << "Nhap so phan tu cho l2: "; int n2; std::cin >> n2;
    for (size_t i = 0; i < n2; i++)
    {
        T a; std::cin >> a;
        l2.addTail(a);
    }
    LinkedList<T> l3;
    LinkedList<T> tmp;
    bool timthaychua = false;
    for (Node<T>* p = l1.getHead(); p != NULL; p = p->get_pNext())
    {
        Node<T>* pWalker = p;
        for (Node<T>* q = l2.getHead(); q != NULL; q = q->get_pNext())
        {
            if (pWalker == NULL)
            {
                break;
            }
            if (pWalker->getData() == q->getData())
            {
                tmp.addTail(q->getData());
                pWalker = pWalker->get_pNext();
            }
            else
            {
                pWalker = p;
                if (tmp.getSize() > l3.getSize())
                {
                    l3.clear();
                    for (Node<T>* k = tmp.getHead(); k != NULL; k = k->get_pNext())
                    {
                        l3.addTail(k->getData());
                    }
                    timthaychua = true;
                    break;
                }
                tmp.clear();
            }
        }
        if (timthaychua)
        {
	        break;
        }
    }
    l3.display();
}

template <typename T>
void Bai4_a()
{
    LinkedList<T> l1;
    LinkedList<T> l2;
    LinkedList<T> l3;
    std::cout << "Nhap so phan tu cho l1: "; int n1; std::cin >> n1;
    for (size_t i = 0; i < n1; i++)
    {
        T a; std::cin >> a;
        l1.addTail(a);
    }
    std::cout << "Nhap so phan tu cho l2: "; int n2; std::cin >> n2;
    for (size_t i = 0; i < n2; i++)
    {
        T a; std::cin >> a;
        l2.addTail(a);
    }
    for (Node<T>* p = l1.getHead(); p != NULL; p = p->get_pNext())
    {
        if (!l2.isContain(p->getData()))
        {
            l3.addTail(p->getData());
        }
    }
    l3.heapSort_sapxepvundong();
    l3.display();
}

template <typename T>
void Bai4_b()
{
    LinkedList<T> l1;
    LinkedList<T> l2;
    LinkedList<T> l3;
    std::cout << "Nhap so phan tu cho l1: "; int n1; std::cin >> n1;
    for (size_t i = 0; i < n1; i++)
    {
        T a; std::cin >> a;
        l1.addTail(a);
    }
    std::cout << "Nhap so phan tu cho l2: "; int n2; std::cin >> n2;
    for (size_t i = 0; i < n2; i++)
    {
        T a; std::cin >> a;
        l2.addTail(a);
    }
    Node<T>* p;
    Node<T>* q;
    for (p = l1.getHead(); p != NULL; p = p->get_pNext())
    {
        if (l2.isContain(p->getData()))
        {
            l3.addTail(p->getData());
        }
    }
    l3.heapSort_sapxepvundong();
    l3.display();
}

template <typename T>
void Bai4_c()
{
    LinkedList<T> l1;
    LinkedList<T> l2;
    LinkedList<T> l3;
    std::cout << "Nhap so phan tu cho l1: "; int n1; std::cin >> n1;
    for (size_t i = 0; i < n1; i++)
    {
        T a; std::cin >> a;
        l1.addTail(a);
    }
    std::cout << "Nhap so phan tu cho l2: "; int n2; std::cin >> n2;
    for (size_t i = 0; i < n2; i++)
    {
        T a; std::cin >> a;
        l2.addTail(a);
    }
    Node<T>* p;
    Node<T>* q;
    for (p = l1.getHead(); p != NULL; p = p->get_pNext())
    {
        if (!l3.isContain(p->getData()))
        {
            l3.addTail(p->getData());
        }
    }
    for (q = l2.getHead(); q != NULL; q = q->get_pNext())
    {
        if (!l3.isContain(q->getData()))
        {
            l3.addTail(q->getData());
        }   
    }
    l3.heapSort_sapxepvundong();
    l3.display();
}

//struct DateTime
//{
//    int _iDay;
//    int _iMonth;
//    int _iYear;
//    
//    DateTime(int day = 1, int month = 1, int year = 1990)
//    {
//        _iDay = day;
//        _iMonth = month;
//        _iYear = year;
//    }
//};
//
//istream& operator >> (istream& is, DateTime& dt)
//{
//    is >> dt._iDay >> dt._iMonth >> dt._iYear;
//    return is;
//}
//
//ostream& operator << (ostream& os, DateTime dt)
//{
//    os << dt._iDay << "/" << dt._iMonth << "/" << dt._iYear;
//    return os;
//}
//
//
//class SinhVien_Bai5
//{
//    std::string _strMaSinhVien;
//    std::string _strHoTen;
//    std::string _strLop;
//    DateTime _dtNgaySinh;
//    double _dDiemTrungBinh;
//public:
//    SinhVien_Bai5(string strMaSinhVien = "", string strHoTen = "", string strLop = "", DateTime dtNgaySinh = DateTime(), double dDiemTrungBinh = 0.0)
//    {
//        _strMaSinhVien = strMaSinhVien;
//        _strHoTen = strHoTen;
//        _strLop = strLop;
//        _dtNgaySinh = dtNgaySinh;
//        _dDiemTrungBinh = dDiemTrungBinh;
//    }
//    void nhap()
//    {
//        cout << "Nhap msv: "; cin >> _strMaSinhVien;
//        cout << "Nhap ho ten: "; cin >> _strHoTen;
//        cout << "Nhap lop: "; cin >> _strLop;
//        cout << "Nhap ngay sinh: "; cin >> _dtNgaySinh;
//        cout << "Nhap diem trung binh: "; cin >> _dDiemTrungBinh;
//    }
//    void xuat()
//    {
//        cout << "Ma SV: " << _strMaSinhVien << '\n';
//        cout << "Ho Ten: " << _strHoTen << '\n';
//        cout << "Lop: " << _strLop << '\n';
//        cout << "Ngay sinh:" << _dtNgaySinh << '\n';
//        cout << "Diem trung binh: " << _dDiemTrungBinh;
//    }
//    friend ostream& operator << (ostream& os, SinhVien_Bai5 sinhvien)
//    {
//        os << "Ma SV: " << sinhvien._strMaSinhVien << '\n';
//        os << "Ho Ten: " << sinhvien._strHoTen << '\n';
//        os << "Lop: " << sinhvien._strLop << '\n';
//        os << "Ngay sinh:" << sinhvien._dtNgaySinh << '\n';
//        os << "Diem trung binh: " << sinhvien._dDiemTrungBinh;
//        return os;
//    }
//};
//
//class SinhVienList
//{
//    Node<SinhVien_Bai5>* _pHead;
//    Node<SinhVien_Bai5>* _pTail;
//    long _lSize;
//public:
//    void addStudent(const SinhVien_Bai5& data)
//    {
//        Node<SinhVien_Bai5>* pAdd = new typename Node<SinhVien_Bai5>::Node(data);
//        if (_pHead == NULL)
//        {
//            _pHead = pAdd;
//            _pTail = pAdd;
//        }
//        else
//        {
//            _pTail->set_pNext(pAdd);
//            _pTail = pAdd;
//        }
//        _lSize++;
//    }
//    void display()
//    {
//        for (Node<SinhVien_Bai5>* p = _pHead; p != NULL; p=p->get_pNext())
//        {
//            p->getData().xuat();
//        }
//    }
//    void input()
//    {
//        cout << "Nhap so luong sinh vien: "; long int n; cin >> n;
//        for (size_t i = 0; i < n; i++)
//        {
//            SinhVien_Bai5 x;
//            x.nhap();
//            addStudent(x);
//        }
//        
//    }
//};