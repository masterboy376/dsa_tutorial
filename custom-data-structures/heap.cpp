#include "bits/stdc++.h"
using namespace std;

int main() {
  // max heap : priority-queue<int, vector<int>>
  // max heap : priority-queue<int, vector<int>, greater<int>>

  // push : o(log n)
  // pop : o(log n)
  // top : o(1)
  // size : o(1)

  // max-heap
  priority_queue<int , vector<int>> max;
  max.push(2);
  max.push(3);
  max.push(1);
  cout<<max.top()<<endl;
  max.pop();
  cout<<max.top()<<endl;
  max.pop();
  cout<<max.top()<<endl;
  max.pop();

  // min-heap
  priority_queue<int , vector<int> , greater<int>> min;
  min.push(2);
  min.push(3);
  min.push(1);
  cout<<min.top()<<endl;
  min.pop();
  cout<<min.top()<<endl;
  min.pop();
  cout<<min.top()<<endl;
  max.pop();
}
