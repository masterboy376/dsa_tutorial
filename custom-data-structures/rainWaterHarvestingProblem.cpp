#include "bits/stdc++.h"
using namespace std;

int rail_water(vector<int> v){
    stack<int> s;
    int ans = 0;
    for(int i=0;i<v.size();i++){
        while(!s.empty() && v[s.top()]<v[i]){
            int cur = s.top();
            s.pop();
            if(s.empty()){
                break;
            }
            else{
                int diff = i-s.top() - 1;
                ans += (min(v[s.top()], v[i]) - v[cur]) * diff;
            }
        }
        s.push(i);
    }
    return ans;
}

int main()
{
    vector<int> v={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<rail_water(v)<<endl;

    return 0;
}