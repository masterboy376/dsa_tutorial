#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
a topological odering is an odering of the nodes in a directed graph where for
each directed edge from node A to node B, node A always appears before node B in
the odering. note: topological odering are NOT unique. not all graph have a
topolofical sort. eg: cyclic graph with no start only exist for acyclic graph.
*/

int main() {
  int n, m;
  cin >> n >> m;
  int cnt = 0;
  vector<vector<int>> adj_list(n);
  vector<int> indeg(n, 0);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    // u --> v
    adj_list[u].push_back(v);
    indeg[v]++;
  }

  queue<int> pq;
  for (int i = 0; i < n; i++) {
    if (indeg[i] == 0) {
      pq.push(i);
    }
  }

  while (!pq.empty()){
    cnt++;
    int x = pq.front();
    pq.pop();
    cout << x << " ";
    for (auto it : adj_list[x]) {
      indeg[it]--;
      if (indeg[it] == 0) {
        pq.push(it);
      }
    }
    }
    cout << endl;

  return 0;
}
