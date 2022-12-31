#include "bits/stdc++.h"
#include <iostream>
#include <vector>
using namespace std;

// segment tree, fenwick tree, sieve of eratosthenes, range minimum query,
// segmented sieve, totient function

/*
square root decomposition: find min in given range
*/

const int N = 1e5 + 2, MOD = 1e9 + 7;
;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }

  int len = (int)sqrtl(n) + 1;
  vector<int> b(len, MOD);
  for (int i = 0; i < n; i++) {
    b[i / len] += min(b[i / len], a[i]);
  }

  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    int ans = MOD;
    for (int i = l; i <= r;) {
      if (i % len == 0 && i + len - 1 <= r) {
        ans = min(ans, b[i / len]);
        i += len;
      } else {
        ans = min(ans, a[i]);
        i++;
      }
    }
    cout << ans << endl;
  }

  return 0;
}
