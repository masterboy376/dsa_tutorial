#include <iostream>
using namespace std;

int sumSubArray(int* a, int n){
    int sum = 0;
    for (int i = 0; i<n; i++){
        for (int j = i; j<n; j++){
            sum+=a[j];
        }
    }
    return sum;
}

void longestArithmaticIntArr(int* arr, int n){

}

int main()
{
    int s= 7;
    int arr[]={10,7,4,6,8,10,11};

    cout<<sumSubArray(arr,s)<<endl;

    return 0;
}