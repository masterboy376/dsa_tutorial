#include <iostream>
using namespace std;

long long merge(int a[], int l, int mid, int r){
    long long inv=0;
    int i, j, k, b[l+r+1];
    i = l;
    j = mid + 1;
    k = l;
	
    while (i <= mid && j <= r)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];
            j++;
            k++;
            inv+=mid+1-i;
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        k++;
        i++;
    }
    while (j <= r)
    {
        b[k] = a[j];
        k++;
        j++;
    }
    for (int i = l; i <= r; i++)
    {
        a[i] = b[i];
    }
    return inv;
}

long long countInversion(int a[], int l, int r){
    long long inv = 0;
    if(l<r){
        int mid = (l+r)/2;
        inv+=countInversion(a,l, mid);
        inv+=countInversion(a, mid+1,r);
        inv+=merge(a,l,mid,r);
    }
    return inv;
}

int main()
{
    int a[8]={3,5,6,9,1,2,7,8};
    cout<<countInversion(a,0, 8-1)<<endl;

    return 0;
}