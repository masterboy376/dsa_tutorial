#include <iostream>
#include <vector>
using namespace std;

// matrix chain multiplication

const int MOD = 1e9 + 7, N = 1e3 + 2;

int a[N];
//memoization
int dpm[N][N];

int mcm(int i, int j){
  if(i==j)
    return 0;
  if(dpm[i][j]!=-1)
    return dpm[i][j];
  
  dpm[i][j] = MOD;
  for(int k = i; k<j; k++){
    dpm[i][j] = min(dpm[i][j], mcm(i,k)+mcm(k+1,j)+a[i-1]*a[k]*a[j]);
  }
    return dpm[i][j];
}

int main() {
  int n;cin>>n;
  for(int i = 0; i<n; i++){
    cin>>a[i];
  }

  //memoization
  for(int i = 0; i<N; i++){
    for(int j = 0; j<N; j++){
      dpm[i][j] = -1;
    }
  }
  cout<<mcm(1, n-1)<<endl;

  //tabulation
  int dpt[n+1][n+1];
  for(int i = 1;i<n;i++){
    dpt[i][i]=0;
  }
  for(int l = 2; l<n; l++){
    for(int i = 1; i<n-l+1; i++){
      int j = i+l-1;
      dpt[i][j] = MOD;
      for(int k =i;k<j; k++){
        dpt[i][j]=min(dpt[i][j], dpt[i][k]+dpt[k+1][j]+a[i-1]*a[k]*a[j]);
      }
    }
  }
  cout<<dpt[1][n-1]<<endl;
  return 0;
}
