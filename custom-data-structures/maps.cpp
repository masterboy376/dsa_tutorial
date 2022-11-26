#include <iostream>
#include <queue>
#include <map>

using namespace std;

// hashing STL : maps and unordered maps

// maps (key-value pair) : implemented by Red-Black trees
// insertion : O(log n)
// accessing : O(log n)

// inorderd maps : implemented by Hah tables (basically array of buckets)
// insertion : O(1) avg
// accessing : O(1)

int main() {
  map<int,int> m;
  m[8]=2;
  cout<<m[8]<<endl;
  return 0;
}
