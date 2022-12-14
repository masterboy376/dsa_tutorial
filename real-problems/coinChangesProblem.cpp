#include <iostream>
#include <vector>
using namespace std;

// coin changes problem

const int MOD = 1e9 + 7, N = 1e3 + 2;

// memoization
int dp[N][N];

int coinChange(vector<int> &a, int n, int x) {
  if (x == 0)
    return 1;
  if (x < 0)
    return 0;
  if (n <= 0)
    return 0;
  if (dp[n][x] != -1) {
    return dp[n][x];
  }
  dp[n][x] = coinChange(a, n, x - a[n - 1]) + coinChange(a, n - 1, x);
  return dp[n][x];
}

int main() {

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      dp[i][j] = -1;
    }
  }
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int x;
  cin >> x;
  cout << coinChange(a, n, x) << endl;

  // tabulation
  vector<vector<int>> dp2(n + 1, vector<int>(x + 1, 0));
  dp2[0][0] = 1;
  for (int i = 1; i < n + 1; i++) {
    for (int j = 0; j < x + 1; j++) {
      if (j - a[i - 1] >= 0)
        dp2[i][j] += dp2[i][j - a[i - 1]];
      dp2[i][j] += dp2[i - 1][j];
    }
  }
  cout << dp2[n][x] << endl;

  return 0;
}
