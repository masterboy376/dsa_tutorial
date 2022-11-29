#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  // fractional knapsack
  int n;cin>>n;

  vector<pair<int,int>> a(n);

  for(int i = 0; i<n; i++){
    cin>>a[i].first>>a[i].second;
  }
  int w; cin>>w;
  sort(a.begin(), a.end(), [&](pair<int,int> &x, pair<int,int> &y){
    double val1 = (double) x.first/x.second;
    double val2 = (double) y.first/y.second;
    return val1 > val2;
  });

  int ans = 0;
  for(int i = 0; i<n; i++){
    if(w>=a[i].second){
      ans+=a[i].first;
      w-=a[i].second;
      continue;
    }
    double vpw = (double) a[i].first/a[i].second;
    ans += vpw*w;
    w=0;
    break;
  }

  cout<<ans<<endl;

  return 0;
}
