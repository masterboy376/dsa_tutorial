#include <iostream>
using namespace std;

// check if the array is sorted or not

bool isSorted1(int *a, int n, int marker)
{
    if (marker < n-1)
    {
        if (a[marker] <= a[marker + 1])
        {
            marker++;
            return isSorted1(a, n, marker);
        }
        else{
            return false;
        }
    }
    else{
        return true;
    }
}
bool isSorted2(int a[], int n)
{
    if(n==1){
        return true;
    }
    bool restArr = isSorted2(a+1, n-1);
    return (a[0]<=a[1] && restArr);
}

int main()
{
    int a[]={1,2,3,4,5,6,6};
    cout<<isSorted1(a, 7, 0)<<endl;
    cout<<isSorted2(a, 7)<<endl;

    return 0;
}