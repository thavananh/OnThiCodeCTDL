#include <iostream>
using namespace std;

int linearSearch_timkiemtuyentinh(int a[], int n, int key)
{
    // for (size_t i = 0; i < n; i++)
    // {
    //     if (a[i] == key)
    //     {
    //         return i;
    //     }   
    // }
    // int i = 0;
    // while (i < n)
    // {
    //     if (a[i] == key)
    //     {
    //         return i;
    //     }
    // }
    for (size_t i = n-1; i >= 0; --i)
    {
        if (a[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch_timkiemnhiphan(int a[], int n, int left, int right, int key)
{
    // while (left <= right)
    // {
    //     int mid = left / 2 + right / 2;
    //     if (a[mid] == key)
    //     {
    //         return mid;
    //     }
    //     else if (key > a[mid])
    //     {
    //         left = mid + 1;
    //     }
    //     else
    //     {
    //         right = mid - 1;
    //     }
    // }
    if (left <= right)
    {
        int mid = left / 2 + right / 2;
        if (a[mid] == key)
        {
            return mid;
        }
        else if (key > a[mid])
        {
            binarySearch_timkiemnhiphan(a, n, mid + 1, right, key);
        }
        else
        {
            binarySearch_timkiemnhiphan(a, n, left, mid - 1, key);
        }
    }
    return -1;
}

void interChangeSort_doichotructiep_tangdan(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
            {
                swap(a[i], a[j]);
            }
        }
    }
}
void interchangeSort_doichotructiep_giamdan(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] > a[i])
            {
                swap(a[i], a[j]);
            }
        }
    }
}

void selectionSort_sapxepchon_tangdan(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i+1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(a[i], a[min]);
        }
    }
}

void selectionSort_sapxepchon_giamdan(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int max = i;
        for (int j = i+1; j < n; j++)
        {
            if (a[j] > a[max])
            {
                max = j;
            }
        }
        if (max != i)
        {
            swap(a[i], a[max]);
        }
    }
}

void insertionSort_sapxepchen_tangdan(int a[], int n)
{
    int i, j;
    for (i = 1; i < n-1; i++)
    {
        int x = a[i];
        for (j = i; j > 0 && a[j - 1] > x; j--)
        {
            a[j] = a[j - 1];
        }
        a[j] = x;
    }
}

void insertionSort_sapxepchen_giamdan(int a[], int n)
{
    int i, j;
    for (i = 1; i < n-1; i++)
    {
        int x = a[i];
        for (j = i; j > 0 && a[j - 1] < x; j--)
        {
            a[j] = a[j - 1];
        }
        a[j] = x;
    }
}

void shift()
{

}

void createHeap(int a[], int n)
{

}

void heapSort(int a[], int n);