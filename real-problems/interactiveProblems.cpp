#include "bits/stdc++.h"
#include <iostream>
#include <vector>
using namespace std;

/*
interactive problems
*/

const int N = 1e5 + 2, MOD = 1e9 + 7;

int main() {
  int lo = 1, hi = 1000000;
  int ans = -1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    cout << mid << endl;
    cout << flush;
    string s;
    cin >> s;
    if (s == "<")
      hi = mid - 1;
    else {
      ans = max(ans, mid);
      lo = mid + 1;
    }
  }
  cout << "! " << ans << endl;
  cout << flush;

  return 0;
}
