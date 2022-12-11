#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// dynamic programming: fibonacci series

const int inf = 1e5 + 2;

int dp[inf];

int fib_func(int n) {
  if (n == 0)
    return 0;
  if (n == 1)
    return 0;
  if (n == 2)
    return 1;

  if (dp[n] != -1)
    return dp[n];

  return dp[n] = fib_func(n - 1) + fib_func(n - 2);
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < inf; i++) {
    dp[i] = -1;
  }

  cout << fib_func(n) << endl;

  return 0;
}
