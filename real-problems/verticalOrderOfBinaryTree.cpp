#include <iostream>
#include <map>
#include <vector>

using namespace std;

void getAllHorizontalDis(int s, int a[], int i, map<int, vector<int>> &hd, int dis) {
  if (i >= s) {
    return;
  }
  else{
  hd[dis].push_back(a[i]);
  getAllHorizontalDis(s, a, 2 * i + 1, hd, dis - 1);
  getAllHorizontalDis(s, a, 2 * i + 2, hd, dis + 1);
    return;
  }
}

int main() {
  int a[7] = {10, 7, 4, 3, 11, 14, 6};
  map<int, vector<int>> horizontalDis;

getAllHorizontalDis(7, a, 0, horizontalDis, 0);
  
  map<int, vector<int>>::iterator it;
  for (it = (horizontalDis).begin(); it != (horizontalDis).end(); it++) {
    for(int i=0; i<(it->second.size()); i++){
      cout<<it->second[i]<<" ";
    }
    cout << endl;
  }

  return 0;
}
