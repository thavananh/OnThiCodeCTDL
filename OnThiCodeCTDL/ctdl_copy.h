#include <stdexcept>
#include <random>
#include <iostream>

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
			delete newArr;
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
					newArr[i] = newArr[i-1];
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
					_arr[i] = _arr[i - 1];
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
		_size--;
		for (unsigned int i = index; i < _size; ++i)
		{
			_arr[i] = _arr[i + 1];
		}
	}

	void removeAllValue(T val)
	{
		for (unsigned int i = 0; i < _size; ++i)
		{
			if (val == _arr[i])
			{
				removeValueAt(val, i);
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
};
