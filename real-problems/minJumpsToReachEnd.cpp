#include <iostream>
#include <vector>
using namespace std;

// matrix chain multiplication

const int MOD = 1e9 + 7, N = 1e3 + 2;


int main() {
  // tabulation
  vector<int> dpt(N, MOD);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  if (a[0] == 0) {
    cout << -1 << endl;
    return 0;
  }

  dpt[0] = 0;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (i <= j + a[j]) {
        dpt[i] = min(dpt[i], dpt[j]+1);
      }
    }
  }

  cout<<dpt[n-1]<<endl;

  return 0;
}
