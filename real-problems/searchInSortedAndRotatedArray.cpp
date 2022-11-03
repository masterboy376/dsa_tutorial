#include "bits/stdc++.h"
using namespace std;

int searchInRotatedArray(int a[], int left, int right, int key){
    if(left>right){
        return -1;
    }
    int mid = (left+right)/2;
    if(a[mid]==key){
        return mid;
    }
    if(a[left] <= a[mid]){
        if(key>=a[left] and key<=a[mid]){
            return searchInRotatedArray(a, left, mid-1, key);
        }
        return searchInRotatedArray(a, mid+1, right, key);
    }
        if(key>=a[mid] and key<=a[right]){
            return searchInRotatedArray(a, mid+1, right, key);
        }
        return searchInRotatedArray(a, left, mid-1, key);
}

int main()
{
    int a[5] = {50,10,20,30,40};
    cout<<searchInRotatedArray(a, 0, 4, 10)<<endl;

    return 0;
}