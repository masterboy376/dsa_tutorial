#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
  // adjacency matrix
  int n,m; cin>>n>>m;
  vector<vector<int>> adjm(n+1, vector<int> (n+1, 0));

  for(int i = 0; i<m; i++){
    int x,y; cin>>x>>y;

    adjm[x][y] = 1;
    adjm[y][x] = 1;
  }

  cout<<"adjacency matrix of above graph is given by: "<<endl;
  for(int i = 1 ; i<n+1; i++){
    for(int j = 0; j<n+1; j++){
      cout<<adjm[i][j]<<" ";
    }
    cout<<endl;
  }

  // adjacency list
  cin>>n>>m;
  vector<vector<int>> adjl(n+1);
  for(int i =0; i<m;i++){
    int x,y; cin>>x>>y;
    adjl[x].push_back(y);
    adjl[y].push_back(x);
    }
  cout<<"adjacency list of above graph is given by: "<<endl;
  for(int i = 1 ; i<n+1; i++){
    cout<<i<<": ";
    for(int j : adjl[i]){// another way of iterating in cpp17 and above
      cout<<j<<" ";
    }
    cout<<endl;
  }
  
  return 0;
}
