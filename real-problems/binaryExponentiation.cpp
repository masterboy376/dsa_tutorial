#include <iostream>
#include <vector>
using namespace std;

/*
binary exponentiation
*/
const int N = 1e5 + 2, MOD = 1e9 + 7;

int powerRec(int a, int n) {
  if (n == 0)
    return 1;
  int p = (powerRec(a, n / 2)) % MOD;
  if (n & 1) {
    return (((p * p) % MOD) * a) % MOD;
  } else {
    return (p * p) % MOD;
  }
}

int powerIter(int a, int n) {
  int ans = 1;
  while (n > 0) {
    if (n & 1) {
      ans = (ans * a) % MOD;
    }
    a = (a * a) % MOD;
    n = n >> 1;
  }
  return ans;
}

int main() {
  int a, n;
  cin >> a >> n;
  a %= MOD;
  cout << powerRec(a, n) << endl;
  cout << powerIter(a, n) << endl;

  return 0;
}
