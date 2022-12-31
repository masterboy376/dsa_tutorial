#include "bits/stdc++.h"
#include <iostream>
#include <vector>
using namespace std;

// segment tree, fenwick tree, sieve of eratosthenes, range minimum query,
// segmented sieve, totient function

/*
square root decomposition
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

  int len = sqrtl(n) + 1;
  vector<int> b(len, 0);
  for (int i = 0; i < n; i++) {
    b[i / len] += a[i];
  }

  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    int sum = 0;
    for (int i = l; i <= r;) {
      if (i % len == 0 && i + len - 1 <= r) {
        sum += b[i / len];
        i += len;
      } else {
        sum += a[i];
        i++;
      }
    }
    cout << sum << endl;
  }

  return 0;
}
