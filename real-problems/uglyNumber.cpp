#include <iostream>
#include <vector>
using namespace std;

// ugly numbers - divisible by 2, 3 or 5

const int MOD = 1e9 + 7, N = 1e3 + 2;

int main() {
  int n;cin>>n;
  int c2=0, c3=0, c5=0;
  vector<int> dp(n+1);
  dp[0] = 1;
  for(int i = 1; i<=n; i++){
    dp[i] = min(2*dp[c2], min(3*dp[c3], 5*dp[c5]));
    if(2*dp[c2]==dp[i])
      c2++;
    if(3*dp[c3]==dp[i])
      c3++;
    if(5*dp[c5]==dp[i])
      c5++;
  }
  cout<<dp[n]<<endl;
  
  return 0;
}
