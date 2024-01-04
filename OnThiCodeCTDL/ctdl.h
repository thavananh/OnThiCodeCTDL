#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class DynamicArray
{
private:	
	T* arr;
	unsigned int _iCapacity;
	unsigned int _iSize;
public:
	DynamicArray(int capacity = 0) : _iCapacity(capacity), _iSize(0)
	{
		if (_iCapacity < 0)
		{
			throw invalid_argument("Size cannot be negative");
		}
		arr = new T[_iCapacity];
	}
	DynamicArray(const DynamicArray& dynamic_array) : _iCapacity(dynamic_array._iCapacity), _iSize(dynamic_array._iSize)
	{
		if (_iCapacity < 0)
		{
			throw invalid_argument("Size cannot be negative");
		}
		arr = new T[_iCapacity];
		for (int i = 0; i < _iSize; i++)
		{
			arr[i] = dynamic_array.arr[i];
		}
	}
	~DynamicArray()
	= default;

	unsigned int length() const
	{
		return _iSize;
	}
	unsigned int capacity() const
	{
		return _iCapacity;
	}
	void add_item(T data)
	{
		if (_iSize >= _iCapacity - 1)
		{
			_iCapacity = 1;
		}
		else
		{
			_iCapacity *= 2;
		}
		T* newArr = new T[_iCapacity];
		for (unsigned int i = 0; i < _iSize; i++)
		{
			newArr[i] = arr[i];
		}
		arr = new T[_iCapacity];
		for (unsigned int i = 0; i < _iSize; i++)
		{
			arr[i] = newArr[i];
		}
		arr[_iSize] = data;
		_iSize++;
		delete[] newArr;
		newArr = nullptr;
	}
	T getElement(int index)
	{
		return arr[index];
	}
	unsigned int firstIndexOf(T a)
	{
		for (size_t i = 0; i < _iSize; i++)
		{
			if (arr[i] == a)
			{
				return i;
			}
		}
		return -1;
	}
	unsigned int lastIndexOf(T a)
	{
		for (long i = _iSize - 1; i >= 0; i++)
		{
			if (arr[i] == a)
			{
				return i;
			}
		}
		return -1;
	}

	unsigned int removeAt(long index = -1)
	{
		if (index >= 0)
		{
			_iSize--;
			for (long i = index; i < _iSize - 1; i++)
			{
				arr[i] = arr[i + 1];
			}
		}
	}
	unsigned int removeValue(T val)
	{
		int index = firstIndexOf(val);
		while (index >= 0)
		{
			_iSize--;
			for (long i = index; i < _iSize - 1; i++)
			{
				arr[i] = arr[i + 1];
			}
			index = firstIndexOf(val);
		}
	}
	void swapElement(unsigned int index1, unsigned int index2)
	{
		T tmp = arr[index1];
		arr[index1] = arr[index2];
		arr[index2] = tmp;
	}

	void printArr()
	{
		for (unsigned int i = 0; i < _iSize; ++i)
		{
			cout << arr[i] << " ";
		}
	}

	void modifiedElement(T val, int index)
	{
		arr[index] = val;
	}
};


template <typename T>
long thuatToanTimKiemTuyenTinh(DynamicArray<T> dynamic_array, int key)
{
	for (long i = 0; i < dynamic_array._iSize; i++)
	{
		if (key == dynamic_array.getElement(i))
		{
			return i;
		}
	}
	return -1;
}

template<typename T>
long thuatToanTimKiemNhiPhan_deQuy(DynamicArray<T> dynamic_array, int key, int bottom, int top)
{
	if (bottom < top)
	{
		int mid = (bottom + top) / 2;
		if (dynamic_array.getElement(mid) < key)
		{
			return thuatToanTimKiemNhiPhan_deQuy(dynamic_array, key, mid + 1, top);
		}
		else
		{
			return thuatToanTimKiemNhiPhan_deQuy(dynamic_array, key, bottom, mid - 1);
		}
	}
	else if (bottom > top)
	{
		return -1;
	}
	else
	{
		if (dynamic_array.getElement(bottom))
		{
			return bottom;
		}
		return -1;
	}
}

