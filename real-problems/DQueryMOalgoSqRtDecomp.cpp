#include "bits/stdc++.h"
#include <iostream>
#include <vector>
using namespace std;

// segment tree, fenwick tree, sieve of eratosthenes, range minimum query,
// segmented sieve, totient function, MO's algo

/*
square root decomposition( MO's algo): DQuery
*/

const int N = 2e5 + 2, MOD = 1e9 + 7;
int rootN;

struct Q {
  int idx, l, r;
};
Q qs[N];

bool compare(Q q1, Q q2) {
  if (q1.l / rootN == q2.l / rootN) {
    return q1.r > q2.r;
  }
  return q1.l < q2.l;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }

  rootN = (int)sqrtl(n);

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    qs[i].l = l;
    qs[i].r = r;
    qs[i].idx = i;
  }
  sort(qs, qs + q, compare);

  vector<int> ans(q);
  int curr_l = 0, curr_r = -1, l, r;
  int curr_ans = 0;
  vector<int> freq(10 * N, 0);

  for (int i = 0; i < q; i++) {
    l = qs[i].l;
    r = qs[i].r;
    l--;
    r--;
    while (curr_r < r) {
      curr_r++;
      freq[a[curr_r]]++;
      if (freq[a[curr_r]] == 1) {
        curr_ans++;
      }
    }
    while (curr_l > l) {
      curr_l--;
      freq[a[curr_l]]++;
      if (freq[a[curr_l]] == 1) {
        curr_ans++;
      }
    }
    while (curr_l < l) {
      freq[a[curr_l]]--;
      curr_l++;
      if (freq[a[curr_l]] == 0) {
        curr_ans--;
      }
    }
    while (curr_r > r) {
      freq[a[curr_r]]--;
      curr_r--;
      if (freq[a[curr_r]] == 0) {
        curr_ans--;
      }
    }
    ans[qs[i].idx] = curr_ans;
  }

  for (int i = 0; i < q; i++) {
    cout << ans[i] << endl;
  }

  return 0;
}
