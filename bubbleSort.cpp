#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr, i, i + 1);
        }
    }
    if (n - 1 > 1)
    {
        bubbleSort(arr, n - 1);
    }
}

int main()
{
    auto start = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);

    int num;
    cout<<"Enter the number of elements:"<<endl;
    cin>>num;
    int arr[num];
    int n = sizeof(arr) / sizeof(arr[0]);
    for(int i=0;i<num;i++){
        arr[i] = rand()%100;
    }
    cout<<"Elements of the array:"<<endl;
    for(int i=0;i<num;i++){
        cout<<arr[i]<<" ";
    }
    bubbleSort(arr, n);
    cout<<"\nSorted array: ";
    printArray(arr, n);

    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "\nTime taken by program is : " << fixed 
         << time_taken << setprecision(9);
    cout << " sec" << endl;
    
    return 0;
}