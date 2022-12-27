#include "bits/stdc++.h"
#include <iostream>
#include <vector>
using namespace std;

/*
string hash
*/

const int N = 1e5 + 2, MOD = 1e9 + 7;

int p = 31;
vector<long long> powers(N);

long long calculate_hash(string s){
  long long hash = 0;
  for(int i =0;i<s.size();i++){
    hash = (hash + (s[i]-'a'+1)*powers[i])%MOD;
  }
  return hash;
}

int main() {
  vector<string> strings = {"aa", "ab", "aa", "b", "cc", "aa"};
  int distinct = 0;

  // conventional
  // o(nmlog(n))
  sort(strings.begin(), strings.end());
  // log(nm)
  for (int i = 0; i < strings.size(); i++) {
    if (i == 0 or strings[i] != strings[i - 1]) {
      distinct++;
    }
  }
  cout << distinct << endl;

  // string hashing
  powers[0] = 1;
  for (int i = 1; i < N; i++) {
    powers[i] = (powers[i - 1] * p) % MOD;
  }
  vector<long long> hashes;
  for (auto w : strings) {
    hashes.push_back(calculate_hash(w));
  }
  // o(nlog(n))
  sort(hashes.begin(), hashes.end());
  distinct = 0;
  // log(n)
  for (int i = 0; i < hashes.size(); i++) {
    if (i == 0 or hashes[i] != hashes[i - 1]) {
      distinct++;
    }
  }
  cout << distinct << endl;

  return 0;
}
