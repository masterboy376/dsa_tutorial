#include <iostream>
using namespace std;

// matrix sorted search

int main()
{
    int m, n;
    cin >> m >> n;
    int a[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    int target;
    cin >> target;

    bool flag = false;
    int r = 0, c = n - 1;
    while (r < m && c >= 0)
    {
        if (a[r][c] == target)
        {
            flag = true;
            break;
        }
        else if(a[r][c]>target){
            c--;
        }
        else{
            r++;
        }
    }
    cout<<flag<<endl;

    return 0;
}