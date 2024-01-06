#include <stdexcept>
#include <random>
#include <iostream>
#include <vector>
#pragma once


template <typename  T>
class DynamicArray
{
private:
	unsigned int _size;
	unsigned int _capacity;
	T* _arr;
public:
	DynamicArray(int capacity = 0) : _size(0), _capacity(capacity)
	{
		if (_capacity < 0)
		{
			throw::std::invalid_argument("Vui long khong nhap so am vao mang");
		}
		else
		{
			_arr = new T[capacity];
		}
	}
	DynamicArray(const DynamicArray& dynamic_array) : _size(dynamic_array._size), _capacity(dynamic_array._capacity)
	{
		if (_capacity < 0)
		{
			throw::std::invalid_argument("Vui long khong nhap so am vao mang");
		}
		_arr = new T[_capacity];
		for (int i = 0; i < _size; i++)
		{
			_arr[i] = dynamic_array._arr[i];
		}
	}
	~DynamicArray()
	{}
	unsigned int Length()
	{
		return _size;
	}
	unsigned int Capacity()
	{
		return _capacity;
	}

	void setSize(unsigned int size)
	{
		_size = size;
	}

	T getVal(unsigned int index)
	{
		return _arr[index];
	}

	void addValue(T val)
	{
		if (_size >= _capacity - 1)
		{
			_capacity *= 2 + 1;
			T* newArr = new T[_capacity];
			for (unsigned int i = 0; i < _size; ++i)
			{
				newArr[i] = _arr[i];
			}
			_arr = new T[_capacity];
			for (unsigned int i = 0; i < _size; ++i)
			{
				_arr[i] = newArr[i];
			}
			_arr[_size] = val;
			delete[] newArr;
			newArr = nullptr;
		}
		else
		{
			_arr[_size] = val;
		}
		_size++;
	}
	void addValueAt(T val, unsigned int index)
	{
		if (index > _size)
		{
			throw::std::out_of_range("Array out of bound");
		}
		else
		{
			_size++;
			if (_size >= _capacity - 1)
			{
				_capacity *= 2 + 1;
				T* newArr = new T[_capacity];
				for (unsigned int i = 0; i < _size; ++i)
				{
					newArr[i] = _arr[i];
				}
				for (unsigned int i = _size; i > index; --i)
				{
					newArr[i] = newArr[i-1]; // dịch mảng về phải
				}
				newArr[index] = val;
				_arr = new T[_capacity];
				for (unsigned int i = 0; i < _size; ++i)
				{
					_arr[i] = newArr[i];
				}
				delete newArr;
				newArr = nullptr;
			}
			else
			{
				for (unsigned int i = _size; i > index; --i)
				{
					_arr[i] = _arr[i - 1]; // dịch mảng về phải
				}
				_arr[index] = val;
			}
		}
	}

	void removeValueAt(T val, unsigned int index)
	{
		if (index > _size)
		{
			throw::std::out_of_range("index muon xoa vuot qua size");
		}
		_arr[_size] = 0;
		_size--;
		for (unsigned int i = index; i < _size; ++i)
		{
			_arr[i] = _arr[i + 1]; // dịch mảng về trái
		}
	}

	void removeAllValue(T val)
	{
		for (int i = _size - 1; i >= 0; --i) // Lặp từ cuối mảng
		{
			if (_arr[i] == val)
			{
				removeValueAt(val, i); // Gọi hàm removeValueAt với chỉ số i
			}
		}
	}

	void clean()
	{
		_capacity = 0;
		_size = 0;
		delete _arr;
		_arr = nullptr;
	}
	void printArr()
	{
		for (unsigned int i = 0; i < _size; ++i)
		{
			std::cout << _arr[i] << " ";
		}
	}

	void swapElement(unsigned int index1, unsigned int index2)
	{
		T tmp = _arr[index1];
		_arr[index1] = _arr[index2];
		_arr[index2] = tmp;
	}

	void modifiedElement(T val, unsigned int index)
	{
		_arr[index] = val;
	}

