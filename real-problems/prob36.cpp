#include <iostream>
using namespace std;

// N-queen problem

bool isSafe(int **a, int n, int x, int y)
{
    for (int row = 0; row < x; row++)
    {
        if (a[row][y] == 1)
        {
            return false;
        }
    }
    int row = x;
    int col = y;
    while (row >= 0 && col >= 0)
    {
        if (a[row][col] == 1)
        {
            return false;
        }
        row--;
        col--;
    }
    row = x;
    col = y;
    while (row >= 0 && col < n)
    {
        if (a[row][col] == 1)
        {
            return false;
        }
        row--;
        col++;
    }
    return true;
}

bool placeQueen(int **a, int n, int x)
{
    if (x >= n)
    {
        return true;
    }
    for (int col = 0; col < n; col++)
    {
        if (isSafe(a, n, x, col))
        {
            a[x][col] = 1;
        }
        if (placeQueen(a, n, x + 1))
        {
            return true;
        }
        a[x][col] = 0; // back tracking
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    int **a = new int *[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            a[i][j] = 0;
        }
    }

    if (placeQueen(a, n, 0))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}