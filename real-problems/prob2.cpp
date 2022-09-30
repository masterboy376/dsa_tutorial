#include <iostream>
using namespace std;

// record breaking

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n + 1];
        a[n] = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int r = 0;
        int max = a[0];
        for (int i = 0; i < n; i++)
        {
            if (a[i] > max)
            {
                if (a[i] > a[i + 1])
                {
                    r++;
                }
                max = a[i];
            }
        }

        cout << "Case " << t + 1 << ": " << r << endl;
    }

    return 0;
}