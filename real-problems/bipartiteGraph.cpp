#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
bipartite graph:
-its vertices can be divided in two disjoint and independent sets U and V such
that every edge connets a vertex in U to one in V. -the graph does not contain
any odd-length cycles. -the graph is 2 colorable.
*/
int n, m;
bool bipart;
vector<vector<int>> adj;
vector<int> col;
vector<bool> vis;

void color(int u, int curr) {
  if (col[u] != -1 and col[u] != curr) {
    bipart = false;
    return;
  }
  col[u] = curr;
  if (vis[u]) {
    return;
  }
  vis[u] = true;
  for (auto i : adj[u]) {
    color(i, curr xor 1);
  }
}

int main() {
  bipart = true;
  cin >> n >> m;
  adj = vector<vector<int>>(n);
  col = vector<int>(n, -1);
  vis = vector<bool>(n, false);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  bool cycle = false;
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      color(i, 0);
    }
  }

  cout << bipart << endl;

  return 0;
}
