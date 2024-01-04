#include  "ctdl.h"
#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Nhap so luong phan tu: ";
	cin >> n;
	//DynamicArray<int> dynamic_array(n);
	//for (int i = 0; i < n; i++)
	//{
	//	int a;
	//	cin >> a;
	//	dynamic_array.add_item(a);
	//}
	///*cout << thuatToanTimKiemNhiPhan_deQuy(dynamic_array, 5, 0, dynamic_array.length() - 1) << '\n';
	//cout << thuatToanTimKiemNhiPhanToiUu_deQuy(dynamic_array, 4, 0, dynamic_array.length() - 1) << endl;
	//cout << thuatToanTimKiemNhiPhan_KhongDeQuy(dynamic_array, 5) << endl;*/
	///*moPhongCachChayInterchangeSort_doichotructiep_tangdan(dynamic_array);*/
	//cout << endl;
	////moPhongSelectionSort_sapxepchon_tangdan(dynamic_array);
	////moPhongInsertionSort_tangdan(dynamic_array);
	//moPhongBubbleSort_tangdan(dynamic_array);
	int a[1000];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	heapSort_hcmue(a, n);
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
}