	void interChangeSort_doichotructiep_tangdan()
	{
		for (unsigned int i = 0; i < _size - 1; ++i)
		{
			for (unsigned int j = i + 1; j < _size; j++)
			{
				if (_arr[j] < _arr[i])
				{
					swapElement(i, j);
				}
			}
		}
	}
	void interchangeSort_doichotructiep_giamdan()
	{
		for (unsigned int i = 0; i < _size - 1; ++i)
		{
			for (unsigned int j = i + 1; j < _size; j++)
			{
				if (_arr[j] > _arr[i])
				{
					swapElement(i, j);
				}
			}
		}
	}
	void selectionSort_sapxepchon_tangdan()
	{
		unsigned int j;
		for (unsigned int i = 0; i < _size - 1; ++i)
		{
			int min = i;
			for (j = i + 1; j < _size; j++)
			{
				if (_arr[j] < _arr[min])
				{
					min = j;
				}
			}
			if (min != i)
			{
				swapElement(min, i);
			}
		}
	}
	void selectionSort_sapxepchon_giamdan()
	{
		unsigned int j;
		for (unsigned int i = 0; i < _size - 1; ++i)
		{
			unsigned int max = i;
			for (j = i + 1; j < _size; j++)
			{
				if (_arr[j] > _arr[max])
				{
					max = j;
				}
			}
			if (max != i)
			{
				swapElement(max, i);
			}
		}
	}
	void sapXepChen_insertionSort_tangdan()
	{
		unsigned int pos, i;
		T x;
		for (unsigned i = 1; i < _size; ++i)
		{
			x = _arr[i];
			for (pos = i; pos > 0 && _arr[pos-1] > x; pos--)
			{
				_arr[pos] = _arr[pos - 1];
			}
			_arr[pos] = x;
		}
	}

	void sapXepChen_insertionSort_giamdan()
	{
		unsigned int pos, i;
		T x;
		for (unsigned i = 1; i < _size; ++i)
		{
			x = _arr[i];
			for (pos = i; pos > 0 && _arr[pos - 1] > x; pos--)
			{
				_arr[pos] = _arr[pos - 1];
			}
			_arr[pos] = x;
		}
	}

	void bubbleSort_sapxepnoibot_tangdan()
	{
		unsigned int i, j;
		for (i = 0; i < _size - 1; ++i)
		{
			for (j = _size - 1; j > i; j--)
			{
				if (_arr[j] < _arr[i])
				{
					swapElement(j, i);
				}
			}
		}
	}

	void bubbleSort_sapxepnoibot_giamdan()
	{
		unsigned int i, j;
		for (i = 0; i < _size - 1; ++i)
		{
			for (j = _size - 1; j > i; j--)
			{
				if (_arr[j] < _arr[i])
				{
					swapElement(j, i);
				}
			}
		}
	}

	void shift_maxheap(int left, int right)
	{
		T x;
		int curr, joint;
		curr = left; joint = 2 * curr + 1;
		x = _arr[curr];
		while (joint <= right)
		{
			if (joint < right)
			{
				if (_arr[joint] < _arr[joint + 1])
				{
					joint = joint + 1;
				}
				
			}
			if (_arr[joint] < x)
			{
				break;
			}
			_arr[curr] = _arr[joint];
			curr = joint;
			joint = 2 * curr + 1;
			
		}
		_arr[curr] = x;
	}

	void shift_minheap(int left, int right)
	{
		T x;
		unsigned int curr, joint;
		curr = left; joint = 2 * curr + 1;
		x = _arr[curr];
		while (joint <= right)
		{
			if (joint < right)
			{
				if (_arr[joint] > _arr[joint + 1])
				{
					joint = joint + 1;
				}

			}
			if (_arr[joint] > x)
			{
				break;
			}
			_arr[curr] = _arr[joint];
			curr = joint;
			joint = 2 * curr + 1;
			
		}
		_arr[curr] = x;
	}

	void createHeap()
	{
		long int left;
		for (left = (_size - 1) / 2; left >= 0; left--)
		{
			shift_maxheap(left, _size - 1);
		}
	}

	void heapsort_sapxepvundong_tangdan()
	{
		unsigned int right;
		createHeap();
		right = _size - 1;
		while (right > 0)
		{
			swapElement(0, right);
			right--;
			shift_maxheap(0, right);
		}
	}

	void heapsort_sapxepvundong_giamdan()
	{
		unsigned int right;
		createHeap();
		right = _size - 1;
		while (right > 0)
		{
			swapElement(0, right);
			right--;
			shift_minheap(0, right);
		}
	}

	void heapify_maxheap_28tech(unsigned int index, unsigned int N)
	{
		unsigned int largest = index;
		unsigned int left = index * 2 + 1;
		unsigned int right = index * 2 + 2;
		if (left < N && _arr[left] > _arr[largest])
		{
			largest = left;
		}
		if (right < N && _arr[right] > _arr[largest])
		{
			largest = right;
		}
		if (largest != index)
		{
			swapElement(index, largest);
			heapify_maxheap_28tech(largest, N);
		}
	}

