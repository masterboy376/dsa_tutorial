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
        IDX[i] = 0;
    }

    for(int i = 0; i<n; i++){
        if(a[i]>=0){
            IDX[a[i]] = 1;
        }
    }
    for(int i = 0; i<N; i++){
        cout<<IDX[i]<<endl;
        if(!IDX[i]){
            cout<<i<<endl;
            return 0;
        }
    }

    return 0;
}
