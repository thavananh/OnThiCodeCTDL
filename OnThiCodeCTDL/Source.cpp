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
	//dynamic_array.interChangeSort_doichotructiep_tangdan();
	//dynamic_array.interchangeSort_doichotructiep_giamdan();
	//dynamic_array.selectionSort_sapxepchon_tangdan();
	//dynamic_array.selectionSort_sapxepchon_giamdan();
	//dynamic_array.bubbleSort_sapxepnoibot_tangdan();
	//dynamic_array.bubbleSort_sapxepnoibot_giamdan();
	//dynamic_array.heapsort_sapxepvundong_tangdan();
	//dynamic_array.heapsort_sapxepvundong_tangdan_28tech();
	//dynamic_array.heapsort_sapxepvundong_giamdan_28tech();
	/*DynamicArray<int> d1, d2;
	cout << "Nhap so phan tu: ";
	int n1; cin >> n1;
	for (int i = 0; i < n1; ++i)
	{
		int a;
		cin >> a;
		d1.addValue(a);
	}
	cout << "nhap so phan tu: ";
	int n2; cin >> n2;
	for (size_t i = 0; i < n2; i++)
	{
		int a;
		cin >> a;
		d2.addValue(a);
	}
	DynamicArray<int>tmp = 	merge2daydaduocsapxep<int>(d1, d2);*/
	/*tmp.printArr();*/
	dynamic_array.mergeSort_28tech(0, dynamic_array.Length() - 1);
	dynamic_array.printArr();
}