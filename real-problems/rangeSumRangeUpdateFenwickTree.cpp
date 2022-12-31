#include <iostream>
#include <vector>
using namespace std;

// segment tree, fenwick tree, sieve of eratosthenes, range minimum query,
// segmented sieve, totient function

/*
updates in fenwick tree
-range sum with point updates
-rage sum with range update
*/

const int N = 1e5 + 2;

int query(int i, vector<int> &bit, int n) {
  int ans = 0;
  while (i > 0) {
    ans += bit[i];
    i -= i & (-i);
  }
  return ans;
}

void update(int i, int inc, vector<int> &bit, int n) {
  while (i <= n) {
    bit[i] += inc;
    i += i & (-i);
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> bit(n + 10, 0);
    int u;
    cin >> u;
    while (u--) {
      int l, r, inc;
      cin >> l >> r >> inc;
      l++;
      r++;
      update(l, inc, bit, n);
      update(r + 1, -inc, bit, n);
    }
    int q;
    cin >> q;
    while (q--) {
      int w;
      cin >> w;
      w++;
      cout << query(w, bit, n) << endl;
    }
  }

  return 0;
}
