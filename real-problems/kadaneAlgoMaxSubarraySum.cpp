#include <iostream>
#include <vector>
using namespace std;

// maximum subarray sum - kadane's algo

const int MOD = 1e9 + 7, N = 1e3 + 2;


int main() {
  int n ;cin>>n;
  vector<int> a(n);
  for(int i = 0;i<n;i++){
    cin>>a[i];
  }

  int curr=0,maxTillNow=0;
  for(int i = 0; i<n; i++){
    curr+=a[i];
    maxTillNow = max(maxTillNow, curr);
    if(curr<0){
      curr=0;
    }
  }
  cout<<maxTillNow<<endl;
  
  return 0;
}
