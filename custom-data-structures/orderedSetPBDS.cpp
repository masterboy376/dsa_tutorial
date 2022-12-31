#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// segment tree, fenwick tree, sieve of eratosthenes, range minimum query,
// segmented sieve, totient function, MO's algo

/*
policy based: ordered set: implemented by red-black tree
*/
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
  int q;cin>>q;
  oset<int> s;
  while(q--){
    int c;cin>>c;
    if(c==1){
      int t;cin>>t;
      s.insert(t);
    }
    else if(c==2){
      int t;cin>>t;
      cout<<*s.find_by_order(t)<<endl;
    }
    else{
      int t;cin>>t;
      cout<<s.order_of_key(t)<<endl;
    }
  }

  return 0;
}
