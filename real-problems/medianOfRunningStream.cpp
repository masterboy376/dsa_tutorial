#include "bits/stdc++.h"
using namespace std;

priority_queue<int, vector<int>, greater<int>> pqmin;
priority_queue<int, vector<int>> pqmax;

void insert(int n){
  if(pqmin.size()==pqmax.size()){
    if(pqmax.size()==0){
      pqmax.push(n);
      return;
    }
    if(n<pqmax.top()){
      pqmax.push(n);
    }
    else{
      pqmin.push(n);
    }
  }
  else{
    if(pqmax.size()>pqmin.size()){
      if(n>=pqmax.top()){
        pqmin.push(n);
      }
      else{
        int temp = pqmax.top();
        pqmax.pop();
        pqmax.push(n);
        pqmin.push(temp);
        
      }
    }
    else{
      if(n<=pqmin.top()){
        pqmax.push(n);
      }
      else{
        int temp = pqmin.top();
        pqmin.pop();
        pqmin.push(n);
        pqmax.push(temp);
        
      }
    }
  }
}

double findMedian(){
  if(pqmax.size()==pqmin.size()){
    return (pqmax.top() + pqmin.top())/2.0;
  }
  else if(pqmax.size()>pqmin.size()){
    return pqmax.top();
  }
  else{
    return pqmin.top();
  }
}

int main() {
  insert(10);
  cout<<findMedian()<<endl;
  
  return 0;
}
