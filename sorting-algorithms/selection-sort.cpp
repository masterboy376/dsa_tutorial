#include <iostream>
using namespace std;

void printArray(int* arr, int n){
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<", ";
    }
    cout<<endl;
}

void selectionSort(int* arr, int n){ // stable, non-recursive, non-adaptive, worst-time = o(n^2), best-time = o(n^2), avg-time = o(n^2), space(inplace) = o(1)
    int temp, min;
    for(int i = 0; i<n; i++){
        // for each of n-1 pass 
        min=i;
        for(int j = i+1; j<n; j++){
            if(arr[min]>arr[j]){
                min = j;
            }
        }
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    int size = 10;
    int arr[] = {4,2,7,7,23,8,9,10,6,13};

    printArray(arr, size);
    selectionSort(arr, size);
    printArray(arr, size);


    return 0;
}