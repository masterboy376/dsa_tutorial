#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  // Activity Selection
  // constraints
  // 1<=n<=10^5
  // 1<=start,end<=10^9
  // start<=n<=end

  int n;
  cin >> n;
  vector<vector<int>> v;
  for (int i = 0; i < n; i++) {
    int start, end;
    cin >> start >> end;
    v.push_back({start, end});
  }
  
  sort(v.begin(), v.end(),
       [&](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });

  int take = 1;
  int en = v[0][1];
  for (int i = 0; i < n; i++) {
    if (v[i][0] >= en) {
      take++;
      en = v[i][1];
    }
  }
  cout << take << endl;

  return 0;
}
