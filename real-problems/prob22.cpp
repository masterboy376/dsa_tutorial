#include <iostream>
using namespace std;

// inclusion and exclusion principle: euclid algorithm to find GCD ( HCF )

int hcf(int a, int b){
    while(b!=0){
        int rem = a%b;
        a=b;
        b=rem;
    }
    return a;
}

int main()
{
    cout<<hcf(56,28)<<endl;

    return 0;
}