
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// Bellman ford algorithm - single source shortest path from a vertex u to all the vertex in the graph. If the node is unreachable, then print -1.
// note : weights of the edges can be positive as well as negative for this.

/*
dijkstra's vs bellman ford
-bellman ford can work with negative edges and negative cycles.
-it can detect negative cycles as well.
*/

const int inf = 1e7;

int main() {
  int n,m;cin >> n >> m;
  vector<int> dist(n, inf);
  vector<vector<int>> edges;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back({u, v, w});
  }
  int src; cin>>src;
  dist[src]=0;
  for(int i = 0; i<n-1; i++){
    for(auto e : edges){
      int u = e[0];
      int v = e[1];
      int w = e[2];
      dist[v]=min(dist[v], dist[u]+w);
    }
  }
  for(auto it : dist){
    cout<<it<<" ";
  }
  cout<<endl;

  return 0;
}
