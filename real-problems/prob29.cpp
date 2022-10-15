#include <iostream>
using namespace std;

// count all possible path in a maze

int countPathInMaze (int n, int i, int j){
    if(i==n-1 && j==n-1){
        return 1;
    }
    if(i>=n || j>=n){
        return 0;
    }
    return countPathInMaze(n,i+1,j)+countPathInMaze(n,i,j+1);
}

int main()
{
    cout<<countPathInMaze(5, 0, 0)<<endl;

    return 0;
}