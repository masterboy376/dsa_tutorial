#include <iostream>
#include <vector>
using namespace std;

/*
boring factorials:
neha gives you a prime number p and an integer n close to p, and asks you to fing n! modulo p
constraints
1<p<=2*10^9
1<=n<=2*10^9
abs(n-p)<=1000
*/

/*
if n>=p:
(n!)%p == 0
else:
willson th.: (p-1)! === (p-1)(mod p) 
but we have to remove (n+1)*(n+2)*...*(p-1)
we will remove them by taking reverse modulo
fermat's th. : a^(p-2) === a^(-1)(mod p)

time complexity:
taking inverse of 'p-n' numbers in logarithmic time O((p-n)*logn)
*/
const int N = 1e5 + 2, MOD = 1e9 + 7;

int power(int x,int y,int p){
  int res = 1;
  x = x%p;
  while(y>0){
    if(y&1){
      res=(res*x)%p;
    }
    y=y>>1;
    x=(x*x)%p;
  }
return res;
}

int modInverse(int a, int p){
  return power(a,p-2,p);
}

int modfact(int n, int p){
  if(p<=n)
    return 0;
  int res = p-1;
  for(int i = n+1;i<p;i++){
    res = (res*modInverse(i,p))%p;
  }
  return res;
}

int main() {
  int n,p;cin>>n>>p;
  cout<<modfact(n,p)<<endl;

  return 0;
}
