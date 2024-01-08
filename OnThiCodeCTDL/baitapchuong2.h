#include "ctdl_copy.h"
#include <string>
#include <sstream>
#include <vector>

template<typename T>
void bai1(DynamicArray<T>&dynamic_array, T val)
{
    for (long int i = dynamic_array.Length() - 1; i >= 0 ;i--)
    {
        if (dynamic_array.getVal(i) == val)
        {
            unsigned int k;
            
            for (k = i; k < dynamic_array.Length() - 1; k++)
            {
                dynamic_array.modifiedElement(dynamic_array.getVal(k + 1), k);
            }
            dynamic_array.modifiedElement(0, dynamic_array.Length());
            dynamic_array.setSize(dynamic_array.Length() - 1);
        }
    }
}

template<typename T>
void bai2(DynamicArray<T>dynamic_array, T val)
{
    for (unsigned int i = 0; i < dynamic_array.Length(); ++i)
    {
	    if (val == dynamic_array.getVal(i))
	    {
            std::cout << i << " ";
	    }
    }
}
template <typename T>
unsigned int bai3(DynamicArray<T>dynamic_array, T val)
{
    unsigned int left = 0;
    unsigned int right = dynamic_array.Length() - 1;
    unsigned int mid;
    unsigned int solanchiadoimang = 0;
    unsigned int left_val[100];
    unsigned int right_val[100];
    unsigned int i = 0, j = 0;
    while (left <= right)
    {
        mid = (left + right) / 2;
	    if (dynamic_array.getVal(mid) == val)
	    {
            std::cout << "so lan chia doi mang la: " << solanchiadoimang << '\n';
            for (unsigned int k = 0; k < i; ++k)
            {
                std::cout << "Lan " << k+1 << " : x = " << val << " nam trong doan " << "[" << left_val[k] << ".." << right_val[k] << "]" << '\n';
            }
            return mid;
	    }
	    else if (val > dynamic_array.getVal(mid))
	    {
            left = mid + 1;
            solanchiadoimang++;
            left_val[i] = left;
            right_val[j] = right;
            i++; j++;
	    }
	    else
	    {
            right = mid - 1;
            solanchiadoimang++;
            left_val[i] = left;
            right_val[j] = right;
            i++; j++;
	    }
    }
    std::cout << "so lan chia doi mang la: " << solanchiadoimang << '\n';
    for (unsigned int k = 0; k < i; ++k)
    {
        std::cout << "Lan " << k << " : x = " << val << " nam trong doan " << "[" << left_val[k] << ".." << right_val[k] << "]" << '\n';
    }
    std::cout << "khong tim thay" << '\n'; 
    return -1;
}

struct Bai4_MonHoc
{
    std::string _maMon, _tenMon;
    int _soTinChi;
    double _diem;
    Bai4_MonHoc(std::string maMon = "", std::string tenMon = "", int soTinChi = 0, double diem = 0.0) : _maMon(maMon), _tenMon(tenMon), _soTinChi(soTinChi), _diem(diem){}
};

std::istream& operator >> (std::istream& is, Bai4_MonHoc& monhoc)
{
    std::cout << "Nhap ma mon: "; std::cin >> monhoc._maMon;
    std::cout << "Nhap ten mon: "; std::cin >> monhoc._tenMon;
    std::cout << "Nhap so tin chi: "; std::cin >> monhoc._soTinChi;
    std::cout << "Nhap diem: "; std::cin >> monhoc._diem;
    return is;
}

std::ostream& operator << (std::ostream& os, Bai4_MonHoc monhoc)
{
	std::cout << "Ma mon: " << monhoc._maMon << '\n';
    std::cout << "Ten mon: " << monhoc._tenMon << '\n';
    std::cout << "So tin chi: " << monhoc._soTinChi << '\n';
    std::cout << "Diem: " << monhoc._diem << '\n';
    return os;
}

class Bai4
{
private:
    std::string _mssv, _hoTen, _ngaySinh;
    int _soMonHoc;
    Bai4_MonHoc _monHoc[100];
public:
    Bai4(std::string mssv = "", std::string hoTen = " ", std::string ngaySinh = "", int soMonHoc = 0, Bai4_MonHoc monHoc[] = {}) : _mssv(mssv), _hoTen(hoTen), _ngaySinh(ngaySinh), _soMonHoc(soMonHoc)  
    {
        for (size_t i = 0; i < _soMonHoc; i++)
        {
            _monHoc[i] = monHoc[i];
        }
    }
    Bai4(const Bai4& bai4): _mssv(bai4._mssv), _hoTen(bai4._hoTen), _ngaySinh(bai4._ngaySinh), _soMonHoc(bai4._soMonHoc)  
    {
        for (size_t i = 0; i < _soMonHoc; i++)
        {
            _monHoc[i] = bai4._monHoc[i];
        }
    }
    ~Bai4()
    {}
    void nhap()
    {
        std::cout << "nhap mssv: ";         std::cin >> _mssv; std::cin.ignore();
        std::cout << "nhap ho ten: ";       std::getline(std::cin, _hoTen);
        std::cout << "nhap ngay sinh: ";    std::cin >> _ngaySinh;
        std::cout << "nhap so mon hoc: ";   std::cin >> _soMonHoc;
        std::cout << "Nhap thong tin mon hoc" << std::endl;
        for (size_t i = 0; i < _soMonHoc; i++)
        {
	        std::cin >> _monHoc[i];
        }
    }
    void xuat()
    {
        std::cout << "MSSV: " << _mssv << '\n';
        std::cout << "Ho Ten: " << _hoTen << '\n';
        std::cout << "Ngay Sinh: " << _ngaySinh << '\n';
        std::cout << "So Mon Hoc: " << _soMonHoc << '\n';
        for (int i = 0; i < _soMonHoc; ++i)
        {
            std::cout << "Mon hoc thu: " << i + 1 << '\n';
            std::cout << _monHoc[i] << std::endl;
        }
    }
    std::string getMSSV()
    {
        return _mssv;
    }
    void setHoTenSinhVien(std::string hoTen)
    {
        _hoTen = hoTen;
    }
    std::string getTen()
    {
        std::stringstream ss(_hoTen);
        std::string tmp;
        std::vector<std::string>processHoTen;
        while (ss >> tmp)
        {
            processHoTen.push_back(tmp);
        }
        if (processHoTen.size() >= 1)
        {
            return processHoTen[processHoTen.size() - 1];
        }
        return "";
    }
};

int searchSinhVien(Bai4 sinhvien[], int n, std::string key)
{
    for (size_t i = 0; i < n; i++)
    {
        if (sinhvien[i].getMSSV() == key)     
        {
            return i;
        }
    }
    return -1;
}

void insertionSort_sinhvien(Bai4 sinhvien[], int n)
{
    int i, j;
	for (i = 1; i < n-1; ++i)
    {
        int val = (int)sinhvien[i].getTen()[0];
        Bai4 sinhvienTmp = sinhvien[i];
        for (j = i; j > 0 && (int)sinhvien[j-1].getTen()[0] > val; j--)
        {
            sinhvien[j] = sinhvien[j-1];
        }
        sinhvien[j] = sinhvienTmp;
    }
}

/*
3
4801104035
Lau Minh Tam
02/03/2004
1
COMP123
XSTK
3
5
4801104053
Nguyen Vo Minh Duy
01/01/2004
1
COMP123
XSTK
3
10
4801104114
Nguyen Anh Hung
11/12/2004
1
COMP123
XSTK
3
8
 */
