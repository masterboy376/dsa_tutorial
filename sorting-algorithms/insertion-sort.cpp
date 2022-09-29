#include <iostream>
using namespace std;

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

void insertionSort(int *arr, int n)
{ // stable, non-recursive, non-adaptive, worst-time = o(n^2), best-time = o(n^2), avg-time = o(n^2), space(inplace) = o(1)
    int key, j;
    for (int i = 1; i < n; i++)
    {
        // for each of n-1 pass -> i+1
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main()
{
    int size = 10;
    int arr[] = {4, 2, 7, 7, 23, 8, 9, 10, 6, 13};

    printArray(arr, size);
    insertionSort(arr, size);
    printArray(arr, size);

    return 0;
}