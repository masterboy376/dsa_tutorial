#include "bits/stdc++.h"
using namespace std;

int main()
{
    set<int, greater<int>> s;
    s.insert(1);
    s.insert(2);
    s.insert(2); // O(log n)
    s.insert(3);

    for(auto i:s){
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto i = s.begin(); i!=s.end(); i++){
        cout<<*i<<" ";
    }
    cout<<endl;
    for(auto i = s.rbegin(); i!=s.rend(); i++){
        cout<<*i<<" ";
    }
    cout<<endl;

    cout<<s.size()<<endl;

    cout<<*s.lower_bound(1)<<endl; // O(log n)
    cout<<*s.lower_bound(2)<<endl;
    cout<<*s.lower_bound(3)<<endl;
    cout<<*s.upper_bound(1)<<endl; // O(log n)
    cout<<*s.upper_bound(2)<<endl;
    cout<<*s.upper_bound(3)<<endl;

    s.erase(2); // O(log n)
    s.erase(s.begin());
    

    return 0;
}