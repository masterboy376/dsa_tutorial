#include <iostream>
#include <vector>
using namespace std;

// longest increasing subsequence

const int MOD = 1e9 + 7, N = 1e3 + 2;

// memoization
int dpm[N];

int lis(vector<int> &a, int n) {
  if (dpm[n] != -1) {
    return dpm[n];
  }

  dpm[n] = 1;
  for (int i = 0; i < n; i++) {
    if (a[n] > a[i]) {
      dpm[n] = max(dpm[n], 1 + lis(a, i));
    }
  }

  return dpm[n];
}

int main() {

  // memoization
  for (int i = 0; i < N; i++) {
    dpm[i] = -1;
  }

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cout << lis(a, n - 1) << endl;

  // tabulation
  vector<int> dpt(n, 1);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (a[i] > a[j]) {
        dpt[i] = max(dpt[i], 1 + dpt[j]);
      }
    }
  }

  cout << dpt[n - 1] << endl;
  return 0;
}
