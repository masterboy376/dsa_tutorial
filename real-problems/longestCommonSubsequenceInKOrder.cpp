#include <iostream>
#include <vector>
using namespace std;

// longest common subseq in k order

const int MOD = 1e9 + 7, N = 1e3 + 2;

int n,m,k;
vector<int> a,b;

//memoisation
int dpm[2005][2005][7];

int solve(int i , int j , int k){
  if(i == n and j == m){
    return 0;
  }
  if(dpm[i][j][k]!=-1){
    return dpm[i][j][k];
  }
  int c1=0,c2=0,c3=0;
  if(a[i]==b[j]){
    c1=1+solve(i+1,j+1,k);
  }
  if(k>0){
    c2=1+solve(1+1,j+1,k-1);
  }
  c3=max(solve(i+1,j,k), solve(i,j+1,k));
  return dpm[i][j][k] = max(c1,max(c2,c3));
}

int main() {
   for (int i = 0; i < 2005; i++) {
    for (int j = 0; j < 2005; j++) {
      for (int k = 0; k < 7; k++) {
        dpm[i][j][k] = -1;
      }
    }
  }
  cin>>n>>m>>k;
  a = vector<int>(n);
  b = vector<int>(m);
  for(auto &i:a){
    cin>>i;
  }
  for(auto &i:b){
    cin>>i;
  }
  cout<<solve(0,0,k)<<endl;
  
  return 0;
}
