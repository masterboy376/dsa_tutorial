#include <algorithm>>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  // max and min diff
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  long long max = 0, min = 0;
  for (int i = 0; i < n / 2; i++) {
    max += abs(a[i] - a[i + n / 2]);
    min += abs(a[2 * i + 1] - a[2 * i]);
  }

  cout << "max: " << max << " min: " << min << endl;

  return 0;
}