template <typename T>
long thuatToanTimKiemNhiPhanToiUu_deQuy(DynamicArray<T> dynamic_array, int key, int bottom, int top)
{
	if (bottom <= top)
	{
		int mid = (bottom + top) / 2;
		if (dynamic_array.getElement(mid) == key)
		{
			return mid;
		}
		else if (dynamic_array.getElement(mid) < key)
		{
			return thuatToanTimKiemNhiPhanToiUu_deQuy(dynamic_array, key, mid + 1, top);
		}
		else
		{
			return thuatToanTimKiemNhiPhanToiUu_deQuy(dynamic_array, key, bottom, mid - 1);
		}
	}
	else
	{
		return -1;
	}
}

template<typename T>
long thuatToanTimKiemNhiPhan_KhongDeQuy(DynamicArray<T> dynamic_array, int key)
{
	int bottom = 0, top = dynamic_array.length() - 1;
	while (bottom <= top)
	{
		int mid = (bottom + top) / 2;
		if (dynamic_array.getElement(mid) == key)
		{
			return mid;
		}
		else if (dynamic_array.getElement(mid) < key)
		{
			bottom = mid + 1;
		}
		else
		{
			top = mid - 1;
		}
	}
	return -1;
}

template<typename  T>
void interchangeSort_doichotructiep_tangdan(DynamicArray<T>dynamic_array)
{
	for (int i = 0; i < dynamic_array.length(); ++i)
	{
		for (int j = i + 1; dynamic_array.length(); ++j)
		{
			if (dynamic_array.getElement(i) > dynamic_array.getElement(j))
			{
				dynamic_array.swapElement(i, j);
			}
		}
	}
}

template<typename  T>
void moPhongCachChayInterchangeSort_doichotructiep_tangdan(DynamicArray<T> dynamic_array)
{

	for (unsigned int i = 0; i < dynamic_array.length() - 1; ++i)
	{
		bool isPrint = false;
		cout << "Lan lap " << i << endl;
		for (int j = i + 1; j < dynamic_array.length(); ++j)
		{
			if (dynamic_array.getElement(i) > dynamic_array.getElement(j))
			{
				isPrint = true;
				cout << "i = " << i << ", j = " << j << "   "; dynamic_array.printArr(); cout << '\n';
				dynamic_array.swapElement(i, j);
			}
		}
		if (!isPrint)
		{
			dynamic_array.printArr(); cout << '\n';
		}
	}
}


template<typename  T>
void selectionSort_sapxepchon_tangdan(DynamicArray<T>dynamic_array)
{
	for (unsigned int i = 0; i < dynamic_array.length() - 1; ++i)
	{
		unsigned int min = i;
		for (unsigned int j = i+1; j < dynamic_array.length(); ++j)
		{
			if (dynamic_array.getElement(j) < dynamic_array.getElement(min))
			{
				min = i;
			}
			if (min != i)
			{
				dynamic_array.swapElement(min, j);
			}
		}
	}
}

template <typename T>
void moPhongSelectionSort_sapxepchon_tangdan(DynamicArray<T>dynamic_array)
{
	unsigned int i = 0, j = 0;
	for (i = 0; i < dynamic_array.length() - 1; ++i)
	{
		unsigned int min = i;
		
		bool isPrint = false;
		cout << "lan lap thu " << i << endl;
		for (j = i + 1; j < dynamic_array.length(); ++j)
		{
			if (dynamic_array.getElement(j) < dynamic_array.getElement(min))
			{
				min = j;
			}
			
		}
		if (min != i)
		{
			isPrint = true;
			cout << "i = " << i << ", min = " << min << "   "; dynamic_array.printArr(); cout << '\n';
			dynamic_array.swapElement(i, min);
		}
		if (!isPrint)
		{
			dynamic_array.printArr(); cout << '\n';
		}
	}
}

