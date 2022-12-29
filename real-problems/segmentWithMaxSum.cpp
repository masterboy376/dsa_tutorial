// #include "bits/stdc++.h"
#include <iostream>
#include <vector>
using namespace std;

// segment tree, fenwick tree, sieve of eratosthenes, range minimum query,
// segmented sieve, totient function

/*
segment with max sum
*/

class segmentNode {
public:
  long long pref, suff, sum, ans;
  segmentNode() {
    pref = 0;
    suff = 0;
    sum = 0;
    ans = 0;
  }
  segmentNode(long long pref1, long long suff1, long long sum1,
              long long ans1) {
    pref = pref1;
    suff = suff1;
    sum = sum1;
    ans = ans1;
  }
};
const int N = 1e5 + 2, MOD = 1e9 + 7;
vector<long long> a(N);
vector<segmentNode> tree(4 * N);

void build(int node, int st, int en) {
  if (st == en) {
    if (a[st] <= 0) {
      tree[node].pref = 0;
      tree[node].suff = 0;
      tree[node].sum = a[st];
      tree[node].ans = 0;
    } else {
      tree[node].pref = a[st];
      tree[node].suff = a[st];
      tree[node].sum = a[st];
      tree[node].ans = a[st];
    }
    return;
  }
  int mid = (st + en) / 2;
  build(2 * node, st, mid);
  build(2 * node + 1, mid + 1, en);

  tree[node].sum = tree[2 * node].sum + tree[2 * node + 1].sum;
  tree[node].pref =
      max(tree[2 * node].pref, tree[2 * node].sum + tree[2 * node + 1].pref);
  tree[node].suff = max(tree[2 * node + 1].suff,
                        tree[2 * node + 1].sum + tree[2 * node].suff);
  tree[node].ans = max((tree[2 * node].suff + tree[2 * node + 1].pref),
                       max(tree[2 * node].sum, tree[2 * node + 1].sum));
}

void update(int node, int st, int en, int idx, int val) {
  if (st == en) {
    a[st] = val;
    if (a[st] <= 0) {
      tree[node].pref = 0;
      tree[node].suff = 0;
      tree[node].sum = a[st];
      tree[node].ans = 0;
    } else {
      tree[node].pref = a[st];
      tree[node].suff = a[st];
      tree[node].sum = a[st];
      tree[node].ans = a[st];
    }
    return;
  }

  int mid = (st + en) / 2;
  if (idx <= mid) {
    update(2 * node, st, mid, idx, val);
  } else {
    update(2 * node + 1, mid + 1, en, idx, val);
  }

  tree[node].sum = tree[2 * node].sum + tree[2 * node + 1].sum;
  tree[node].pref =
      max(tree[2 * node].pref, tree[2 * node].sum + tree[2 * node + 1].pref);
  tree[node].suff = max(tree[2 * node + 1].suff,
                        tree[2 * node + 1].sum + tree[2 * node].suff);
  tree[node].ans = max((tree[2 * node].suff + tree[2 * node + 1].pref),
                       max(tree[2 * node].sum, tree[2 * node + 1].sum));
}

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  build(1, 0, n - 1);

  cout << tree[1].ans << endl;

  for (int i = 0; i < m; i++) {
    int idx;
    long long val;
    cin >> idx >> val;
    update(1, 0, n - 1, idx, val);
    cout << tree[1].ans << endl;
  }

  return 0;
}
