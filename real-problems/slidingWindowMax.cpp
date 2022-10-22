#include <bits/stdc++.h>
using namespace std;

// review required

int main()
{
    int n, k; cin>>n>>k;
    vector<int> a(n);
    for(auto &i: a){
        cin>>i;
    }

    // approch 1 : O(nlog(n))
    multiset<int, greater<int>> s;
    vector<int> ans1;
    for (int i = 0; i<k; i++){
        s.insert(a[i]);
    }
    ans1.push_back(*s.begin());
    for(int i = k; i<n; i++){
        s.erase(s.lower_bound(a[i-k]));
        s.insert(a[i]);
        ans1.push_back(*s.begin());
    }
    for(auto i:ans1){
        cout<<i<<" ";
    }

    // approch 2 : O(n)
    deque<int> q;
    vector<int> ans;
    for(int i = 0;i<k; i++){
        while(!q.empty() and a[q.back()]<a[i]){
            q.pop_back();
        }
        q.push_back(i);
    }
    ans.push_back(a[q.front()]);
    for(int i = k ; i<n; i++){
        if(q.front()==i-k){
            q.pop_front();
        }
        while(!q.empty() and a[q.back()]<a[i]){
            q.pop_back();
        }
        q.push_back(i);
        ans.push_back(a[q.front()]);
    }
    for(auto i:ans){
        cout<<i<<" ";
    }

    return 0;
}