#include <iostream>
using namespace std;

// seive of erstosthenes - print prime numbers

void printPrime(int n){
    int a[100] = {0};

    for(int i = 2; i<=n; i++){
        if(a[i]==0){
            for(int j = i*i; j<=n; j+=i){
                a[j]=1;
            }
        }
    }

    for(int i = 2; i<=n; i++){
        if(a[i]==0){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;

    printPrime(n);

    return 0;
}