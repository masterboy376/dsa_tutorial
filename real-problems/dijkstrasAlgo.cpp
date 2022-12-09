
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// dijkstra's algorithm - single source shortest path from a vertex u to all the vertex in the graph. If the node is unreachable, then print -1.
// note : weights of the edges must be positive for this.

const int inf = 1e7;

int main() {
  int n,m;cin >> n >> m;
  vector<int> dist(n+1, inf);
  vector<vector<pair<int,int>>> graph(n+1);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
  }
  int src; cin>>src;
  dist[src]=0;
  set<pair<int,int>> s;
  //{wt.vertex}
  s.insert({0,src});
  while(!s.empty()){
    auto x = *(s.begin());
    s.erase(x);
    for(auto it : graph[x.second]){
      if(dist[it.first]>dist[x.second]+it.second){
        s.erase({ dist[it.first], it.first });
        dist[it.first] = dist[x.second] + it.second;
        s.insert({ dist[it.first], it.first });
      }
    }
  }
  for(int i = 1; i<n+1; i++){
    if(dist[i]<inf){
      cout<<dist[i]<<" ";
    }
    else{
      cout<<-1<<" ";
    }
  }
  cout<<endl;

  return 0;
}
