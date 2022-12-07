#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// kruskal algorithm

/*
given a undirected and connected graph G(V,E) , a spanning tree of the graph G
is a tree that spans G(that is , it include every vertex of G) and is a subgraph
of G (every edge in the tree belongs to G).

const of the spanning tree is the sum of the weights of all the edges in the
tree.

there can be many spanning trees

minimum spanning tree ehere the cost of is minimun among all the spanning trees

there also can be many minimum spanning trees (MST)

found by Kruskal Algorithm.
time complexity: O(E logV) or O(E logE)
space complexity: O(E+V)
*/

int N = 1e5 + 6;
vector<int> parent(N);
vector<int> sz(N);
void make_set(int v) {
  parent[v] = v;
  sz[v] = 1;
}

int find_set(int v) {
  if (v == parent[v])
    return v;
  return parent[v] = find_set(parent[v]);
}

void union_set(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (sz[a] < sz[b]) {
      swap(a, b);
    }
    parent[b] = a;
    sz[a] += sz[b];
  }
}

int main() {
  for (int i = 0; i < N; i++) {
    make_set(i);
  }

  int n, m;
  cin >> n >> m;
  vector<vector<int>> edges;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back({w, u, v});
  }
  sort(edges.begin(), edges.end());
  int cost = 0;
  for (auto i : edges) {
    int w = i[0];
    int u = i[1];
    int v = i[2];
    int x = find_set(u);
    int y = find_set(v);
    if (x == y) {
      continue;
    } else {
      cout << u << " " << v << " " << w << endl;
      cost += w;
      union_set(u, v);
    }
  }
  cout << cost << endl;

  return 0;
}
