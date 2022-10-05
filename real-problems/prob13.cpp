#include <iostream>
using namespace std;

// largest word length in string

int main()
{
    string s;
    cout << "Type your full name: ";
    getline(cin, s);

    int j = 0;
    int m = 0;
    for (int i = 0 ; i<s.size(); i++){
        if (s[i] == ' ')
        {
            j = 0;
        }
        else{
        j++;
        m = max(m, j);
        }
    }

    cout<<m<<endl;

    return 0;
}