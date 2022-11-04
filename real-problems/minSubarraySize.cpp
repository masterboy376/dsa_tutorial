#include "bits/stdc++.h"
using namespace std;

// sliding window approch
int minSubarraySize(int a[], int n, int x)
{
    int sum = 0, ans = n + 1, st = 0, en = 0;
    while (en < n)
    {

        while (sum <= x and en < n)
        {
            sum += a[en++];
        }
        while (sum > x and st <= en)
        {
            ans = min(ans, en-st);
            sum -= a[st++];
        }

        // if (sum <= x)
        // {
        //     sum += a[en++];
        // }
        // else
        // {
        //     ans = min(ans, en - st);
        //     sum -= a[st++];
        // }

    }
    return ans;
}

int main()
{
    int a[6] = {1, 4, 45, 6, 10, 19};
    int x = 51;

    cout << minSubarraySize(a, 6, x) << endl;

    return 0;
}