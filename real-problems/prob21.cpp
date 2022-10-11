#include <iostream>
using namespace std;

// inclusion and exclusion principle

int main()
{
    int a;
    cin>>a;
    int n, m;
    cin>>n>>m;

    if(a>n && a>m){
        int n1 = a/n;
        int n2 = a/m;
        int n3 = a/(n*m);

        cout<<(n1+n2-n3)<<endl;
    }

    return 0;
}