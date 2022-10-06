#include <iostream>
using namespace std;

// BIT manipulation problems basic

int isPowerOfTwo(int n){
    return (n && !(n & (n-1)));
}

void printSubArrays(int a[], int n){
    for(int i = 0; i<(1<<n); i++){
        for(int j = 0; j<n;j++){
            if(i & (1<<j)){
                cout<<a[j]<<" ";
            }
        }
            cout<<endl;
    }
}

int countOnes(int n){
    int count = 0;
    while(n){
        n = (n & (n-1));
        count++;
    }
    return count;
}

int main()
{
    cout<<isPowerOfTwo(15)<<endl;
    cout<<countOnes(7)<<endl;
    int s = 5;
    int a[] = {2,5,6,7,8};
    printSubArrays(a, s);

    return 0;
}