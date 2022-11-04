#include "bits/stdc++.h"
using namespace std;

// sliding window approch
int maxSumSubarray(int a[], int k, int x, int n){
    int ans = 0, sum = 0;
    for(int i = 0; i<k; i++){
        sum+=a[i];
    }
    if(sum<=x){
        ans=sum;
    }

    // int st = 0, en = k-1;
    // while(en<n){
    //     sum+=a[en];
    //     sum-=a[st];
    //     st++; en++;
    //     if(sum<=x){
    //         ans = max(ans,sum);
    //     }
    // }
    
    for(int i = k; i<n; i++){
        sum+=a[i];
        sum-=a[i-k];
        if(sum<=x){
            ans = max(ans,sum);
        }
    }

    return ans;
}

int main()
{
    int a[] = {7,5,4,6,8,9};
    int k=3;
    int x=20;

    cout<<maxSumSubarray(a,k,x,6)<<endl;

    return 0;
}