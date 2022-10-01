#include <iostream>
using namespace std;

// pair sum problem

bool brutforce(int arr[], int n, int k){
    for(int i = 0 ; i<n ; i++){
        for(int j = i+1; j<n ; j++){
            if(arr[i]+arr[j] == k){
                return true;
            }
        }
    }
    return false;
}

bool pointerMethod(int a[], int n, int k){ // O(n) -> only for sorted array
    int low = 0;
    int high = n-1;
    while(low<high){
        if(a[low]+a[high]<k){
            low++;
        }
        else if(a[low]+a[high]>k){
            high--;
        }
        else{
            return true;
        }
    }
    return false;
}

int main()
{
    int arr[]={2,4,7,11,14,16,20,21};
    int k = 31;

    cout<<brutforce(arr, 8, k)<<endl;
    cout<<pointerMethod(arr, 8, k)<<endl;


    return 0;
}