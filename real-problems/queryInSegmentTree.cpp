#include "bits/stdc++.h"
#include <iostream>
#include <vector>
using namespace std;

/*
query
segment trees - query(sum) and update in subarray
conventional: query(sum)-o(n), update-o(1)
prefix array: query(sum)-o(1), update-o(n)
segment trees: query(sum)-o(log(n)), update-o(log(n))
*/

const int N = 1e5 + 2, MOD = 1e9 + 7;
int a[N] = {5, 3, 2, 4, 1, 8, 6, 10}, tree[4 * N];

void build(int node, int st, int en) {
  if (st == en) {
    tree[node] = a[st];
    return;
  }
  int mid = (st + en) / 2;
  build(2 * node, st, mid);
  build(2 * node + 1, mid + 1, en);

  tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(int node, int st, int en, int l, int r) {
  if (st > r || en < l) {
    return 0;
  }
  if (l <= st && r >= en) {
    return tree[node];
  }
  int mid = (st + en) / 2;
  int q1 = query(2 * node, st, mid, l, r);
  int q2 = query(2 * node + 1, mid + 1, en, l, r);

  return q1 + q2;
}


int main() {
  int n = 8;
  build(1, 0, n - 1);

  cout << query(1, 0, n - 1, 1, 5) << endl;

  return 0;
}
