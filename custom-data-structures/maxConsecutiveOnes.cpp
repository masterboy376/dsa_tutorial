#include "bits/stdc++.h"
using namespace std;

int main()
{
    vector<int> a = {1,1,1,1,1,1,0,1,1,0,0,0,1,0,1,0,0,0,0,1,1,1};
    int k =3;
    int zerocnt = 0, i=0, ans=0;
    for(int j = 0; j<a.size(); j++){
        if(a[j]==0){
            zerocnt++;
        }
        while (zerocnt>k)
        {
            if(a[i]==0){
                zerocnt--;
            }
            i++;
        }
        ans = max(ans, j-i+1);
    }
    cout<<ans<<endl;

    return 0;
}