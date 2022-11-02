#include "bits/stdc++.h"
using namespace std;

int main()
{
    multiset<int> m;
    m.insert(1); // O(log n)
    m.insert(2);
    m.insert(2);
    m.insert(3);

    for (auto i : m)
    {
        cout << i << " ";
    }
    cout << endl;
    m.erase(2); // O(log n)
    for (auto i : m)
    {
        cout << i << " ";
    }
    cout << endl;

    m.insert(2);
    m.insert(2);

    for (auto i : m)
    {
        cout << i << " ";
    }
    cout << endl;
    m.erase(m.find(2));
    for (auto i : m)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << *m.lower_bound(1) << endl; // O(log n)
    cout << *m.lower_bound(2) << endl;
    cout << *m.lower_bound(3) << endl;
    cout << *m.upper_bound(1) << endl; // O(log n)
    cout << *m.upper_bound(2) << endl;
    cout << *m.upper_bound(3) << endl;

    return 0;
}