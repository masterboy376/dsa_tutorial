#include <iostream>
using namespace std;

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

    // for(int i = 0; i<m; i++){
    //     for(int j = 0; j<n; j++){
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    int row_start=0, col_start=0, row_end=m-1, col_end=n-1;
    while((row_end>=row_start) || (col_end>=col_start)){
        for(int i = col_start; i<=col_end; i++){
            cout<<a[row_start][i]<<" ";
        }
        row_start++;
        cout<<endl;
        for(int i = row_start; i<=row_end; i++){
            cout<<a[i][col_end]<<" ";
        }
        col_end--;
        cout<<endl;
        for(int i = col_end; i>=col_start; i--){
            cout<<a[row_end][i]<<" ";
        }
        row_end--;
        cout<<endl;
        for(int i = row_end; i>=row_start; i--){
            cout<<a[i][col_start]<<" ";
        }
        col_start++;
        cout<<endl;
    }

    return 0;
}