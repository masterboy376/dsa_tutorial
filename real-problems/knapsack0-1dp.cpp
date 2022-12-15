#include <iostream>
#include <vector>
using namespace std;

// 0-n knapsack

const int MOD = 1e9 + 7, N = 1e3 + 2;

int val[N], wt[N];

// memoization
int dpm[N][N];

int Knapsack(int n, int w) {
  if (w <= 0)
    return 0;

  if (n <= 0)
    return 0;

  if (dpm[n][w] != -1) {
    return dpm[n][w];
  }

  if (wt[n - 1] > w) {
    dpm[n][w] = Knapsack(n - 1, w);
  } else {
    dpm[n][w] =
        max(Knapsack(n - 1, w), Knapsack(n - 1, w - wt[n - 1]) + val[n - 1]);
  }
  return dpm[n][w];
}

int main() {

  // memoization
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      dpm[i][j] = -1;
    }
  }

  int n, w;
  cin >> n >> w;
  for (int i = 0; i < n; i++) {
    cin >> wt[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> val[i];
  }
  cout << Knapsack(n, w) << endl;
  return 0;
}
