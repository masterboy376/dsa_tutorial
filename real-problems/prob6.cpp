#include <iostream>
using namespace std;

// maximum sub array sum problem

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i =0; i<n; i++){
        cin>>a[i];
    } 

    // cumulative approch - O(n^2)
    int currsum[n+1];
    currsum[0]=0;
    for (int i = 1; i<=n; i++){
        currsum[i] = currsum[i-1] + a[i-1];
    }
    int max_sum = INT8_MIN;
    for(int i = 1; i<=n; i++){
        int sum =0;
        for (int j = 0; j<i; j++){
            sum = currsum[i]-currsum[j];
            max_sum = max(sum, max_sum);
        }
    }
    cout<<max_sum<<endl;

    // Kadane's algorithm -O(n)
    int currSum = 0;
    int maxSum = INT8_MIN;
    for(int i = 0; i<n; i++){
        currSum += a[i];
        if(currSum<0){
            currSum = 0;
        }
        maxSum = max(maxSum , currSum);
    } 
    cout<<maxSum<<endl;

    return 0;
}