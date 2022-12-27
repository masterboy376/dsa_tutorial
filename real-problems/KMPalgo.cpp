#include "bits/stdc++.h"
#include <iostream>
#include <vector>
using namespace std;

/*
kmp algorithm : find s string in t.
*/

const int N = 1e5 + 2, MOD = 1e9 + 7;

vector<int> prefix_function(string s){
  int n  = s.size();
  vector<int> pi(n,0);
  for(int i =1;i<n;i++){
    int j = pi[i-1];
    while(j>0 and s[i]!=s[j])
      j = pi[j-1];
    if(s[i]==s[j]){
      j++;
    }
    pi[i] = j;
  }
  return pi;
}

int main() {
  string s = "na";
  string t = "apna collegena";
  int S = s.size(), T = t.size();

  vector<int> prefix = prefix_function(t);
  for(auto i:prefix){
    cout<<i<<" ";
  }
  cout<<endl;

  // string matching
  int pos = -1,i=0,j=0;
  while(i<t.size()){
    if(t[i]==s[j]){
      j++;
      i++;
    }
    else{
      if(j!=0)
        j=prefix[j-1];
      else
        i++;
    }
    if(j==s.size()){
      pos= i - s.size();
      break;
    }
  }

  cout<<pos<<endl;
  return 0;
}
