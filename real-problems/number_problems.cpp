#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

int isPrime(int n){
    int flag = 1;
    for(int i = 2 ; i<=sqrt(n) ; i++){
        if(n%i==0){
            flag = 0;
        }
    }
    return flag;
}

int reverseInt(int n){
    int reverse = 0;
    while(n>0){
        int lastDigit = n%10;
        reverse = reverse*10 + lastDigit;
        n = n/10;
    }
    return reverse;
}

int isArmstrong(int num){
    int n = num;
    int sum = 0;
    while(n>0){
        int lastDigit = n%10;
        sum += pow(lastDigit, 3);
        n = n/10;
    }
    if(num==sum){
        return 1;
    }
    else{
        return 0;
    }
}

int main()
{
    cout<<isPrime(13)<<endl;
    cout<<reverseInt(1234)<<endl;
    cout<<isArmstrong(13)<<endl;

    return 0;
}
