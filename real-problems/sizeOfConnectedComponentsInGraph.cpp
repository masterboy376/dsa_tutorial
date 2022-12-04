#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// find number of connected components and its size

vector<bool> vis;
int n,m;
vector<vector<int>> adj;
vector<int> components;

int getComp(int i ){
  if(vis[i]){
    return 0;
  }
  vis[i]=true;
  int ans=1;
  for(auto i : adj[i]){
    if(!vis[i]){
    ans+=getComp(i);
    vis[i]=true;
    }
  }
  return ans;
}

int main() {
  cin >> n >> m;
  adj = vector<vector<int>>(n);
  vis=vector<bool>(n, 0);
  components = vector<int>(n);
  for(int i = 0; i<m; i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for(int i = 0;i<n; i++){
    if(!vis[i]){
      components.push_back(getComp(i));
    }
  }
  for(auto i : components){
    if(i!=0){ 
    cout<<i<<" ";
    }
  }
  cout<<endl;

  return 0;
}
