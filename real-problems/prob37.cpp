#include <iostream>
using namespace std;

//mergesort 

void printArray(int a[], int n){
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<", ";
    }
    cout<<endl;
}

void merge(int a[], int mid, int low, int high, int n){
	int i, j, k, b[n];
    i = low;
    j = mid + 1;
    k = low;
	
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
}

void mergeSort(int a[], int low, int high,int n){
	int mid;
	if(low<high){
		mid = (low+high)/2;
		mergeSort(a,low, mid,n);
		mergeSort(a,mid+1, high,n);
		merge(a, mid, low, high, n);
	}
}

int main() {
    int size = 5;
    int arr[] = {2, 5, 3, 12, 3};
    printArray(arr, size);
    mergeSort(arr, 0, size-1, size);
    printArray(arr, size);
	
	return 0;
}