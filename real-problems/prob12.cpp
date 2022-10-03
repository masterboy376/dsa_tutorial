#include <iostream>
using namespace std;

//palindrome

int main()
{
    int n;
    cin>>n;
    char a[n+1];
    cin>>a;

    bool flag = true;
    for(int i = 0; i<n/2; i++){
        if(a[i] != a[n-1-i]){
            flag = false;
            break;
        }
    }

    cout<<flag<<endl;

    return 0;
}