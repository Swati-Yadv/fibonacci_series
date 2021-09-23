#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void randArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 400;
    }
    cout << "Array elements are:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void merge(int arr[], int first, int mid, int last)
{
	 int i, j, k; 
    int left[mid-first+1];//sub-array to store elements in the left portion of 'arr[]'
    int right[last-mid];
    for (i = 0; i < mid-first+1; i++)
    left[i] = arr[first + i];
    for (j = 0; j < last-mid; j++)
        right[j] = arr[mid + 1 + j];
    i = 0; // initial index of sub-array left[] 
    j = 0; // initial index of sub-array right[]
    k = first; //initial index of merged array 
    for (k=first;i < mid-first+1 && j < last-mid;k++) 
    { 
        if (left[i] <= right[j]) arr[k] = left[i++];
        else arr[k] = right[j++];
    }
    while (i < mid-first+1) arr[k++] = left[i++];
    while (j < last-mid) arr[k++] = right[j++];
}


void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
void mergeSort(int arr[], int first, int last)
{
    if (first >= last)
       return;
    
	int mid = (first+ last) / 2;
    mergeSort(arr, first, mid);
    mergeSort(arr, mid + 1, last);
    merge(arr, first, mid, last);
}

int main()
{
	auto start = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);

    int num;
    cout << "Enter the number of elements:" << endl;
    cin >> num;
    int arr[num];
    int n = sizeof(arr) / sizeof(arr[0]);
    randArray(arr, n);
    cout << "\nThe sorted array is:" << endl;
    mergeSort(arr, 0, n - 1);
    printArray(arr, n);

	auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "\nTime taken by program is : " << fixed 
         << time_taken << setprecision(9);
    cout << " sec" << endl;
    return 0;
}