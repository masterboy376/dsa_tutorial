#include <iostream>
using namespace std;

// transpose of matrix

int main()
{
     int m, n;
    cin>>m>>n;

    int a[m][n];
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cin>>a[i][j];
        }
    }

    int temp;
    for (int i = 0; i<m; i++){
        for(int j = i+i; j<n; j++){
            temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }

    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}