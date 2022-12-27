#include "bits/stdc++.h"
#include <iostream>
#include <vector>
using namespace std;

/*
subStr() - calculate the indices of the occurances of string s in t;
*/

const int N = 1e5 + 2, MOD = 1e9 + 7;

int p = 31;
vector<long long> powers(N);

long long calculate_hash(string s) {
  long long hash = 0;
  for (int i = 0; i < s.size(); i++) {
    hash = (hash + (s[i] - 'a' + 1) * powers[i]) % MOD;
  }
  return hash;
}

int main() {
  string s = "na";
  string t = "apna collegena";
  int S = s.size(), T = t.size();
  // O(ST)
  for (int i = 0; i < T - S + 1; i++) {
    if (t.substr(i, S) == s) {
      cout << "found at index " << i << endl;
    }
  }

  return 0;
}
