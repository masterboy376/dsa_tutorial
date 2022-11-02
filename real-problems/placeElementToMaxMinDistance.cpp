#include "bits/stdc++.h"
using namespace std;

bool isFeasable(int mid, int arr[], int n, int k)
{
    int pos = arr[0], elements = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - pos >= mid)
        {
            pos = arr[i];
            elements++;
        }
            if (elements == k)
            {
                return true;
            }
    }
    return false;
}

int largestMinDistance(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int result = -1, left = 1, right = arr[n + 1];
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (isFeasable(mid, arr, n, k))
        {
            result = max(result, mid);
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return result;
}

int main()
{
    int a[] = {1, 2, 8, 4, 9};
    int n = 5, k = 3;

    cout << largestMinDistance(a, n, k) << endl;

    return 0;
}