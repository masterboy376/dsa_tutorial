#include <iostream>
using namespace std;

// tiling problem

int countWays(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    return countWays(n-1)+countWays(n-2);
}

int main()
{
    cout<<countWays(4)<<endl;
    return 0;
}