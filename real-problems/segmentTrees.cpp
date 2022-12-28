#include "bits/stdc++.h"
#include <iostream>
#include <vector>
using namespace std;

/*
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

int main() {
  int n = 8;
  build(1, 0, n - 1);

  for (int i = 1; i < 16; i++) {
    cout << tree[i] << endl;
  }
  return 0;
}
