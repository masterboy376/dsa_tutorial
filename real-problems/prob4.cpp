#include <iostream>
using namespace std;

// subarray with given sum

/*
n = 5, s = 12
a = {1,2,3,7,5}
output: 2, 4
*/

int main()
{
    int n, s;
    cin >> n;
    cin >> s;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int st = 0, en = 0, currSum = a[0];
    while (en != n && st != n)
    {
        if (currSum < s)
        {
            en++;
            currSum += a[en];
        }
        else if (currSum > s)
        {
            currSum -= a[st];
            st++;
        }
        else
        {
            cout << st << " to " << en << endl;
            return 0;
        }
    }
    if(currSum!=s){
        cout<<-1<<endl;
    }

    return 0;
}