template <typename T>
void InsertionSort_tangdan(DynamicArray<T>& dynamic_array) // Note the '&' for reference
{
    unsigned int i, pos;
    T x;
    for (i = 1; i < dynamic_array.length(); ++i)
    {
        x = dynamic_array.getElement(i);
        for (pos = i; pos > 0 && dynamic_array.getElement(pos-1) > x; pos--)
        {
            dynamic_array.modifiedElement(dynamic_array.getElement(pos - 1), pos);
        }
        dynamic_array.modifiedElement(x, pos); // Corrected this line
    }
}


template <typename T>
void moPhongInsertionSort_tangdan(DynamicArray<T> dynamic_array)
{
	 int i, pos;
	 int pre_pos;
	T x;
	int lan = 1;
	for (i = 1; i < dynamic_array.length(); ++i)
	{
		x = dynamic_array.getElement(i);
		cout << "Lan lap thu " << lan << endl;
		lan++;
		DynamicArray<T> tmp(dynamic_array);
		for (pos = i; (pos > 0) && (dynamic_array.getElement(pos - 1) > x); pos--)
		{
			dynamic_array.modifiedElement(dynamic_array.getElement(pos - 1), pos);
			
		}
		dynamic_array.modifiedElement(x, pos);
		cout << "i = " << i << ", pos = " << pos - 1 << "   "; tmp.printArr(); cout << '\n';
	}
}

template <typename T>
void bubbleSort_tangdan(DynamicArray<T> dynamic_array)
{
	unsigned int i, j;
	for (i = 0; i < dynamic_array.length(); ++i)
	{
		for (j = dynamic_array.length() - 1; j > i; --j)
		{
			if (dynamic_array.getElement(j) < dynamic_array.getElement(j-1))
			{
				dynamic_array.swapElement(j, j - 1);
			}
		}
	}
}

template <typename T>
void moPhongBubbleSort_tangdan(DynamicArray<T> dynamic_array)
{
	unsigned int i, j;
	for (i = 0; i < dynamic_array.length() - 1; ++i)
	{
		bool isPrint = false;
		cout << "lan lap thu " << i + 1 << endl;
		for (j = dynamic_array.length() - 1; j > i; --j)
		{
			if (dynamic_array.getElement(j) < dynamic_array.getElement(j - 1))
			{
				isPrint = true;
				cout << "i = " << i << ", j = " << j << "   "; dynamic_array.printArr(); cout << '\n';
				dynamic_array.swapElement(j, j - 1);
			}
		}
		if (!isPrint)
		{
			dynamic_array.printArr(); cout << '\n';
		}
	}
}

template <typename T>
void shift_hcmue(T a[], int left, int right)
{
	T x;
	int curr, joint;
	curr = left;
	joint = 2 * curr + 1;
	x = a[curr];
	while (joint <= right)
	{
		for (int i = 0; i <= right; ++i)
		{
			cout << a[i] << " ";
		}
		cout << endl;
		if (joint < right)
		{
			if (a[joint] < a[joint + 1])
			{
				joint = joint + 1;
			}
		}
		if (a[joint] < x)
		{
			break;
		}
		
		
		a[curr] = a[joint];
		curr = joint;
		joint = 2 * curr + 1;
		
	}
	a[curr] = x;
	for (int i = 0; i <= right; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

template <typename T>
void createHeap_hcmue(T a[], int n)
{
	int left;
	for (left = (n-1) / 2; left >= 0; left--) // left = (n-1)/2 để đi từ nút lá trái ở tầng gần cuối
	{
		shift_hcmue(a, left, n - 1);
	}
}

template <typename T>
void heapSort_hcmue(T a[], int n)
{
	int right;
	createHeap_hcmue(a, n);
	right = n - 1;
	while (right > 0)
	{
		swap(a[0], a[right]);
		right--;
		shift_hcmue(a, 0, right);
	}
}