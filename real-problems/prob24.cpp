#include <iostream>
using namespace std;

// print number in increasing and decreasing 

void inc(int n){
    if(n<=0){
        return;
    }
    inc(n-1);
    cout<<n<<" ";
}

void dec(int n){
    if(n<=0){
        return;
    }
    cout<<n<<" ";
    dec(n-1);
}

int main()
{
    int n = 5;
    
    dec(n);
    cout<<endl;

    inc(n);
    cout<<endl;

    return 0;
}