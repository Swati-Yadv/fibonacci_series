#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void randArray(int arr[],int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 400;
    }
    cout<<"Array elements are"<<endl;
     for(int i=0;i<n;i++)
    {
     cout<<arr[i]<<" ";
    }
}

void insertionSort(int arr[],int j,int n)
{
    int i,key;
    key = arr[j];
    i = j;
    while(i>0 && arr[i-1]>key)
    {
        arr[i]= arr[i-1];
        i=i-1;
    }
    arr[i] = key;
    if(j+1<=n){
        insertionSort(arr,j+1,n);
    }
}

void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
     cout<<arr[i]<<" ";
    }
}

int main()
{
    auto start = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
  
    int num;
    cout << "Enter the number of elements:" << endl;
    cin >> num;
    int arr[num];
    int n= sizeof(arr)/sizeof(arr[0]);
    randArray(arr,n);
    cout<<"Sorted array: "<<endl;
    insertionSort(arr,1,n-1);
    printArray(arr,n);

    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "\nTime taken by program is : " << fixed 
         << time_taken << setprecision(9);
    cout << " sec" << endl;
    return 0;
}
