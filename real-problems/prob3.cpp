#include <iostream>
using namespace std;

// f1rst repeating element

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i =0; i<n; i++){
        cin>>a[i];
    } 

    const int N = 1e6 + 2;
    int IDX[N];
    for(int i = 0; i<N; i++){
        IDX[i] = -1;
    }

    int minIdx = INT8_MAX;

    for(int i = 0; i<n; i++){
        if(IDX[a[i]]!=-1){
            minIdx = min(minIdx, IDX[a[i]]);
        }
        else{
            IDX[a[i]] = i;
        }
    }

if(minIdx == INT8_MAX){
    cout<<-1<<endl;
}
else{
    cout<<minIdx<<endl;
}

    return 0;
}