#include "bits/stdc++.h"
using namespace std;

int main()
{
    unordered_set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(2); // O(1) , worst case = O(n )
    s.insert(3);

    for(auto i:s){
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto i = s.begin(); i!=s.end(); i++){
        cout<<*i<<" ";
    }
    cout<<endl;
    for(auto i = s.begin(); i!=s.end(); i++){
        cout<<*i<<" ";
    }
    cout<<endl;

    cout<<s.size()<<endl;

    s.erase(2); // O(1) , worst case = O(n )
    s.erase(s.begin());
    for(auto i = s.begin(); i!=s.end(); i++){
        cout<<*i<<" ";
    }

    return 0;
}