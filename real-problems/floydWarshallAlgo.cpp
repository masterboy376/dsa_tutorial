
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// Floyd warshall algorithm - a DP based algo used to find shortest path btw two vertex in a graph

const int inf = 1e9;

int main() {
  vector<vector<int>> graph = {
  {0,5,inf,10},
  {inf,0,3,inf},
  {inf,inf,0,1},
  {inf,inf,inf,0},
  };
  int n = graph.size();
  vector<vector<int>> dist = graph;
  for(int k = 0; k<n; k++){
    for(int i = 0; i<n; i++){
      for(int j = 0; j<n; j++){
        if(dist[i][k] + dist[k][j] < dist[i][j]){
          dist[i][j] = dist[i][k]+dist[k][j];
        }
      }
    }
  }
  for(int i =0; i<n; i++){
    for(int j = 0; j<n; j++){
      if(dist[i][j] == inf){
        cout<<"INF ";
      }
      else{
        cout<<dist[i][j]<<" ";
      }
    }
  cout<<endl;
  }
  cout<<endl;

  return 0;
}
