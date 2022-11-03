#include "bits/stdc++.h"
using namespace std;

int findPeak(int a[], int st, int en, int n){
    int mid = st+(en-st)/2;
    if((mid==0 || a[mid-1]<=a[mid]) and (mid==n-1 || a[mid+1]<=a[mid])){
        return mid;
    }
    else if(mid>0 and a[mid-1]>a[mid]){
        return findPeak(a,  st, mid-1, n);
    }
    else{
        return findPeak(a, mid+1, en, n);
    }
}

int main()
{
    int a[]={1,20,3,4,1,0};
    cout<<findPeak(a, 0, 5, 6)<<endl;


    return 0;
}