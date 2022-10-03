#include <iostream>
using namespace std;

//palindrome

int main()
{
    string s;
  cout << "Type your full name: ";
  getline (cin, s);
  cout << "Your name is: " << s;

    int i = 0;
    int j = 1;
    int m = 0;
    while (s[i]!='\n')
    {
        if(s[i]=' '){
            j=0;
            i++;
        }
        j++;
        m = max(m,j);
        i++;
    }

    cout<<m<<endl;
    

    return 0;
}