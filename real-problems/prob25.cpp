#include <iostream>
using namespace std;

// tell first and last occurance of a number in array

int firstOccurance(int a[], int n, int i, int key){
    if(i==n){
        return -1;
    }
    if(a[i]==key){
        return i;
    }
    return firstOccurance(a, n, i+1,key);
}

int lastOccurance(int a[], int n, int i, int key){
    if(i==n){
        return -1;
    }
    int restArray = lastOccurance(a, n, i+1,key);
    if(restArray!=-1){
        return restArray;
    }
    if(a[i]==key){
        return i;
    }
    return -1;
}

int main()
{
    int a[] = {4,2,1,2,5,2,7};
    cout<<firstOccurance(a,7,0,2)<<endl;
    cout<<lastOccurance(a,7,0,2)<<endl;

    return 0;
}