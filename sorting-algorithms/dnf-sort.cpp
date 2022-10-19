#include <iostream>
using namespace std;

void dnfsort(int a[], int n){
    int low=0, mid=0, high=n-1;
    int temp;
    while(mid!=high){
        if(a[mid]==0){
            temp = a[mid];
            a[mid]=a[low];
            a[low]=temp;
            low++;
            mid++;
        }
        else if(a[mid]==1){
            mid++;
        }
        else{
            temp = a[mid];
            a[mid]=a[high];
            a[high]=temp;
            high--;
        }
    }
}

int main()
{
    int a[10]={1,1,2,0,0,1,2,2,1,0};
    dnfsort(a,10);
    for(int i =0; i<10; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    return 0;
}