#include <iostream>
using namespace std;

// largest word in string

int main()
{
    string s;
    cout << "Type your full name: ";
    getline(cin, s);

    int currStart = 0;
    int currLen = 0;
    int maxStart = 0;
    int maxLen = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            currStart = i + 1;
            currLen = 0;
        }
        else
        {
            currLen++;
            if (maxLen < currLen)
            {
                maxLen = currLen;
                maxStart = currStart;
            }
        }
    }

    for (int i = maxStart; i < maxLen + maxStart; i++)
    {
        cout << s[i];
    }
    cout << endl;

    return 0;
}