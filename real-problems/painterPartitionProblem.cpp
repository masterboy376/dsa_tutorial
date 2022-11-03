#include "bits/stdc++.h"
using namespace std;

bool isPossible(int a[], int n, int m, int min){
    int studentRequired=1, sum=0;

    for(int i = 0; i<n; i++){
        if(a[i]>min){
            return false;
        }
        if(sum+a[i]>min){
            studentRequired++;
            sum = a[i];
            if(studentRequired>m){
                return false;
            }
        }
        else{
            sum+=a[i];
        }
    }
    return true;
}

int minTime( int a[], int n, int m){
    int sum = 0, k=0;
    if(n<m){
        return -1;
    }
    for (int i=0;i<n;i++){
        k=max(k,a[i]);
        sum = sum+a[i];
    }
    int start = k, end = sum, ans = INT32_MAX;
    while(start<=end){
        int mid = (start+end)/2;
        if(isPossible(a,n,m,mid)){
            ans = min(ans, mid);
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}

int main()
{
    int a[]={10,20,30,40};
    int m = 4;

    cout<<minTime(a,4,m)<<endl;

    return 0;
}