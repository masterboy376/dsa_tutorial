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
void bubbleSort(int *arr, int n)
{ // stable, non-recursive, maybe-adaptive, worst-time = o(n^2), best-time = o(n), avg-time = o(n), space(inplace) = o(1)
    int temp, isSorted;
    for (int i = n - 1; i >= 0; i--)
    {
        isSorted=1;
        // for each of n-1 pass -> i+1
        for (int j = 0; j <= i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSorted=0;
            }
        }
        if(isSorted){
            cout<<"Sorted in pass number: "<<i+1<<endl;
            return;
        }
    }
}

int main()
{
    int size = 10;
    int arr[] = {4, 2, 7, 7, 23, 8, 9, 10, 6, 13};
    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printArray(arr, size);
    bubbleSort(arr, size);
    printArray(arr, size);

    return 0;
}