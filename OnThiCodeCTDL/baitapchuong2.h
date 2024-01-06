#include "ctdl_copy.h"

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