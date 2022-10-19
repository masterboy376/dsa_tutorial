#include <iostream>
using namespace std;

void quickSort(int a[], int n){
    int max = INT32_MIN;
    for(int i =0; i<n;i++){
        if(max<a[i]){
            max=a[i];
        }
    }
    max++;
    int countArr[max];
    for(int i=0;i<max;i++){
        countArr[i]=0;
    }
    for(int i =0; i<n;i++){
        countArr[a[i]]+=1;
    }

    for(int i=0;i<max;i++){
        cout<<countArr[i]<<" ";
    }
    cout<<endl;

    int j = 0;
    for (int i = 0 ;i<max; i++){
        while(countArr[i]>0){
            a[j]=i;
            j++;
            countArr[i]--;
        }
    }
}

int main()
{
    int a[7] = {4,3,6,2,5,1,4};
    quickSort(a,7);
    for(int i =0; i<sizeof(a)/sizeof(a[0]);i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}