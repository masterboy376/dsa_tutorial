#include "bits/stdc++.h"
#include <iostream>
#include <vector>
using namespace std;

// segment tree, fenwick tree, sieve of eratosthenes, range minimum query,
// segmented sieve, totient function

/*
square root decomposition( MO's algo): find sum in range
*/

const int N = 1e5 + 2, MOD = 1e9 + 7;
int rootN;

struct Q{
int idx,l,r;
};
Q qs[N];

bool compare(Q q1, Q q2){
  if(q1.l/rootN == q2.l/rootN){
    return q1.r > q2.r;
  }
  return q1.l/rootN < q2.l/rootN;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }

  rootN = (int)sqrtl(n) + 1;
  
  int q;
  cin >> q;
  for(int i  = 0;i<q; i++){
    int l,r;cin>>l>>r;
    qs[i].l = l;
    qs[i].r = r;
    qs[i].idx = i;
  }
  sort(qs,qs+q, compare);

  vector<int> ans(q);
  int curr_l = 0,curr_r = -1,l,r;
  int curr_ans = 0;
  for(int i =0;i<q;i++){
    l = qs[i].l; r = qs[i].r;
    l--;r--;
    while(curr_r<r){
      curr_r++;
      curr_ans+= a[curr_r];
    }
    while(curr_l>l){
      curr_l--;
      curr_ans += a[curr_l];
    }
    while(curr_l<l){
      curr_ans-= a[curr_l];
      curr_l++;
    }
    while(curr_r>r){
      curr_ans -= a[curr_r];
      curr_r--;
    }
    ans[qs[i].idx] = curr_ans;
  }
  
  for (int i = 0; i < q; i++) {
    cout<<ans[i]<<endl;
  }

  return 0;
}
