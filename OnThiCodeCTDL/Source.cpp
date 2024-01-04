#include  "ctdl_copy.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "Nhap so phan tu: ";
	unsigned int n; cin >> n;
	DynamicArray<long> dynamic_array(n);
	for (unsigned int i = 0; i < n; ++i)
	{
		long val;
		cin >> val;
		dynamic_array.addValue(val);
	}
	dynamic_array.printArr(); cout << endl;
	dynamic_array.addValueAt(10, 1);
	dynamic_array.printArr(); cout << endl;
	dynamic_array.removeValueAt(10, 1);
	dynamic_array.printArr(); cout << endl;
	dynamic_array.removeAllValue(10);
	dynamic_array.printArr();
}