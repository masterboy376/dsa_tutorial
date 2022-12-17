#include <iostream>
#include <vector>
using namespace std;

// longest common subsequence

const int MOD = 1e9 + 7, N = 1e3 + 2;

//memoization
int dpm[N][N];

int lcs(string &s1, string &s2, int n,int m){
  if(n==0 || m==0)
    return 0;
  if(dpm[n][m]!=-1)
    return dpm[n][m];
  if(s1[n-1]==s2[m-1])
    dpm[n][m] = 1+lcs(s1,s2,n-1,m-1);
  else{
    dpm[n][m] = max( lcs(s1,s2,n,m-1), lcs(s1,s2,n-1,m) );
  }
  return dpm[n][m];
}

int main() {
  string s1,s2;
  cin>>s1>>s2;

  int n = s1.size(), m = s2.size();

  // memoization
  for(int i =0;i<N;i++){
    for(int j = 0;j<N;j++){
      dpm[i][j]=-1;
    }
  }
  cout<<lcs(s1,s2,n,m)<<endl;

  // tabulation
  vector<vector<int>> dpt(n+1, vector<int>(m+1, -1));

  for(int i = 0; i<n+1; i++){
    for(int j = 0; j<m+1; j++){
      if(i==0 || j==0){
        dpt[i][j]=0;
        continue;
      }
      if(s1[i-1]==s2[j-1]){
        dpt[i][j] = 1+dpt[i-1][j-1];
      }
      else{
        dpt[i][j] = max(dpt[i-1][j],dpt[i][j-1]);
      }
    }
  }
  cout<<dpt[n][m]<<endl;
  
  return 0;
}
