#include <iostream>
using namespace std;


// quick sort
int partition(int *A, int low, int high){
    int pivot = A[low];
    int i = low+1;
    int j = high;
    int temp;

    do{
        while (A[i]<=pivot)
        {
            i++;
        }
        while (A[j]>pivot)
        {
            j--;
        }
        if(i < j){
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i<j);

    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    
    return j;
}

void quickSort(int *A, int low, int high){
    int partitionIndex;
    if(low < high){
        partitionIndex = partition(A, low, high);
        quickSort(A, low, partitionIndex-1);
        quickSort(A, partitionIndex+1, high);
    }
}
/*
3 5 4 7 2 1 6
3 1 4 7 2 5 6
3 1 2 7 4 5 6
7 1 2 3 4 5 6

7 1 2 3 4 5 6
6 1 2 3 4 5 7

6 1 2 3 4 5 7
5 1 2 3 4 6 7

5 1 2 3 4 6 7
4 1 2 3 5 6 7

4 1 2 3 5 6 7
3 1 2 4 5 6 7

3 1 2 4 5 6 7
2 1 3 4 5 6 7

2 1 3 4 5 6 7
1 2 3 4 5 6 7
*/
int main()
{
    int a[7]={3,5,4,7,2,1,6};
    quickSort(a, 0,6);
    for(int i = 0; i<5; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    return 0;
}