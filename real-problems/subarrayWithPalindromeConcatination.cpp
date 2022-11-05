#include "bits/stdc++.h"
using namespace std;

// sliding window approch
bool isPalindrome(int n){
    int temp = n, number = 0;
    while(temp>0){
        number = number*10 +temp%10;
        temp=temp/10;
    }
    if(number==n){
        return true;
    }
    return false;
}
int subarrayWithPalindromeConcatination(vector<int> a, int k){ //O(n*n)
    int num = 0;
    for(int i=0; i<k; i++){
        num = num*10 + a[i];
    }
    if(isPalindrome(num)){
        return 0;
    }
    for(int j=k; j<a.size(); j++){
        num = (num % (int)pow(10, k-1))*10 + a[j];
        if(isPalindrome(num)){
            return j-k+1;
        }
    }
    return -1;
}

int main()
{
    vector<int> a = {2,3,5,1,1,5};
    int k = 4;

    cout<<subarrayWithPalindromeConcatination(a,k)<<endl;

    return 0;
}