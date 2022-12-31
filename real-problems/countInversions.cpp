#include "bits/stdc++.h"
#include <iostream>
#include <vector>
using namespace std;

// segment tree, fenwick tree, sieve of eratosthenes, range minimum query,
// segmented sieve, totient function

/*
inversion count using fenwick tree - solve negative numbe problem by using
relative ordering
*/

const int N = 1e5 + 2;
vector<int> bit;

int getSum(int i) {
  int sum = 0;
  while (i > 0) {
    sum += bit[i];
    i -= i & (-i);
  }
  return sum;
}

void update(int n, int i, int inc) {
  while (i <= n) {
    bit[i] += inc;
    i += i & (-i);
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a)
    cin >> i;
  vector<int> temp = a;
  sort(temp.begin(), temp.end());
  for (int i = 0; i < n; i++) {
    a[i] = lower_bound(temp.begin(), temp.end(), a[i]) - temp.begin() + 1;
  }

  bit = vector<int>(n + 1);
  int inv = 0;
  for (int i = n - 1; i >= 0; i--) {
    inv += getSum(a[i] - 1);
    update(n, a[i], 1);
  }
  cout << inv << endl;

  return 0;
}
