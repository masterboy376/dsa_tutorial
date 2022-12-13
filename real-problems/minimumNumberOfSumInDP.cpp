#include <vector>
#include <iostream>
using namespace std;

// min number of squares
// f(x) = min( f(x-i*i)+1 , f(f)) ---> i from 1 to root(x)

const int MOD = 1e9 + 7, N = 1e5 + 2;
int dp[N];

//memoisation
int minSquare(int n) {
  if (n == 1 || n == 2 || n == 3 || n == 0) {
    if (dp[n] == MOD)
      dp[n] = n;
    return dp[n];
  }
  if (dp[n] != MOD)
    return dp[n];
  for (int i = 1; i * i <= n; i++) {
    dp[n] = min(dp[n], 1+minSquare(n-i*i));
  }
  return dp[n];
}

int main() {
  // memoisation
  for (int i = 0; i < N; i++) {
    dp[i] = MOD;
  }
  int n;
  cin >> n;
  cout << minSquare(n) << endl;

  // tabulation
  int m; cin>>m;
  vector<int> dp2(m+1,MOD);
  dp2[0]=0;
  dp2[1]=1;
  dp2[2]=2;
  dp2[3]=3;

  for(int i = 1; i*i<=m; i++){
    for(int j = 0; i*i+j<=m;j++){
      dp2[i*i + j] = min(dp2[i*i+j], 1+dp2[j]);
    }
  }
  cout<<dp2[m]<<endl;

  return 0;
}
