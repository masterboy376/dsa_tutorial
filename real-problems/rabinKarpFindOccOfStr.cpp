#include "bits/stdc++.h"
#include <iostream>
#include <vector>
using namespace std;

/*
rabin karp algorithm
*/

const int N = 1e5 + 2, MOD = 1e9 + 7;

int p = 31;
vector<long long> powers(N);

int main() {
  string s = "na";
  string t = "apna collegena";
  int S = s.size(), T = t.size();

  powers[0]=1;
  for(int i = 1;i<N;i++){
    powers[i] = (powers[i-1]*p)%MOD;
  }

  vector<long long> h(T+1,0);
  for(int i = 0;i<T;i++){
    h[i+1] = (h[i] + (t[i]-'a'+1)*powers[i])%MOD;
  }

  long long h_s = 0;
  for(int i = 0;i<S;i++){
    h_s = (h_s + (s[i] - 'a' + 1)*powers[i])%MOD;
  }
  for(int i = 0;i+S-1<T; i++){
    long long cur_h = (h[i+S] - h[i] + MOD)%MOD;
    if(cur_h == (h_s*powers[i])%MOD){
      cout<<"found at index "<<i<<endl;
    }
  }

  return 0;
}
