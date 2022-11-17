#include "bits/stdc++.h"
using namespace std;

int main() {
  int k;
  cin >> k;

  vector<vector<int>> a(k);

  for (int i = 0; i < k; i++) {
    int size;
    cin >> size;

    a[i] = vector<int>(size);
    for (int j = 0; j < size; j++) {
      cin >> a[i][j];
    }
  }

  vector<int> idx(k, 0);

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;

  vector<int> ans;

  for (int i = 0; i < k; i++) {
    pq.push(make_pair(a[i][0], i));
  }

  while (!pq.empty()) {
    pair<int, int> x = pq.top();
    pq.pop();

    if (idx[x.second] < a[x.second].size()) {
      ans.push_back(x.first);
      pq.push(make_pair(a[x.second][idx[x.second] + 1], x.second));
    }
    idx[x.second] += 1;
  }

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl;
  }

  return 0;
}
