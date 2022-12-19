#include <iostream>
#include <vector>
using namespace std;

// number of binary string

const int MOD = 1e9 + 7, N = 1e3 + 2;

int main() {
  // tabulation
  int n;cin>>n;
  int one[n+1], zero[n+1];

  one[1] =1;
  zero[1] =1; 
  
  for(int i = 2;i<=n;i++){
    one[i] = zero[i-1];
    zero[i] = one[i-1] + zero[i-1];
  }

  cout<<one[n]+zero[n]<<endl;

  return 0;
}
