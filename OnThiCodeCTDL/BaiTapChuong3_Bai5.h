#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

struct DateTime
{
    int _iDay;
    int _iMonth;
    int _iYear;

    DateTime(int day = 1, int month = 1, int year = 1990)
    {
        _iDay = day;
        _iMonth = month;
        _iYear = year;
    }
};

istream& operator >> (istream& is, DateTime& dt)
{
    is >> dt._iDay >> dt._iMonth >> dt._iYear;
    return is;
}

ostream& operator << (ostream& os, DateTime dt)
{
    os << dt._iDay << "/" << dt._iMonth << "/" << dt._iYear;
    return os;
}

class SinhVien_Bai5
{
    std::string _strMaSinhVien;
    std::string _strHoTen;
    std::string _strLop;
    DateTime _dtNgaySinh;
    double _dDiemTrungBinh;
public:
    SinhVien_Bai5(string strMaSinhVien = "", string strHoTen = "", string strLop = "", DateTime dtNgaySinh = DateTime(), double dDiemTrungBinh = 0.0)
    {
        _strMaSinhVien = strMaSinhVien;
        _strHoTen = strHoTen;
        _strLop = strLop;
        _dtNgaySinh = dtNgaySinh;
        _dDiemTrungBinh = dDiemTrungBinh;
    }
    void nhap()
    {
        cout << "Nhap msv: "; cin >> _strMaSinhVien;
        cin.ignore();
        cout << "Nhap ho ten: "; getline(cin, _strHoTen);
        cout << "Nhap lop: "; cin >> _strLop;
        cout << "Nhap ngay sinh: "; cin >> _dtNgaySinh;
        cout << "Nhap diem trung binh: "; cin >> _dDiemTrungBinh;
    }
    void xuat()
    {
        cout << "Ma SV: " << _strMaSinhVien << '\n';
        cout << "Ho Ten: " << _strHoTen << '\n';
        cout << "Lop: " << _strLop << '\n';
        cout << "Ngay sinh:" << _dtNgaySinh << '\n';
        cout << "Diem trung binh: " << _dDiemTrungBinh;
    }
    // friend ostream& operator << (ostream& os, SinhVien_Bai5 sinhvien)
    // {
    //     os << "Ma SV: " << sinhvien._strMaSinhVien << '\n';
    //     os << "Ho Ten: " << sinhvien._strHoTen << '\n';
    //     os << "Lop: " << sinhvien._strLop << '\n';
    //     os << "Ngay sinh:" << sinhvien._dtNgaySinh << '\n';
    //     os << "Diem trung binh: " << sinhvien._dDiemTrungBinh;
    //     return os;
    // }
    string getMaSinhVien()
    {
        return _strMaSinhVien;
    }
    string getHoTen()
    {
        return _strHoTen;
    }
    string getLop()
    {
        return _strLop;
    }
    DateTime getNgaySinh()
    {
        return _dtNgaySinh;
    }
    double getDiemTrungBinh()
    {
        return _dDiemTrungBinh;
    }
    void setMaSinhVien(string maSinhVien)
    {
        _strMaSinhVien = maSinhVien;
    }
    void setHoTen(string hoTen)
    {
        _strHoTen = hoTen;
    }
    void setLop(string lop)
    {
        _strLop = lop;
    }
    void setNgaySinh(DateTime ngaySinh)
    {
        _dtNgaySinh = ngaySinh;
    }
    void setDiemTrungBinh(double diemTrungBinh)
    {
        _dDiemTrungBinh = diemTrungBinh;
    }
    char getChuCaiDauCuaTen()
    {
        stringstream ss(_strHoTen);
        vector<string>processName;
        string tmp;
        while (ss >> tmp)
        {
            processName.push_back(tmp);
        }
        if (processName.size() > 0)
        {
            return processName[processName.size() - 1][0];
        }
        return 0;
    }
};


class NodeSinhVien
{
    SinhVien_Bai5 _data;
    NodeSinhVien* _pNext;
public:
    NodeSinhVien(SinhVien_Bai5 data)
    {
        _data = data;
        _pNext = NULL;
    }
    SinhVien_Bai5& getData()
    {
        return _data;
    }
    void setData(SinhVien_Bai5 data)
    {
        _data = data;
    }
    NodeSinhVien* get_pNext()
    {
        return _pNext;
    }
    void setNodeSinhVien(NodeSinhVien* node)
    {
        _pNext = node;
    }
};


class SinhVienList
{
    NodeSinhVien* _pHead;
    NodeSinhVien* _pTail;
    long _lSize;
public:
    SinhVienList()
    {
        _pHead = _pTail = NULL;
        _lSize = 0;
    }
    void addStudent(const SinhVien_Bai5& data)
    {
        NodeSinhVien* pAdd = new NodeSinhVien(data);
        if (_pHead == NULL)
        {
            _pHead = pAdd;
            _pTail = pAdd;
        }
        else
        {
            _pTail->setNodeSinhVien(pAdd);
            _pTail = pAdd;
        }
        _lSize++;
    }
    void display()
    {
        for (NodeSinhVien* p = _pHead; p != NULL; p=p->get_pNext())
        {
            p->getData().xuat(); cout << endl;
        }
    }
    void input()
    {
        cout << "Nhap so luong sinh vien: "; long int n; cin >> n;
        for (size_t i = 0; i < n; i++)
        {
            SinhVien_Bai5 x;
            x.nhap();
            addStudent(x);
        }
        
    }
    void Bai1_b(string x, string y)
    {
        for (NodeSinhVien* p = _pHead; p != NULL; p = p->get_pNext())
        {
            if (p->getData().getMaSinhVien() == x)
            {
                p->getData().setHoTen(y);
            }
        }
    }
    void swapTwoNode(NodeSinhVien* node1, NodeSinhVien* node2)
    {
        SinhVien_Bai5 tmp = node1->getData();
        node1->setData(node2->getData());
        node2->setData(tmp);
    }

    NodeSinhVien* searchPre(NodeSinhVien* node)
    {
        if (_pHead == NULL)
        {
            return NULL;
        }
        NodeSinhVien* pWalker = _pHead;
        while (pWalker->get_pNext() != node)
        {
            pWalker = pWalker->get_pNext();
        }
        return pWalker;
    }

    void insertionSort_theoTen()
    {
        NodeSinhVien* q;
        for (NodeSinhVien* p = _pHead->get_pNext(); p != NULL; p = p->get_pNext())
        {
            SinhVien_Bai5 tmp = p->getData();
            for (q = p; q != _pHead && (int)(searchPre(q)->getData().getChuCaiDauCuaTen()) < (int)(tmp.getChuCaiDauCuaTen()); q = searchPre(q))
            {
                q->setData(searchPre(q)->getData());
            }
            q->setData(tmp);
        }
    }
    
    void insertionSort_TheoMSSV()
    {

    }
};