#include "bits/stdc++.h"
#include <iostream>
#include <vector>
using namespace std;

/*
number of minimums in a segment trees
*/

const int N = 1e5 + 2, MOD = 1e9 + 7;
int a[N] = {1, 1, 2, 1, 1, 1, 1, 1};
pair<int, int> tree[4 * N];

void build(int node, int st, int en) {
  if (st == en) {
    tree[node].first = a[st];
    tree[node].second = 1;
    return;
  }
  int mid = (st + en) / 2;
  build(2 * node, st, mid);
  build(2 * node + 1, mid + 1, en);

  if (tree[2 * node].first < tree[2 * node + 1].first) {
    tree[node].first = tree[2 * node].first;
    tree[node].second = tree[2 * node].second;
  } else if (tree[2 * node + 1].first < tree[2 * node].first) {
    tree[node].first = tree[2 * node + 1].first;
    tree[node].second = tree[2 * node + 1].second;
  } else {
    tree[node].first = tree[2 * node].first;
    tree[node].second = tree[2 * node].second + tree[2 * node + 1].second;
  }
}

pair<int, int> query(int node, int st, int en, int l, int r) {
  if (st > r || en < l) {
    return make_pair(MOD, -1);
  }
  if (l <= st && r >= en) {
    return tree[node];
  }
  int mid = (st + en) / 2;
  pair<int, int> q1 = query(2 * node, st, mid, l, r);
  pair<int, int> q2 = query(2 * node + 1, mid + 1, en, l, r);

  pair<int, int> ans;
  if (q1.first < q2.first) {
    ans = q1;
  } else if (q2.first < q1.first) {
    ans = q2;
  } else {
    ans.first = q1.first;
    ans.second = q1.second + q2.second;
  }
  return ans;
}

void update(int node, int st, int en, int idx, int val) {
  if (st == en) {
    a[st] = val;
    tree[node].first = val;
    tree[node].second = 1;
    return;
  }

  int mid = (st + en) / 2;
  if (idx <= mid) {
    update(2 * node, st, mid, idx, val);
  } else {
    update(2 * node + 1, mid + 1, en, idx, val);
  }

  if (tree[2 * node].first < tree[2 * node + 1].first) {
    tree[node].first = tree[2 * node].first;
    tree[node].second = tree[2 * node].second;
  } else if (tree[2 * node + 1].first < tree[2 * node].first) {
    tree[node].first = tree[2 * node + 1].first;
    tree[node].second = tree[2 * node + 1].second;
  } else {
    tree[node].first = tree[2 * node].first;
    tree[node].second = tree[2 * node].second + tree[2 * node + 1].second;
  }
}

int main() {
  int n = 8;
  build(1, 0, n - 1);

  cout << query(1, 0, n - 1, 1, 2).first << ", "
       << query(1, 0, n - 1, 1, 2).second << endl;
  update(1, 0, n - 1, 5, 1);
  cout << query(1, 0, n - 1, 1, 2).first << ", "
       << query(1, 0, n - 1, 1, 2).second << endl;

  return 0;
}
