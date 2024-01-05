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
	dynamic_array.heapsort_sapxepvundong_giamdan_28tech();
	dynamic_array.printArr(); cout << '\n';
}