	void heapify_minheap_28tech(unsigned int index, unsigned int N)
	{
		unsigned int largest = index;
		unsigned int left = index * 2 + 1;
		unsigned int right = index * 2 + 2;
		if (left < N && _arr[left] < _arr[largest])
		{
			largest = left;
		}
		if (right < N && _arr[right] < _arr[largest])
		{
			largest = right;
		}
		if (largest != index)
		{
			swapElement(index, largest);
			heapify_minheap_28tech(largest, N);
		}
	}

	void createmaxheap_28tech()
	{
		for (long i = _size / 2 - 1; i >= 0; --i)
		{
			heapify_maxheap_28tech(i, _size);
		}
	}

	void createminheap_28tech()
	{
		for (long i = _size / 2 - 1; i >= 0; --i)
		{
			heapify_minheap_28tech(i, _size);
		}
	}

	void heapsort_sapxepvundong_tangdan_28tech()
	{
		createmaxheap_28tech();
		for (unsigned int i = _size - 1; i > 0; --i)
		{
			swapElement(0, i);
			heapify_maxheap_28tech(0, i);
		}
	}

	void heapsort_sapxepvundong_giamdan_28tech()
	{
		createminheap_28tech();
		for (unsigned int i = _size - 1; i > 0; --i)
		{
			swapElement(0, i);
			heapify_minheap_28tech(0, i);
		}
	}

	/*void distribute(int &nb, int &nc, int k)
	{
		DynamicArray<T>b(100);
		DynamicArray<T>c(100);
		unsigned int i, pa, pb, pc;
		pa = pb = pc = 0;
		while (pa < _size)
		{
			for (size_t i = 0; (pa < _size) && (i < k); i++, pa++, pb++)
			{
				b[pb] = a[pa];
			}
			for (size_t i = 0; (pa < _size) && (i < k); i++, pa++, pc++)
			{
				c[pc] = a[pa];
			}
		}
		nb = pb; nc = pc;
	}

	void mergeSubarr(int nb, int nc, int &pa, int &pb, int &pc, int k)
	{
		std::vector<int>()
	}*/

	void merge_28tech(int left, int mid, int right)
	{
		DynamicArray<T> tmp1(100), tmp2(100);
		for (unsigned int i = left; i <= mid; ++i)
		{
			tmp1.addValue(_arr[i]);
		}
		for (size_t i = mid + 1; i <= right; i++)
		{
			tmp2.addValue(_arr[i]);
		}
		unsigned int i = 0, j = 0;
		while (i < tmp1.Length() && j < tmp2.Length())
		{
			if (tmp1.getVal(i) <= tmp2.getVal(j)) // phải là dấu bằng, nếu không là dấu bằng sẽ bị mất phần tử
			{
				_arr[left] = tmp1.getVal(i); ++left; ++i;
			}
			else
			{
				_arr[left] = tmp2.getVal(j); ++left; ++j;
			}
		}
		while (i < tmp1.Length())
		{
			_arr[left] = tmp1.getVal(i); ++left; ++i;
		}
		while (j < tmp2.Length())
		{
			_arr[left] = tmp2.getVal(j); ++left; ++j;
		}	
	}

	void mergeSort_28tech(unsigned int left, unsigned int right)
	{
		if (left >= right)
		{
			return;
		}
		int mid = (left + right) / 2;
		mergeSort_28tech(left, mid);
		mergeSort_28tech(mid+1, right);
		merge_28tech(left, mid, right);
	}

	friend DynamicArray<T> merge2daydaduocsapxep(DynamicArray<T> d1, DynamicArray<T>d2);

};

template <typename T1>
DynamicArray<T1> merge2daydaduocsapxep(DynamicArray<T1> d1, DynamicArray<T1>d2)
{
	unsigned int maxlength = d1.Length() + d2.Length();
	unsigned int i = 0, j = 0;
	DynamicArray<T1> rs(maxlength);
	while (i < maxlength || j < maxlength)
	{
		if (i == d1.Length())
		{
			for (size_t k = i; k < d2.Length(); k++)
			{
				T1 x = d2.getVal(k);
				rs.addValue(x);
			}
			break;
		}
		else if (j == d2.Length())
		{
			for (size_t k = j; k < d1.Length(); k++)
			{
				T1 x = d1.getVal(k);
				rs.addValue(x);
			}
			break;
		}


		if (d1.getVal(i) < d2.getVal(j))
		{
			rs.addValue(d1.getVal(i));
			i++;
		}
		else
		{
			rs.addValue(d2.getVal(j));
			j++;
		}

	}
	return rs;
}