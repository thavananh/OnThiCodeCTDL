#include "ctdl_copy.h"
#include <string>

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
};

