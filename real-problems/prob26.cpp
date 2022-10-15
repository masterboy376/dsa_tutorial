#include <iostream>
using namespace std;

// reverse a string

void reverse(string s, int i)
{
    int len = s.length();
    if(!(i<len)){
        return;
    }

    reverse(s, i+1);
    cout<<s[i];
}

int main()
{
    string str = "sambhav kaushik";
    reverse(str, 0);
    cout<<endl;

    return 0;
}