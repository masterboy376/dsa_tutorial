#include <iostream>
#include <vector>
using namespace std;

// 0-n knapsack

const int MOD = 1e9 + 7, N = 1e3 + 2;

// memoization
int dpm[N][N];

int main() {
  // tabulation
  int n =5,W=11;
  vector<int> wt = {3,2,4,5,1};
  vector<int> val = {4,3,5,6,1};
  vector<int> dp(W+1 , 0);
  for(int j = 0;j<=W;j++){
    for(int i = 0;i<n;i++){
      if(j-wt[i]>=0)
        dp[j] = max(dp[j], val[i]+dp[j-wt[i]]);
    }
  }
  cout<<dp[W]<<endl;
  
  return 0;
}
