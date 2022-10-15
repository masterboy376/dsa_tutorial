#include <iostream>
using namespace std;

// friends pairing problem

int friendsPairingCenter(int n){
    if(n==0||n==1||n==2){
        return n;
    }
    return friendsPairingCenter(n-1) + friendsPairingCenter(n-2)*(n-1);
}

int main()
{
    cout<<friendsPairingCenter(4)<<endl;
    return 0;
}