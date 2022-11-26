#include <iostream>
#include <map>

using namespace std;


int main() {
 int a[8]={2,2,2,1,1,4,3,4};
  map<int,int> frequencyMap;

  for (int i = 0; i<8; i++){
    frequencyMap[a[i]]++;
  }

  map<int,int> :: iterator it;
  for(it=frequencyMap.begin() ; it!=frequencyMap.end(); it++){
    cout<<it->first<<" "<<it->second<<endl;
  }
  
  return 0;
}
